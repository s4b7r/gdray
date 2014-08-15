/*
 * main.cpp
 *
 *  Created on: 14.08.2014
 *      Author: sieb
 */


#include "raytrace.h"


void init_test( model *m, vector *B, vector *S, vector *U,
		scalar *w, scalar *r, int *nx, int *ny ) {

	m->triangles_count = 2;
	m->triangles = (triangle*)malloc(sizeof(triangle)*m->triangles_count);

	m->triangles[0].p[0](0) = 3;
	m->triangles[0].p[0](1) = -1;
	m->triangles[0].p[0](2) = -3;
	m->triangles[0].p[1](0) = 3;
	m->triangles[0].p[1](1) = 1;
	m->triangles[0].p[1](2) = -4;
	m->triangles[0].p[2](0) = 3;
	m->triangles[0].p[2](1) = -1;
	m->triangles[0].p[2](2) = -5;
	m->triangles[0].color(0) = 1;
	m->triangles[0].color(1) = 0;
	m->triangles[0].color(2) = 0;
	m->triangles[0].color(3) = 1;
	m->triangles[0].p[0](0) = 3;

	m->triangles[0].p[0](0) = 3;
	m->triangles[1].p[0](1) = -1;
	m->triangles[1].p[0](2) = 5;
	m->triangles[1].p[1](0) = 3;
	m->triangles[1].p[1](1) = 1;
	m->triangles[1].p[1](2) = 4;
	m->triangles[1].p[2](0) = 3;
	m->triangles[1].p[2](1) = -1;
	m->triangles[1].p[2](2) = 3;
	m->triangles[1].color(0) = 0;
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
	*nx = 640;
	*ny = 480;
	*w = 10;
	*r = (double)*nx / (double)*ny;

}

int main(int argc, char **argv) {

	BMP pic;
	model m;
	vector B, S, U, dx, dy;
	scalar w, r;
	int nx, ny;
	int x, y;

	init_test(&m, &B, &S, &U, &w, &r, &nx, &ny);


	//printf("t_c %d\n", m.triangles_count);
	//printf("t0p0 %f %f %f\n", m.triangles[0].p[0](0), m.triangles[0].p[0](1), m.triangles[0].p[0](2));
	//printf("t0p1 %f %f %f\n", m.triangles[0].p[1](0), m.triangles[0].p[1](1), m.triangles[0].p[1](2));
	//printf("t0p2 %f %f %f\n", m.triangles[0].p[2](0), m.triangles[0].p[2](1), m.triangles[0].p[2](2));
	//printf("t0c %f %f %f %f\n", m.triangles[0].color(0), m.triangles[0].color(1), m.triangles[0].color(2), m.triangles[0].color(3));
	//printf("B %f %f %f\n", B(0), B(1), B(2));
	//printf("S %f %f %f\n", S(0), S(1), S(2));
	//printf("U %f %f %f\n", U(0), U(1), U(2));
	//printf("w %f r %f nxy %d %d\n", w, r, nx, ny);


	getPxDisplaceVec(B, S, U, w, r, nx, ny, &dx, &dy);

	//printf("dx %f %f %f\n", dx(0), dx(1), dx(2));
	//printf("dy %f %f %f\n", dy(0), dy(1), dy(2));

	pic.SetSize(nx, ny);
	pic.SetBitDepth(32);

	traceAll(B, S, nx, ny, dx, dy, m, &pic);

	for( y = 0; y < ny; y++ ) {
		pic(nx/2,y)->Alpha=255;
		pic(nx/2,y)->Blue=255;
		pic(nx/2,y)->Green=255;
		pic(nx/2,y)->Red=255;
	}
	for( x = 0; x < nx; x++ ) {
			pic(x,ny/2)->Alpha=255;
			pic(x,ny/2)->Blue=255;
			pic(x,ny/2)->Green=255;
			pic(x,ny/2)->Red=255;
		}

	pic.WriteToFile("testoutput.bmp");
	printf("Done\n");

	return 0;

}



