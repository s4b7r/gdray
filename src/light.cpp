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
			if(x+y <= 1.0 && (p[0]+x*AB+y*AC-testPunkt).norm() <= maxTriggerDist){
				//cout << "A\n" << p[0] << endl << "testPunkt\n" << testPunkt << endl << "AB\n" << AB << endl << "AC\n" << AC << endl;
				return true;
			}
		}
	}

	return false;
}

double getAngle(Vector3d A, Vector3d B){
	return acos(A.dot(B));
}

//Vector4d getColor(Vector3d schnittpunkt, /*structray strahl,*/ Vector4d farbe, Vector3d normale, model modell){
Vector4d getColor(Vector3d schnittpunkt, ray strahl, Vector4d farbe, Vector3d normale, model modell){
	//if(normale.norm())cout << "Schnittpunkt: \n" << schnittpunkt << endl << "farbe: \n" << farbe << endl << "Normale: \n" << normale;
	Vector4d ret(0,0,0,1);

	// Diffuses Licht unabhängig von Beobachter
	for(int i=0;i<modell.lightsources_count;i++){
		bool proxybool = false;

		Vector3d sl = modell.lightsources[i].p - schnittpunkt; //Vektor vom Schnittpunkt zur Lichtquelle


		for(int k=0;k<modell.triangles_count;k++){

			Vector3d AB = modell.triangles[k].p[1]-modell.triangles[k].p[0];
			Vector3d AC = modell.triangles[k].p[2]-modell.triangles[k].p[0];

			Vector3d b3 = sl.normalized();
			Vector3d b2 = (b3.cross(AB)).normalized();
			Vector3d b1 = (b3.cross(b2)).normalized();

			Matrix3d T;
			T << b1.transpose(), b2.transpose(), b3.transpose();

			T = T.inverse().eval();

			Vector3d A_ = T*modell.triangles[k].p[0];
			Vector3d AC_ = T*AC;
			Vector3d AB_ = T*AB;

			Vector3d null_(0,0,0);
			Vector3d A0_ = null_-A_;

			if(getAngle(A0_,AB_)+getAngle(A0_,AC_) <= getAngle(AB_,AC_)){
				proxybool = true;
			}

			/*for(double j=2*STEP;j<=sl.norm();j+=STEP){
				if(getIfInsideTriangle(modell.triangles[k].p, schnittpunkt + ((j/sl.norm())*sl))){
					proxybool = true;
				}
			}*/
		}

		if(!proxybool){
			long double cosAlpha = normale.dot(sl.normalized());

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
