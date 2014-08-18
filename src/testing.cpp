/*
 * testing.cpp
 *
 *  Created on: 16.08.2014
 *      Author: sieb
 */

#include "head.h"

/*
 * NOTICE:
 *
 * All these strange referencing/dereferencing-combinations are the result
 * of multiple search-and-replaces.
 * Not going to beautify this, because this routines are for developer's
 * testing purposes only.
 *
 */


void init_test1( set *set ) {

	(&(set->m))->lightsources_count = 1;
	(&(set->m))->lightsources = (lightsource*)malloc(sizeof(lightsource)*(&(set->m))->lightsources_count);

	(&(set->m))->lightsources[0].p(X) = 0;
	(&(set->m))->lightsources[0].p(Y) = 0;
	(&(set->m))->lightsources[0].p(Z) = 2;
	(&(set->m))->lightsources[0].color(0) = 1;
	(&(set->m))->lightsources[0].color(1) = 1;
	(&(set->m))->lightsources[0].color(2) = 1;

	(&(set->m))->triangles_count = 2;
	(&(set->m))->triangles = (triangle*)malloc(sizeof(triangle)*(&(set->m))->triangles_count);

	(&(set->m))->triangles[0].p[0](0) = 3;
	(&(set->m))->triangles[0].p[0](1) = 0;
	(&(set->m))->triangles[0].p[0](2) = 2;
	(&(set->m))->triangles[0].p[1](0) = 3;
	(&(set->m))->triangles[0].p[1](1) = 2;
	(&(set->m))->triangles[0].p[1](2) = 1;
	(&(set->m))->triangles[0].p[2](0) = 3;
	(&(set->m))->triangles[0].p[2](1) = 0;
	(&(set->m))->triangles[0].p[2](2) = 0;
	(&(set->m))->triangles[0].color(0) = 0;
	(&(set->m))->triangles[0].color(1) = 1;
	(&(set->m))->triangles[0].color(2) = 0;
	(&(set->m))->triangles[0].color(3) = 1;

	(&(set->m))->triangles[1].p[0](0) = 6;
	(&(set->m))->triangles[1].p[0](1) = 10;
	(&(set->m))->triangles[1].p[0](2) = 10;
	(&(set->m))->triangles[1].p[1](0) = 6;
	(&(set->m))->triangles[1].p[1](1) = 10;
	(&(set->m))->triangles[1].p[1](2) = -10;
	(&(set->m))->triangles[1].p[2](0) = 6;
	(&(set->m))->triangles[1].p[2](1) = -10;
	(&(set->m))->triangles[1].p[2](2) = 0;
	(&(set->m))->triangles[1].color(0) = 1;
	(&(set->m))->triangles[1].color(1) = 1;
	(&(set->m))->triangles[1].color(2) = 0;
	(&(set->m))->triangles[1].color(3) = 1;



	(*(&(set->B)))(0) = 1;
	(*(&(set->B)))(1) = 0;
	(*(&(set->B)))(2) = 0;
	(*(&(set->S)))(0) = 1;
	(*(&(set->S)))(1) = 0;
	(*(&(set->S)))(2) = 0;
	(*(&(set->U)))(0) = 0;
	(*(&(set->U)))(1) = 1;
	(*(&(set->U)))(2) = 0;
	*(&(set->nx)) = 256;
	*(&(set->ny)) = 192;
	*(&(set->w)) = 10;
	*(&(set->r)) = (double)*(&(set->nx)) / (double)*(&(set->ny));

}

void init_test2( set *set ) {

	(&(set->m))->lightsources_count = 1;
	(&(set->m))->lightsources = (lightsource*) malloc(
			sizeof(lightsource) * (&(set->m))->lightsources_count);

	(&(set->m))->lightsources[0].p(X) = 0;
	(&(set->m))->lightsources[0].p(Y) = 0;
	(&(set->m))->lightsources[0].p(Z) = 2;
	(&(set->m))->lightsources[0].color(0) = 1;
	(&(set->m))->lightsources[0].color(1) = 1;
	(&(set->m))->lightsources[0].color(2) = 1;

	(&(set->m))->triangles_count = 4;
	(&(set->m))->triangles = (triangle*) malloc(sizeof(triangle) * (&(set->m))->triangles_count);

	(&(set->m))->triangles[0].p[0](0) = 6;
	(&(set->m))->triangles[0].p[0](1) = -1;
	(&(set->m))->triangles[0].p[0](2) = -3;
	(&(set->m))->triangles[0].p[1](0) = 2;
	(&(set->m))->triangles[0].p[1](1) = 1;
	(&(set->m))->triangles[0].p[1](2) = -4;
	(&(set->m))->triangles[0].p[2](0) = 1;
	(&(set->m))->triangles[0].p[2](1) = -1;
	(&(set->m))->triangles[0].p[2](2) = -5;
	(&(set->m))->triangles[0].color(0) = 1;
	(&(set->m))->triangles[0].color(1) = 0;
	(&(set->m))->triangles[0].color(2) = 0;
	(&(set->m))->triangles[0].color(3) = 1;

	(&(set->m))->triangles[1].p[0](0) = 3;
	(&(set->m))->triangles[1].p[0](1) = 0;
	(&(set->m))->triangles[1].p[0](2) = 2;
	(&(set->m))->triangles[1].p[1](0) = 3;
	(&(set->m))->triangles[1].p[1](1) = 2;
	(&(set->m))->triangles[1].p[1](2) = 1;
	(&(set->m))->triangles[1].p[2](0) = 3;
	(&(set->m))->triangles[1].p[2](1) = 0;
	(&(set->m))->triangles[1].p[2](2) = 0;
	(&(set->m))->triangles[1].color(0) = 0;
	(&(set->m))->triangles[1].color(1) = 1;
	(&(set->m))->triangles[1].color(2) = 0;
	(&(set->m))->triangles[1].color(3) = 1;

	(&(set->m))->triangles[2].p[0](0) = 3;
	(&(set->m))->triangles[2].p[0](1) = 4;
	(&(set->m))->triangles[2].p[0](2) = -3;
	(&(set->m))->triangles[2].p[1](0) = 3;
	(&(set->m))->triangles[2].p[1](1) = 6;
	(&(set->m))->triangles[2].p[1](2) = -4;
	(&(set->m))->triangles[2].p[2](0) = 3;
	(&(set->m))->triangles[2].p[2](1) = 4;
	(&(set->m))->triangles[2].p[2](2) = -5;
	(&(set->m))->triangles[2].color(0) = 0;
	(&(set->m))->triangles[2].color(1) = 1;
	(&(set->m))->triangles[2].color(2) = 1;
	(&(set->m))->triangles[2].color(3) = 1;

	(&(set->m))->triangles[3].p[0](0) = 6;
	(&(set->m))->triangles[3].p[0](1) = 10;
	(&(set->m))->triangles[3].p[0](2) = 10;
	(&(set->m))->triangles[3].p[1](0) = 6;
	(&(set->m))->triangles[3].p[1](1) = 10;
	(&(set->m))->triangles[3].p[1](2) = -10;
	(&(set->m))->triangles[3].p[2](0) = 6;
	(&(set->m))->triangles[3].p[2](1) = -10;
	(&(set->m))->triangles[3].p[2](2) = 0;
	(&(set->m))->triangles[3].color(0) = 1;
	(&(set->m))->triangles[3].color(1) = 1;
	(&(set->m))->triangles[3].color(2) = 0;
	(&(set->m))->triangles[3].color(3) = 1;

	(*(&(set->B)))(0) = 1;
	(*(&(set->B)))(1) = 0;
	(*(&(set->B)))(2) = 0;
	(*(&(set->S)))(0) = 1;
	(*(&(set->S)))(1) = 0;
	(*(&(set->S)))(2) = 0;
	(*(&(set->U)))(0) = 0;
	(*(&(set->U)))(1) = 1;
	(*(&(set->U)))(2) = 0;
	*(&(set->nx)) = 640;
	*(&(set->ny)) = 480;
	*(&(set->w)) = 10;
	*(&(set->r)) = (double) *(&(set->nx)) / (double) *(&(set->ny));

}

void run_test1( int test_no ) {

	BMP pic1, pic2;
	set set1, set2;
	int x, y;

	switch (test_no) {
	case 1:
		init_test1(&set1);
		break;
	case 2:
		init_test2(&set1);
		break;
	default:
		break;
	}

	saveModel(set1, "testoutput/model1.xml");
	loadModel(&set2, "testoutput/model1.xml");
	saveModel(set2, "testoutput/model1_2.xml");

	fillNormals(&(set1.m));
	fillNormals(&(set2.m));

	//printf("t_c %d\n", m.triangles_count);
	//printf("t0p0 %f %f %f\n", m.triangles[0].p[0](0), m.triangles[0].p[0](1), m.triangles[0].p[0](2));
	//printf("t0p1 %f %f %f\n", m.triangles[0].p[1](0), m.triangles[0].p[1](1), m.triangles[0].p[1](2));
	//printf("t0p2 %f %f %f\n", m.triangles[0].p[2](0), m.triangles[0].p[2](1), m.triangles[0].p[2](2));
	//printf("t0c %f %f %f %f\n", m.triangles[0].color(0), m.triangles[0].color(1), m.triangles[0].color(2), m.triangles[0].color(3));
	//printf("B %f %f %f\n", B(0), B(1), B(2));
	//printf("S %f %f %f\n", S(0), S(1), S(2));
	//printf("U %f %f %f\n", U(0), U(1), U(2));
	//printf("w %f r %f nxy %d %d\n", w, r, nx, ny);


	getPxDisplaceVec(&set1);
	getPxDisplaceVec(&set2);

	//printf("dx %f %f %f\n", dx(0), dx(1), dx(2));
	//printf("dy %f %f %f\n", dy(0), dy(1), dy(2));

	pic1.SetSize(set1.nx, set1.ny);
	pic1.SetBitDepth(32);

	traceAll(set1, &pic1);

	for( y = 0; y < set1.ny; y++ ) {
		pic1(set1.nx/2,y)->Alpha=255;
		pic1(set1.nx/2,y)->Blue=255;
		pic1(set1.nx/2,y)->Green=255;
		pic1(set1.nx/2,y)->Red=255;
	}
	for( x = 0; x < set1.nx; x++ ) {
		pic1(x,set1.ny/2)->Alpha=255;
		pic1(x,set1.ny/2)->Blue=255;
		pic1(x,set1.ny/2)->Green=255;
		pic1(x,set1.ny/2)->Red=255;
	}

	pic1.WriteToFile("testoutput/pic3_1.bmp");
	printf("Done\n");

	pic2.SetSize(set2.nx, set2.ny);
	pic2.SetBitDepth(32);

	traceAll(set2, &pic2);

	for( y = 0; y < set2.ny; y++ ) {
		pic2(set2.nx/2,y)->Alpha=255;
		pic2(set2.nx/2,y)->Blue=255;
		pic2(set2.nx/2,y)->Green=255;
		pic2(set2.nx/2,y)->Red=255;
	}
	for( x = 0; x < set2.nx; x++ ) {
		pic2(x,set2.ny/2)->Alpha=255;
		pic2(x,set2.ny/2)->Blue=255;
		pic2(x,set2.ny/2)->Green=255;
		pic2(x,set2.ny/2)->Red=255;
	}

	pic2.WriteToFile("testoutput/pic3_2.bmp");
	printf("Done\n");

}

void run_test3() {

	BMP pic1;
	set set1;
	int i;
	char s[1024];

	init_test1(&set1);

	fillNormals(&(set1.m));
	getPxDisplaceVec(&set1);
	pic1.SetSize(set1.nx, set1.ny);
	pic1.SetBitDepth(32);

	for( i = -6; i <= 6; i=i+2 ) {
		set1.m.lightsources[0].p(Z) = i;
		traceAll(set1, &pic1);
		sprintf(s, "testoutput/lighingtest_%d_.bmp", i);
		pic1.WriteToFile(s);
		printf("Done %d\n", i);
	}

}

void test_start( int test_no ) {

	switch (test_no) {
	case 1:
	case 2:
		run_test1(test_no);
		break;
	case 3:
		run_test3();
		break;
	default:
		break;
	}

}
