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
void getPxDisplaceVec( set *set );

/*
 * getRayFromPx()
 *
 * Calculate ray from camera point through given screen pixel.
 */
ray getRayThroughPx( set set, int x, int y );
/*
 * x = pixel's x coordinate
 * y = pixel's y coordinate
 *
 */

/*
 * intersectRayTriangle()
 *
 * Calculate intersection between ray and given triangle.
 */
double intersectRayTriangle( set set, ray r, Vector4d *c, int tIndex, double min_d );
/*
 * c = pointer to color vector which will hold the pixels color after return
 * tIndex = the triangles index in struct model m
 */

/*
 * intersectRayWorldCompl()
 *
 * Calculate intersections between ray and all world-objects.
 */
Vector4d intersectRayWorld( ray r, set set, double min_d );


/*
 * tracePx()
 *
 * Perform raytracing for one pixel.
 */
Vector4d tracePx( set set, int x, int y );
/*
 *
 * x / y = pixel's x and y coordinates
 *
 *
 */

/*
 * traceAll()
 *
 * Perform raytracing for all pixels.
 *
 * Could return some kind of picture one day.
 */
void traceAll( set set, BMP *pic );

#endif /* RAYTRACE_H_ */
