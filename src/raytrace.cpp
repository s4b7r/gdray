/*
 * raytrace.color
 *
 *  Created on: 25.07.2014
 *      Author: sieb
 *
 * The raytracing routines.
 */

#include "raytrace.h"

/*
 * getPxDpVec()
 *
 * Calculate displacement vectors between the virtual screen's origin
 * and the upper and the right pixel.
 */
void getPxDisplaceVec(
		vector B, vector S, vector U,
		scalar w, scalar r,
		int nx, int ny,
		vector *dx, vector *dy ) {
	/*
	 *
	 * B = world origin -> camera point
	 * S = camera point -> viewport midpoint
	 * U = camera's "UP"-vector
	 * w = width of viewport in model-length-units
	 * r = aspect ratio = w / h
	 * nx = number of pixels in x direction
	 * ny = number of pixels in y direction
	 * dx = displacement vector of one pixel in x direction
	 * dy = displacement vector of one pixel in y direction
	 *
	 */


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

/*
 * getRayFromPx()
 *
 * Calculate ray from camera point through given screen pixel.
 */
ray getRayThroughPx(
		vector B, vector S,
		int nx, int ny,
		vector dx, vector dy,
		int x, int y ) {
	/*
	 * B = world origin -> camera point
	 * S = camera point -> viewport midpoint
	 * nx = number of pixels in x direction
	 * ny = number of pixels in y direction
	 * dx = displacement vector of one pixel in x direction
	 * dy = displacement vector of one pixel in y direction
	 * x = pixel's x coordinate
	 * y = pixel's y coordinate
	 *
	 */


	struct ray r;
	// r = ray from B through pixel

	r.point = B;
	r.direction = S+dx*(x-(scalar)nx/2+0.5)+dy*(y-(scalar)ny/2+0.5);

	return r;

}

/*
 * intersectRayTriangle()
 *
 * Calculate intersection between ray and given triangle.
 */
scalar intersectRayTriangle(
		ray r, triangle t,
		color *c ) {
	/*
	 * todo comments
	 */

	Matrix3d A;
	A.col(0) = r.direction * -1;
	A.col(1) = t.p[0] - t.p[2];
	A.col(2) = t.p[1] - t.p[2];
	Vector3d x = A.colPivHouseholderQr().solve(r.point - t.p[2]);

	if( x(0) < 1 || x(1) < 0 || x(1) > 1 || x(2) < 0 || x(2) > 1 ) {
		return 0;
	}

	*c = t.color;
	return x(0);

}


/*
 * intersectRayWorldCompl()
 *
 * Calculate intersections between ray and all world-objects.
 */
color intersectRayWorld(
		ray r, model m ) {
	/*
	 *
	 * r = ray for which intersections shall be checked
	 * m = the hole, wide world
	 *
	 */

	int i;
	scalar d, dmin = -1;
	color c, cmin;
	/*
	 * index, distance (camera - intersection) and color
	 * of currently checked triangle and the nearest, intersected one
	 */

	for( i = 0; i < m.triangles_count; i++ ) {

		if( (d=intersectRayTriangle(r, m.triangles[i], &c))>1 && (d < dmin || dmin==-1) ) {
			dmin = d;
			cmin = c;
		}

	}

	return cmin;

}

/*
 * tracePx()
 *
 * Perform raytracing for one pixel.
 */
color tracePx(
		vector B, vector S,
		int nx, int ny,
		vector dx, vector dy,
		model m,
		int x, int y ) {
	/*
	 *
	 * x / y = pixel's x and y coordinates
	 *
	 * the other variables got enough attention in other comments
	 *
	 */

	ray r;
	color color;

	r = getRayThroughPx(B, S, nx, ny, dx, dy, x, y);

	//printf("x y %d %d\n", x, y);
	//printf("r.p %f %f %f\n", r.point(0), r.point(1), r.point(2));
	//printf("r.d %f %f %f\n", r.direction(0), r.direction(1), r.direction(2));

	color = intersectRayWorld(r, m);

	return color;

}


/*
 * traceAll()
 *
 * Perform raytracing for all pixels.
 *
 * Could return some kind of picture one day.
 */
void traceAll(
		vector B, vector S,
		int nx, int ny,
		vector dx, vector dy,
		model m,
		BMP *pic ) {
	/*
	 * just check the other comments for this variables, please
	 */

	int x, y;
	// loop counters for pixel's x and y coordinates
	color c;

	for( y = 0; y < ny; y++ ) {
		for( x = 0; x < nx; x++ ) {

			c = tracePx(B, S, nx, ny, dx, dy, m, x, y);
			//printf("x:%d y:%d c:%f %f %f %f\n", x, y, c(0), c(1), c(2), c(3));
			(*pic)(x, y)->Red = c(0)*255;
			(*pic)(x, y)->Green = c(1)*255;
			(*pic)(x, y)->Blue = c(2)*255;
			(*pic)(x, y)->Alpha = c(3)*255;

		}
	}

}

