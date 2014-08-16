/*
 * models.cpp
 *
 *  Created on: 16.08.2014
 *      Author: sieb
 */

void init_test1( model *m, vector *B, vector *S, vector *U,
		scalar *w, scalar *r, int *nx, int *ny ) {

	m->lightsources_count = 1;
	m->lightsources = (lightsource*)malloc(sizeof(lightsource)*m->lightsources_count);

	m->lightsources[0].p(X) = 0;
	m->lightsources[0].p(Y) = 0;
	m->lightsources[0].p(Z) = 2;
	m->lightsources[0].color(0) = 1;
	m->lightsources[0].color(1) = 1;
	m->lightsources[0].color(2) = 1;

	m->triangles_count = 2;
	m->triangles = (triangle*)malloc(sizeof(triangle)*m->triangles_count);

	m->triangles[0].p[0](0) = 3;
	m->triangles[0].p[0](1) = 0;
	m->triangles[0].p[0](2) = 2;
	m->triangles[0].p[1](0) = 3;
	m->triangles[0].p[1](1) = 2;
	m->triangles[0].p[1](2) = 1;
	m->triangles[0].p[2](0) = 3;
	m->triangles[0].p[2](1) = 0;
	m->triangles[0].p[2](2) = 0;
	m->triangles[0].color(0) = 0;
	m->triangles[0].color(1) = 1;
	m->triangles[0].color(2) = 0;
	m->triangles[0].color(3) = 1;

	m->triangles[1].p[0](0) = 6;
	m->triangles[1].p[0](1) = 10;
	m->triangles[1].p[0](2) = 10;
	m->triangles[1].p[1](0) = 6;
	m->triangles[1].p[1](1) = 10;
	m->triangles[1].p[1](2) = -10;
	m->triangles[1].p[2](0) = 6;
	m->triangles[1].p[2](1) = -10;
	m->triangles[1].p[2](2) = 0;
	m->triangles[1].color(0) = 1;
	m->triangles[1].color(1) = 1;
	m->triangles[1].color(2) = 0;
	m->triangles[1].color(3) = 1;



	(*B)(0) = 1;
	(*B)(1) = 0;
	(*B)(2) = 0;
	(*S)(0) = 1;
	(*S)(1) = 0;
	(*S)(2) = 0;
	(*U)(0) = 0;
	(*U)(1) = 1;
	(*U)(2) = 0;
	*nx = 256;
	*ny = 192;
	*w = 10;
	*r = (double)*nx / (double)*ny;

}

void init_test2( model *m, vector *B, vector *S, vector *U,
		scalar *w, scalar *r, int *nx, int *ny ) {

	m->lightsources_count = 1;
	m->lightsources = (lightsource*)malloc(sizeof(lightsource)*m->lightsources_count);

	m->lightsources[0].p(X) = 0;
	m->lightsources[0].p(Y) = 0;
	m->lightsources[0].p(Z) = 2;
	m->lightsources[0].color(0) = 1;
	m->lightsources[0].color(1) = 1;
	m->lightsources[0].color(2) = 1;

	m->triangles_count = 4;
	m->triangles = (triangle*)malloc(sizeof(triangle)*m->triangles_count);

	m->triangles[0].p[0](0) = 6;
	m->triangles[0].p[0](1) = -1;
	m->triangles[0].p[0](2) = -3;
	m->triangles[0].p[1](0) = 2;
	m->triangles[0].p[1](1) = 1;
	m->triangles[0].p[1](2) = -4;
	m->triangles[0].p[2](0) = 1;
	m->triangles[0].p[2](1) = -1;
	m->triangles[0].p[2](2) = -5;
	m->triangles[0].color(0) = 1;
	m->triangles[0].color(1) = 0;
	m->triangles[0].color(2) = 0;
	m->triangles[0].color(3) = 1;

	m->triangles[1].p[0](0) = 3;
	m->triangles[1].p[0](1) = 0;
	m->triangles[1].p[0](2) = 2;
	m->triangles[1].p[1](0) = 3;
	m->triangles[1].p[1](1) = 2;
	m->triangles[1].p[1](2) = 1;
	m->triangles[1].p[2](0) = 3;
	m->triangles[1].p[2](1) = 0;
	m->triangles[1].p[2](2) = 0;
	m->triangles[1].color(0) = 0;
	m->triangles[1].color(1) = 1;
	m->triangles[1].color(2) = 0;
	m->triangles[1].color(3) = 1;

	m->triangles[2].p[0](0) = 3;
	m->triangles[2].p[0](1) = 4;
	m->triangles[2].p[0](2) = -3;
	m->triangles[2].p[1](0) = 3;
	m->triangles[2].p[1](1) = 6;
	m->triangles[2].p[1](2) = -4;
	m->triangles[2].p[2](0) = 3;
	m->triangles[2].p[2](1) = 4;
	m->triangles[2].p[2](2) = -5;
	m->triangles[2].color(0) = 0;
	m->triangles[2].color(1) = 1;
	m->triangles[2].color(2) = 1;
	m->triangles[2].color(3) = 1;

	m->triangles[3].p[0](0) = 6;
	m->triangles[3].p[0](1) = 10;
	m->triangles[3].p[0](2) = 10;
	m->triangles[3].p[1](0) = 6;
	m->triangles[3].p[1](1) = 10;
	m->triangles[3].p[1](2) = -10;
	m->triangles[3].p[2](0) = 6;
	m->triangles[3].p[2](1) = -10;
	m->triangles[3].p[2](2) = 0;
	m->triangles[3].color(0) = 1;
	m->triangles[3].color(1) = 1;
	m->triangles[3].color(2) = 0;
	m->triangles[3].color(3) = 1;



	(*B)(0) = 1;
	(*B)(1) = 0;
	(*B)(2) = 0;
	(*S)(0) = 1;
	(*S)(1) = 0;
	(*S)(2) = 0;
	(*U)(0) = 0;
	(*U)(1) = 1;
	(*U)(2) = 0;
	*nx = 640;
	*ny = 480;
	*w = 10;
	*r = (double)*nx / (double)*ny;

}


