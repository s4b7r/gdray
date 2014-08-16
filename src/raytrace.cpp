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
		vector B, vector S, vector U,
		scalar w, scalar r,
		int nx, int ny,
		vector *dx, vector *dy ) {


	vector S_d = S.normalized();
	// S_d = direction of S

	vector dy_d = U.normalized();
	// dy_d = direction of dy
	vector dx_d = S_d.cross(dy_d);
	// dx_d = direction of dx

	scalar h = w / r;
	// h = height of viewport in model-length-units
	scalar dx_l = w / nx;
	// dx_l = length of dx
	scalar dy_l = h / ny;
	// dy_l = length of dy

	*dx = dx_d * dx_l;
	*dy = dy_d * dy_l;

}


ray getRayThroughPx(
		vector B, vector S,
		int nx, int ny,
		vector dx, vector dy,
		int x, int y ) {


	struct ray r;
	// r = ray from B through pixel

	r.point = B;
	r.direction = S+dx*(x-(scalar)nx/2+0.5)+dy*(y-(scalar)ny/2+0.5);

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
		vector B, vector S,
		int nx, int ny,
		vector dx, vector dy,
		model m,
		int x, int y ) {

	ray r;
	color color;

	r = getRayThroughPx(B, S, nx, ny, dx, dy, x, y);

	//printf("x y %d %d\n", x, y);
	//printf("r.p %f %f %f\n", r.point(0), r.point(1), r.point(2));
	//printf("r.d %f %f %f\n", r.direction(0), r.direction(1), r.direction(2));

	color = intersectRayWorld(r, m);

	return color;

}

void traceAll(
		vector B, vector S,
		int nx, int ny,
		vector dx, vector dy,
		model m,
		BMP *pic ) {

	int x, y;
	// loop counters for pixel's x and y coordinates
	color c;

	for( y = 0; y < ny; y++ ) {
		for( x = 0; x < nx; x++ ) {

			printf("Progress: %d\n", 100*(x+y*nx)/(ny*nx));
			c = tracePx(B, S, nx, ny, dx, dy, m, x, y);
			//printf("x:%d y:%d c:%f %f %f %f\n", x, y, c(0), c(1), c(2), c(3));
			(*pic)(x, y)->Red = c(0)*255;
			(*pic)(x, y)->Green = c(1)*255;
			(*pic)(x, y)->Blue = c(2)*255;
			(*pic)(x, y)->Alpha = c(3)*255;

		}
	}

}

