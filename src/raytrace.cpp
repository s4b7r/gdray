/*
 * raytrace.color
 *
 *  Created on: 25.07.2014
 *      Author: sieb
 *
 * The raytracing routines.
 */

#include "head.h"

void getPxDisplaceVec( set *set ) {


	Vector3d S_d = set->S.normalized();
	// S_d = direction of S

	Vector3d dy_d = set->U.normalized();
	// dy_d = direction of dy
	Vector3d dx_d = S_d.cross(dy_d);
	// dx_d = direction of dx

	double h = set->w / set->r;
	// h = height of viewport in model-length-units
	double dx_l = set->w / set->nx;
	// dx_l = length of dx
	double dy_l = h / set->ny;
	// dy_l = length of dy

	set->dx = dx_d * dx_l;
	set->dy = dy_d * dy_l;

}


ray getRayThroughPx( set set, int x, int y ) {


	struct ray r;
	// r = ray from B through pixel

	r.point = set.B;
	r.direction = set.S+set.dx*(x-(double)set.nx/2+0.5)+set.dy*(y-(double)set.ny/2+0.5);

	return r;

}

double intersectRayTriangle( set set, ray r, Vector4d *c, int tIndex, double min_d) {

	int i;
	triangle t = set.m.triangles[tIndex];
	Vector4d mirrorC;

	// Build and solve linear equationsystem
	// to calculate the intersection
	Matrix3d A;
	A.col(0) = r.direction * -1;
	A.col(1) = t.p[0] - t.p[2];
	A.col(2) = t.p[1] - t.p[2];
	Vector3d x = A.colPivHouseholderQr().solve(r.point - t.p[2]);

	// Check for the equation's conditions
	if( x(0) <= min_d || x(1) < 0 || x(1) > 1 || x(2) < 0 || x(2) > 1 || x(1)+x(2) > 1 ) {
		return 0;
	}

	// Calculate point of intersection
	Vector3d I = r.point + r.direction * x(0);

	if( set.conf.reflection && t.reflection > 0.0 ) {
		ray reflected;
		reflected.point = I;
		reflected.direction = -2 * t.normal.dot(r.direction.normalized()) * t.normal + r.direction.normalized();
		*c = intersectRayWorld(reflected, set, 0.001);
		mirrorC = getColor(I, r, set.m, tIndex, set.conf);
		for(i=0;i<4;i++){
			(*c)(i) = (*c)(i)*t.reflection + mirrorC(i)*(1-t.reflection);
		}
	} else if( set.conf.lighting ){
		*c = getColor(I, r, set.m, tIndex, set.conf);
	} else {
		*c = t.color;
	}

	return x(0);

}

Vector4d intersectRayWorld( ray r, set set, double min_d ) {

	int i;
	double d, dmin = -1;
	Vector4d c, cmin;
	/*
	 * index, distance (camera - intersection) and color
	 * of currently checked triangle and the nearest, intersected one
	 */

	cmin(0) = 0;
	cmin(1) = 0;
	cmin(2) = 0;
	cmin(3) = 0;

	// Check all triangles for intersection and choose the nearest one
	for( i = 0; i < set.m.triangles_count; i++ ) {
		d=intersectRayTriangle(set, r, &c, i, min_d);
		if( d > min_d && (d < dmin || dmin==-1) ) {
			dmin = d;
			cmin = c;
		}

	}

	return cmin;

}

Vector4d tracePx( set set, int x, int y ) {

	ray r;
	Vector4d color;

	r = getRayThroughPx(set, x, y);
	color = intersectRayWorld(r, set, 1.0);

	return color;

}

void traceAll( set set, BMP *pic ) {

	int x, y;
	// loop counters for pixel's x and y coordinates
	Vector4d c;

	//printf("reflection: %d\n", set.conf.reflection);

	// Trace for all pixels
	for( y = 0; y < set.ny; y++ ) {
		for( x = 0; x < set.nx; x++ ) {

			if( !set.conf.no_progress ) {
				printf("Progress: %d\033[12D", 100*(x+y*set.nx)/(set.ny * set.nx));
			}
			c = tracePx(set, x, y);
			(*pic)(x, set.ny-y-1)->Red = c(0)*255;
			(*pic)(x, set.ny-y-1)->Green = c(1)*255;
			(*pic)(x, set.ny-y-1)->Blue = c(2)*255;
			(*pic)(x, set.ny-y-1)->Alpha = c(3)*255;

		}
	}

}

