/*
 * model.c
 *
 *  Created on: 25.07.2014
 *      Author: sieb
 *
 * World, objects, models, triangles ...
 */

struct model {

	struct triangle {

		Vector4d color;
		Vector3d normal;
		Vector3d p[3];

	} *triangles;

	struct lightsource {

		Vector4d color;
		Vector3d p;

	} *lightsources;

	int triangles_count;
	int lightsources_count;

};
