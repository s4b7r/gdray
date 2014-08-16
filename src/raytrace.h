/*
 * raytrace.h
 *
 *  Created on: 15.08.2014
 *      Author: sieb
 */

#ifndef RAYTRACE_H_
#define RAYTRACE_H_

#include <Eigen/Dense>

typedef Vector4d color;
typedef Vector3d vector;
typedef double scalar;

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
		vector *dx, vector *dy );
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

/*
 * getRayFromPx()
 *
 * Calculate ray from camera point through given screen pixel.
 */
ray getRayThroughPx(
		vector B, vector S,
		int nx, int ny,
		vector dx, vector dy,
		int x, int y );
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

/*
 * intersectRayTriangle()
 *
 * Calculate intersection between ray and given triangle.
 */
scalar intersectRayTriangle(
		model m,
		ray r, triangle t,
		color *c ,
		int tIndex);
/*
 * todo comments
 */

/*
 * intersectRayWorldCompl()
 *
 * Calculate intersections between ray and all world-objects.
 */
color intersectRayWorld(
		ray r, model m );
/*
 *
 * r = ray for which intersections shall be checked
 * m = the hole, wide world
 *
 */

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
		int x, int y );
/*
 *
 * x / y = pixel's x and y coordinates
 *
 * the other variables got enough attention in other comments
 *
 */

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
		BMP *pic );
/*
 * just check the other comments for this variables, please
 */


#endif /* RAYTRACE_H_ */
