/*
 * main.cpp
 *
 *  Created on: 14.08.2014
 *      Author: sieb
 */

#include "head.h"

#define DEV_TEST 0

void standard( char *modelfile, char *outputfile ) {

	BMP pic;
	set set;

	loadModel(&set, modelfile);

	fillNormals(&(set.m));
	getPxDisplaceVec(&set);

	pic.SetSize(set.nx, set.ny);
	pic.SetBitDepth(32);
	traceAll(set, &pic);

	pic.WriteToFile(outputfile);

}

int main(int argc, char **argv) {

	if( argc == 2 && !strcmp(argv[1], "--help") ) {
		// Read this for more details...
		printf("\n");
		printf("GD_Ray\n");
		printf("Simple raytracer by Simon Bekemeier and Kevin ***REMOVED***,\n");
		printf("developed within computer graphics II course 2014\n");
		printf("lectured by Prof. Dr. math. ***REMOVED*** ***REMOVED***\n");
		printf("at Bielefeld University of Applied Sciences - \n");
		printf("Department of Engineering Sciences and Mathematics.\n");
		printf("\n");
		printf("Usage:\n");
		printf("GD_Ray MODELFILE OUTPUTFILE\n");
		printf("Standard usage. Will load modelfile given by MODELFILE and save\n");
		printf("raytracing result into OUTPUTFILE.\n");
		printf("\n");
		printf("GD_Ray --run-test\n");
		printf("Run the developer's test procedure.\n");
		printf("\n");
		printf("GD_Ray --help\n");
		printf("Show this help.\n");
		printf("\n");
	} else if( argc == 3 ) {
		// Run the standard procedure
		standard(argv[1], argv[2]);
	} else if( (argc == 2 && !strcmp(argv[1], "--run-test")) || DEV_TEST ) {
		// Run developer's test
		test_start();
	} else {
		// You forgot all the beautiful arguments!
		printf("General use: GD_Ray MODELFILE OUTPUTFILE\n");
		printf("or: GD_Ray --help\n");
		return 0;
	}

	return 0;

}



