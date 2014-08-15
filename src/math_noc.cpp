/*
 * math_noc.c
 *
 *  Created on: 25.07.2014
 *      Author: sieb
 *
 * Everything for vector mathematics and so on.
 * "noc" for "not C", cause math.c may be in standard C libs.
 */

// Use external library: Eigen version 3

#include <Eigen/Dense>
using Eigen::Vector3d;

struct ray {

	Vector3d point;
	Vector3d direction;

};
typedef struct ray ray;
