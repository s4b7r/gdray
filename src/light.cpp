/*
 * light.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: kevin
 */

#include "head.h"

using std::acos;
using std::max;
using std::cout;
using std::endl;

Vector4d getColor(Vector3d schnittpunkt, ray strahl, model modell, int tIndex, config conf){

	// Returning color vector.
	Vector4d ret(0,0,0,1);

	// Color of the object at 'schnittpunkt' (triangle 't').
	Vector4d farbe_t = modell.triangles[tIndex].color;

	// Normal vector of the object at 'schnittpunkt' (triangle 't').
	Vector3d normal_t = modell.triangles[tIndex].normal;

	// Is true if the object at 'schnittpunkt' (triangle 't') is not seen by the current light source due to another object being in the line of sight.
	bool covered = false;

	// Vector from 'schnittpunkt' to the light source.
	Vector3d P;

	// Describing the triangle 'k' with three vectors: A, B and C. AB is the vector from A to B etc..
	Vector3d A_k, AB_k, AC_k;

	// Normal vector of triangle 'k'.
	Vector3d normal_k;

	// Point where the ray from the light source 'i' intersects the plane of triangle 'k'.
	Vector3d intersectionPoint;

	/* If 'intersectionPoint' is clear a collision detection will proof whether the distance between 'intersectionPoint' and a point of the triangle 'k'
	 * is smaller than 'maxTriggerDist'. This is the largest possible distance an intersection point can have to a sampled point on the triangle 'k' and be
	 * inside of the triangle 'k'.
	 *
	 * The equation for a point on a triangle in 3D is:
	 *
	 *		point = A + n*AB + m*AC
	 *
	 * Where A, AB and AC are described as above and 'n' and 'm' reach from zero to one. The triangle 'k' is sampled in percentage steps:
	 * 'step_ab_k' and 'step_ac_k'. They depend on the length of AB or AC and the global resolution value STEP.
	 */
	double step_ab_k, step_ac_k, maxTriggerDist = STEP*0.707106781;

	// This value is the cosine of the angle between P and 'normal_t' and defines the intensity of the diffuse reflected light.
	long double cosAlpha;

	// Here start diffuse light effects independent of viewer position.
	for(int i=0;i<modell.lightsources_count;i++){	// for every light source (index i).

		// Initializing variables for the light source 'i'.
		covered = false;
		P = modell.lightsources[i].p - schnittpunkt;

		for(int k=0;k<modell.triangles_count;k++){	//for every triangle (index k) ...
			if(tIndex != k){	// ... except the one where 'schnittpunkt' is.

				// Initializing variables for the triangle 'k'.
				A_k = modell.triangles[k].p[0];
				AC_k = modell.triangles[k].p[2]-modell.triangles[k].p[0];
				AB_k = modell.triangles[k].p[1]-modell.triangles[k].p[0];
				normal_k = modell.triangles[k].normal;
				step_ab_k = STEP/AB_k.norm();
				step_ac_k = STEP/AC_k.norm();

				// Compute 'intersectionPoint'. Mathematics are described in doc.
				intersectionPoint = schnittpunkt + P*(((A_k.dot(normal_k)-schnittpunkt.dot(normal_k)))/P.dot(normal_k));

				if(P.dot(intersectionPoint-schnittpunkt)>0){	/* if 'intersectionPoint' is between triangle 't' and light source 'i'.
																 * Otherwise objects would incorrectly cover other objects from light.
																 * TODO: look for better condition -> objects will cover themselves
																 * even if light source is between them.
																 */

					// Sample the triangle 'k' as described above
					for(double x = 0.0; x <= 1.0; x += step_ab_k){
						for(double y = 0.0; y <= 1.0; y += step_ac_k){
							if(x+y <= 1.0 && ((Vector3d)(A_k+x*AB_k+y*AC_k-intersectionPoint)).norm() <= maxTriggerDist){
								//cout << "A\n" << p[0] << endl << "testPunkt\n" << testPunkt << endl << "AB\n" << AB << endl << "AC\n" << AC << endl;
								covered = true;
							}
						}
					}
				}
			}
		}

		if(!covered){

			if(conf.lighting_rnd_normal){
				normal_t(0)+=(0.2*rand()-0.1)/RAND_MAX;
				normal_t(1)+=(0.2*rand()-0.1)/RAND_MAX;
				normal_t(2)+=(0.2*rand()-0.1)/RAND_MAX;
				normal_t.normalize();
			}

			cosAlpha = normal_t.dot(P.normalized());

			// If the angle between P and 'normal_t' is smaller than 90 degrees.
			if(acos(cosAlpha) < 1.570796327){

				// Compute returning color dependently on 'cosAlpha' (angle of light irradiation).
				ret += cosAlpha * modell.lightsources[i].color;

			}

			// Compute returning color dependently on color of triangle 't'.
			for(int j=0;j<4;j++){
				ret(j) *= farbe_t(j);
			}
		}
	}

	// Normalize to usable color range (zero to one)
	ret /= modell.lightsources_count;

	return ret;
}
