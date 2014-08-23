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

bool getIfInsideTriangle(Vector3d p[3], Vector3d testPunkt){
	double AB_Betrag = (p[1]-p[0]).norm();
	Vector3d AB = p[1]-p[0];
	double AC_Betrag = (p[2]-p[0]).norm();
	Vector3d AC = p[2]-p[0];

	double step_ab = STEP/AB_Betrag;
	double step_ac = STEP/AC_Betrag;

	double maxTriggerDist = STEP*0.866025403;

	for(double x = 0.0; x <= 1.0; x += step_ab){
		for(double y = 0.0; y <= 1.0; y += step_ac){
			if(x+y <= 1.0 && ((Vector3d)(p[0]+x*AB+y*AC-testPunkt)).norm() <= maxTriggerDist){
				//cout << "A\n" << p[0] << endl << "testPunkt\n" << testPunkt << endl << "AB\n" << AB << endl << "AC\n" << AC << endl;
				return true;
			}
		}
	}

	return false;
}

double getXYAngle(Vector3d A, Vector3d B){
	Vector2d a,b;
	a << A(0), A(1);
	b << B(0), B(1);
	return acos(a.dot(b));
}

//Vector4d getColor(Vector3d schnittpunkt, ray strahl, Vector4d farbe, Vector3d normale, model modell, int tIndex){
Vector4d getColor(Vector3d schnittpunkt, ray strahl, model modell, int tIndex, config conf){
	Vector4d ret(0,0,0,1);

	Vector4d farbe = modell.triangles[tIndex].color;
	Vector3d normale = modell.triangles[tIndex].normal;

	// Diffuses Licht unabhängig von Beobachter
	for(int i=0;i<modell.lightsources_count;i++){
		bool proxybool = false;

		Vector3d P = modell.lightsources[i].p - schnittpunkt; //Vektor vom Schnittpunkt zur Lichtquelle

		for(int k=0;k<modell.triangles_count;k++){
			if(tIndex != k){

				Vector3d A = modell.triangles[k].p[0];
				Vector3d AC = modell.triangles[k].p[2]-modell.triangles[k].p[0];
				Vector3d AB = modell.triangles[k].p[1]-modell.triangles[k].p[0];

				Vector3d norm = modell.triangles[k].normal;

				Vector3d intersectionPoint = schnittpunkt + P*(((A.dot(norm)-schnittpunkt.dot(norm)))/P.dot(norm));	//kann null werden
				if(P.dot(intersectionPoint-schnittpunkt)>0){

					double step_ab = STEP/AB.norm();
					double step_ac = STEP/AC.norm();

					double maxTriggerDist = STEP*0.866025403;

					for(double x = 0.0; x <= 1.0; x += step_ab){
						for(double y = 0.0; y <= 1.0; y += step_ac){
							if(x+y <= 1.0 && ((Vector3d)(A+x*AB+y*AC-intersectionPoint)).norm() <= maxTriggerDist){
								//cout << "A\n" << p[0] << endl << "testPunkt\n" << testPunkt << endl << "AB\n" << AB << endl << "AC\n" << AC << endl;
								proxybool = true;
							}
						}
					}
				}
			}
		}

		if(!proxybool){
			if(conf.lighting_rnd_normal){
				normale(0)+=(0.2*rand()-0.1)/RAND_MAX;
				normale(1)+=(0.2*rand()-0.1)/RAND_MAX;
				normale(2)+=(0.2*rand()-0.1)/RAND_MAX;
				normale.normalize();
			}
			long double cosAlpha = normale.dot(P.normalized());

			if(acos(cosAlpha) < 1.570796327){
				ret += cosAlpha * modell.lightsources[i].color;
			}

			// Abstrahlung vom Objekt abhängig von der Farbe des Objekts
			for(int j=0;j<4;j++){
				ret(j) *= farbe(j);
			}
		}
	}
	ret /= modell.lightsources_count;

	return ret;
}
