/*
 * light.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: kevin
 */

#include "head.h"

using std::acos;
using std::max;

bool getIfInsideTriangle(Vector3d p[3], Vector3d testPunkt){
	for(double x=0.0;x<=(p[1]-p[0]).norm();x+=STEP){
		for(double y=0.0;y<=(p[2]-p[0]).norm();y+=STEP){
			if(x+y <= 1.0 && (p[0]+(x/(p[1]-p[0]).norm())*(p[1]-p[0])+(y/(p[2]-p[0]).norm())*(p[2]-p[0])-testPunkt).norm() <= STEP*0.866025403){
				return true;
			}
		}
	}

	return false;
}

Vector4d getColor(Vector3d schnittpunkt, /*structray strahl,*/ Vector4d farbe, Vector3d normale, model modell){
//Vector4d getColor(Vector3d schnittpunkt, ray strahl, Vector4d farbe, Vector3d normale, model modell){
	Vector4d ret(0,0,0,1);

	// Diffuses Licht unabhängig von Beobachter
	for(int i=0;i<modell.lightsources_count;i++){
		bool proxybool = false;

		Vector3d sl = modell.lightsources[i].p - schnittpunkt; //Vektor vom Schnittpunkt zur Lichtquelle


		for(int k=0;k<modell.triangles_count;k++){
			for(double j=0.0;j<=sl.norm();j+=STEP){
				if(getIfInsideTriangle(modell.triangles[k].p, schnittpunkt + ((j/sl.norm())*sl))){
					proxybool = true;
				}
			}
		}
		if(!proxybool){
			long double cosAlpha = normale.dot(sl.normalized());

			if(acos(cosAlpha) < 90){
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
