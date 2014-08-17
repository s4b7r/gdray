/*
 * raytrace.h
 *
 *  Created on: 15.08.2014
 *      Author: sieb
 */

#ifndef RAYTRACE_H_
#define RAYTRACE_H_

#include <Eigen/Dense>

/*
 * getPxDpVec()
 *
 * Calculate displacement vectors between the virtual screen's origin
 * and the upper and the right pixel.
 */
void getPxDisplaceVec(
		set *set );
/*
 *
 * B = world origin -> camera point
 * S = camera point -> viewport midpoint
 * U = camera's "UP"-Vector3d
 * w = width of viewport in model-length-units
 * r = aspect ratio = w / h
 * nx = number of pixels in x direction
 * ny = number of pixels in y direction
 * dx = displacement Vector3d of one pixel in x direction
 * dy = displacement Vector3d of one pixel in y direction
 *
 */

/*
 * getRayFromPx()
 *
 * Calculate ray from camera point through given screen pixel.
 */
ray getRayThroughPx(
		Vector3d B, Vector3d S,
		int nx, int ny,
		Vector3d dx, Vector3d dy,
		int x, int y );
/*
 * B = world origin -> camera point
 * S = camera point -> viewport midpoint
 * nx = number of pixels in x direction
 * ny = number of pixels in y direction
 * dx = displacement Vector3d of one pixel in x direction
 * dy = displacement Vector3d of one pixel in y direction
 * x = pixel's x coordinate
 * y = pixel's y coordinate
 *
 */

/*
 * intersectRayTriangle()
 *
 * Calculate intersection between ray and given triangle.
 */
double intersectRayTriangle(
		model m,
		ray r,
		Vector4d *c ,
		int tIndex);
/*
 * todo comments
 */

/*
 * intersectRayWorldCompl()
 *
 * Calculate intersections between ray and all world-objects.
 */
Vector4d intersectRayWorld(
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
Vector4d tracePx(
		set set,
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
		set set,
		BMP *pic );
/*
 * just check the other comments for this variables, please
 */


#endif /* RAYTRACE_H_ */
