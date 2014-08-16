/*
 * testing.cpp
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

void test_start() {

	BMP pic1, pic2;
	model m1, m2;
	vector B, S, U, dx, dy;
	scalar w, r;
	int nx, ny;
	int x, y;

	init_test1(&m1, &B, &S, &U, &w, &r, &nx, &ny);
	saveModel(m1, "testoutput/model1.xml");
	loadModel(&m2, "testoutput/model1.xml");
	saveModel(m2, "testoutput/model1_2.xml");

	fillNormals(&m1);
	fillNormals(&m2);

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

	pic1.SetSize(nx, ny);
	pic1.SetBitDepth(32);

	traceAll(B, S, nx, ny, dx, dy, m1, &pic1);

	for( y = 0; y < ny; y++ ) {
		pic1(nx/2,y)->Alpha=255;
		pic1(nx/2,y)->Blue=255;
		pic1(nx/2,y)->Green=255;
		pic1(nx/2,y)->Red=255;
	}
	for( x = 0; x < nx; x++ ) {
		pic1(x,ny/2)->Alpha=255;
		pic1(x,ny/2)->Blue=255;
		pic1(x,ny/2)->Green=255;
		pic1(x,ny/2)->Red=255;
	}

	pic1.WriteToFile("testoutput/pic3_1.bmp");
	printf("Done\n");

	pic2.SetSize(nx, ny);
	pic2.SetBitDepth(32);

	traceAll(B, S, nx, ny, dx, dy, m2, &pic2);

	for( y = 0; y < ny; y++ ) {
		pic2(nx/2,y)->Alpha=255;
		pic2(nx/2,y)->Blue=255;
		pic2(nx/2,y)->Green=255;
		pic2(nx/2,y)->Red=255;
	}
	for( x = 0; x < nx; x++ ) {
		pic2(x,ny/2)->Alpha=255;
		pic2(x,ny/2)->Blue=255;
		pic2(x,ny/2)->Green=255;
		pic2(x,ny/2)->Red=255;
	}

	pic2.WriteToFile("testoutput/pic3_2.bmp");
	printf("Done\n");

}
