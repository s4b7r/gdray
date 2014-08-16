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

	if( argc == 2 && strcmp(argv[1], "--help") ) {
		// Read this for more details...
		// todo print help
	} else if( argc == 3 ) {
		// Run the standard procedure
		standard(argv[1], argv[2]);
	}
	else if( (argc == 2 && strcmp(argv[1], "--run-test")) || DEV_TEST ) {
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



