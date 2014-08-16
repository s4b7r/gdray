/*
 * model.h
 *
 *  Created on: 15.08.2014
 *      Author: sieb
 */

#ifndef MODEL_H_
#define MODEL_H_

struct triangle {

	Vector4d color;
	Vector3d normal;
	Vector3d p[3];

};
typedef struct triangle triangle;

struct lightsource {

		Vector4d color;
		Vector3d p;
};
typedef struct lightsource lightsource;

struct model {

	triangle *triangles;
	lightsource *lightsources;

	int triangles_count;
	int lightsources_count;

};
typedef struct model model;

void loadModel( model *m, char *filename );
void saveModel( model m, char *filename );
void fileToHumanReadableFile( char *filename );

#endif /* MODEL_H_ */
