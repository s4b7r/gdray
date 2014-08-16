/*
 * raytrace.color
 *
 *  Created on: 25.07.2014
 *      Author: sieb
 *
 * The raytracing routines.
 */

#include "head.h"

void getPxDisplaceVec(
		set *set ) {


	vector S_d = set->S.normalized();
	// S_d = direction of S

	vector dy_d = set->U.normalized();
	// dy_d = direction of dy
	vector dx_d = S_d.cross(dy_d);
	// dx_d = direction of dx

	scalar h = set->w / set->r;
	// h = height of viewport in model-length-units
	scalar dx_l = set->w / set->nx;
	// dx_l = length of dx
	scalar dy_l = h / set->ny;
	// dy_l = length of dy

	set->dx = dx_d * dx_l;
	set->dy = dy_d * dy_l;

}


ray getRayThroughPx(
		set set,
		int x, int y ) {


	struct ray r;
	// r = ray from B through pixel

	r.point = set.B;
	r.direction = set.S+set.dx*(x-(scalar)set.nx/2+0.5)+set.dy*(y-(scalar)set.ny/2+0.5);

	return r;

}

scalar intersectRayTriangle(
		model m,
		ray r, triangle t,
		color *c ,
		int tIndex) {

	Matrix3d A;
	A.col(0) = r.direction * -1;
	A.col(1) = t.p[0] - t.p[2];
	A.col(2) = t.p[1] - t.p[2];
	Vector3d x = A.colPivHouseholderQr().solve(r.point - t.p[2]);

	if( x(0) < 1 || x(1) < 0 || x(1) > 1 || x(2) < 0 || x(2) > 1 || x(1)+x(2) > 1 ) {
		return 0;
	}

	vector I = r.point + r.direction * x(0);

	//*c = t.color;
	*c = getColor((Vector3d)I, r, t.color, t.normal, m, tIndex);
	return x(0);

}

color intersectRayWorld(
		ray r, model m ) {

	int i;
	scalar d, dmin = -1;
	color c, cmin;
	/*
	 * index, distance (camera - intersection) and color
	 * of currently checked triangle and the nearest, intersected one
	 */

	for( i = 0; i < m.triangles_count; i++ ) {

		if( (d=intersectRayTriangle(m, r, m.triangles[i], &c, i))>1 && (d < dmin || dmin==-1) ) {
			dmin = d;
			cmin = c;
		}

	}

	return cmin;

}

color tracePx(
		set set,
		int x, int y ) {

	ray r;
	color color;

	r = getRayThroughPx(set, x, y);

	//printf("x y %d %d\n", x, y);
	//printf("r.p %f %f %f\n", r.point(0), r.point(1), r.point(2));
	//printf("r.d %f %f %f\n", r.direction(0), r.direction(1), r.direction(2));

	color = intersectRayWorld(r, set.m);

	return color;

}

void traceAll(
		set set,
		BMP *pic ) {

	int x, y;
	// loop counters for pixel's x and y coordinates
	color c;

	for( y = 0; y < set.ny; y++ ) {
		for( x = 0; x < set.nx; x++ ) {

			printf("Progress: %d\n", 100*(x+y*set.nx)/(set.ny * set.nx));
			c = tracePx(set, x, y);
			//printf("x:%d y:%d c:%f %f %f %f\n", x, y, c(0), c(1), c(2), c(3));
			(*pic)(x, y)->Red = c(0)*255;
			(*pic)(x, y)->Green = c(1)*255;
			(*pic)(x, y)->Blue = c(2)*255;
			(*pic)(x, y)->Alpha = c(3)*255;

		}
	}

}

