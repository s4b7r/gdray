/*
 * light.h
 *
 *  Created on: 15.08.2014
 *      Author: sieb
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#define STEP 0.1

enum dimension {X = 0, Y = 1, Z = 2};

using Eigen::Vector2d;

bool getIfInsideTriangle(Vector3d p[3], Vector3d testPunkt);
Vector4d getColor(Vector3d schnittpunkt, ray strahl, model modell, int tIndex, config conf);


#endif /* LIGHT_H_ */
