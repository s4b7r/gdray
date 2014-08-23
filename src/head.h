/*
 * head.h
 *
 *  Created on: 15.08.2014
 *      Author: sieb
 */

// todo think about some interactive features

#ifndef HEAD_H_
#define HEAD_H_

// C/C++ standard libs
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

// Mini-XML library
// Read and write XML structures
#include <mxml.h>

// Eigen library
// Do some mathematics stuff
#include "Eigen/Dense"
using Eigen::Vector4d;
using Eigen::Vector3d;
using Eigen::Matrix3d;

// EasyBMP library
// Simple BMP-file creation
#include "ext-libs/EasyBMP/EasyBMP.h"

// GD_Ray's own source
#include "math_noc.h"
#include "model.h"
#include "light.h"
#include "raytrace.h"
#include "testing.h"

#endif /* HEAD_H_ */
