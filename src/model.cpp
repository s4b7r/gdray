/*
 * model.c
 *
 *  Created on: 25.07.2014
 *      Author: sieb
 *
 * World, objects, models, triangles ...
 */

#include <Eigen/Dense>
using Eigen::Vector3d;
using Eigen::Vector4d;

struct triangle {

	Vector4d color;
	Vector3d normal;
	Vector3d p[3];

};
typedef struct triangle triangle;

struct model {

	triangle *triangles;

	struct lightsource {

		Vector4d color;
		Vector3d p;

	} *lightsources;

	int triangles_count;
	int lightsources_count;

};
typedef struct model model;
