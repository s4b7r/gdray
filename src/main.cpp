/*
 * main.cpp
 *
 *  Created on: 14.08.2014
 *      Author: sieb
 */

#include "head.h"

#define DEV_TEST 1

int main(int argc, char **argv) {

	if( (argc == 2 && strcmp(argv[1], "--run-test")) || DEV_TEST ) {
		test_start();
	} else if( argc == 1 ) {
		printf("Use: GD_Ray XML-FILE OUTPUT-FILE\n");
		printf("or: GD_Ray --help\n");
		return 0;
	} else if( argc == 2 && strcmp(argv[1], "--help") ) {
		// todo print help
	} else if( argc == 3 ) {
		// todo standard procedure
	}

	return 0;

}



