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

struct config {

	char LIGHTING_RND_NORMAL;

};
typedef struct config config;

struct set {

	config conf; // todo something to think about: does config fit into set?
	BMP pic;
	model m;
	Vector3d B, S, U, dx, dy;
	double w, r;
	int nx, ny;

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

};
typedef struct set set;

void loadModel( set *set, char *filename );
void saveModel( set set, char *filename );
void fileToHumanReadableFile( char *filename );
void fillNormals( model *m );
void initConfig( config *conf );

#endif /* MODEL_H_ */
