/*
 * model.c
 *
 *  Created on: 25.07.2014
 *      Author: sieb
 *
 * World, objects, models, triangles ...
 */

#include "head.h"

void saveModel( set set, char *filename ) {

	model m;
	int i, pi;
	triangle t;
	lightsource l;
	vector p;
	char s[20];
	mxml_node_t *xml;
	mxml_node_t *e0;
	mxml_node_t *e1;
	mxml_node_t *e2;
	mxml_node_t *e3;
	FILE *file;

	m = set.m;

	xml = mxmlNewXML("1.0");



	e0 = mxmlNewElement(xml, "B");

	e1 = mxmlNewElement(e0, "x");
	mxmlNewReal(e1, (double)set.B(0));

	e1 = mxmlNewElement(e0, "y");
	mxmlNewReal(e1, (double)set.B(1));

	e1 = mxmlNewElement(e0, "z");
	mxmlNewReal(e1, (double)set.B(2));

	e0 = mxmlNewElement(xml, "S");

	e1 = mxmlNewElement(e0, "x");
	mxmlNewReal(e1, (double)set.S(0));

	e1 = mxmlNewElement(e0, "y");
	mxmlNewReal(e1, (double)set.S(1));

	e1 = mxmlNewElement(e0, "z");
	mxmlNewReal(e1, (double)set.S(2));

	e0 = mxmlNewElement(xml, "U");

	e1 = mxmlNewElement(e0, "x");
	mxmlNewReal(e1, (double)set.U(0));

	e1 = mxmlNewElement(e0, "y");
	mxmlNewReal(e1, (double)set.U(1));

	e1 = mxmlNewElement(e0, "z");
	mxmlNewReal(e1, (double)set.U(2));

	e0 = mxmlNewElement(xml, "w");
	mxmlNewReal(e0, set.w);

	e0 = mxmlNewElement(xml, "r");
	mxmlNewReal(e0, set.r);

	e0 = mxmlNewElement(xml, "nx");
	mxmlNewReal(e0, set.nx);

	e0 = mxmlNewElement(xml, "ny");
	mxmlNewReal(e0, set.ny);


	e0 = mxmlNewElement(xml, "triangles_count");
	mxmlNewReal(e0, m.triangles_count);

	e0 = mxmlNewElement(xml, "triangles");

	for( i = 0; i < m.triangles_count; i++ ) {

		t = m.triangles[i];
		e1 = mxmlNewElement(e0, "triangle");

		e2 = mxmlNewElement(e1, "color");

		e3 = mxmlNewElement(e2, "red");
		mxmlNewReal(e3, (double)t.color(0));

		e3 = mxmlNewElement(e2, "green");
		mxmlNewReal(e3, (double)t.color(1));

		e3 = mxmlNewElement(e2, "blue");
		mxmlNewReal(e3, (double)t.color(2));

		e3 = mxmlNewElement(e2, "alpha");
		mxmlNewReal(e3, (double)t.color(3));

		e2 = mxmlNewElement(e1, "normal");

		e3 = mxmlNewElement(e2, "x");
		mxmlNewReal(e3, (double)t.normal(0));

		e3 = mxmlNewElement(e2, "y");
		mxmlNewReal(e3, (double)t.normal(1));

		e3 = mxmlNewElement(e2, "z");
		mxmlNewReal(e3, (double)t.normal(2));

		for( pi = 0; pi < 3; pi++ ) {
			sprintf(s, "p%d", pi);
			e2 = mxmlNewElement(e1, (const char*)s);

			e3 = mxmlNewElement(e2, "x");
			mxmlNewReal(e3, (double)t.p[pi](0));

			e3 = mxmlNewElement(e2, "y");
			mxmlNewReal(e3, (double)t.p[pi](1));

			e3 = mxmlNewElement(e2, "z");
			mxmlNewReal(e3, (double)t.p[pi](2));
		}

	}

	e0 = mxmlNewElement(xml, "lightsources_count");
	mxmlNewReal(e0, m.lightsources_count);

	e0 = mxmlNewElement(xml, "lightsources");

	for( i = 0; i < m.lightsources_count; i++ ) {

		l = m.lightsources[i];
		e1 = mxmlNewElement(e0, "lightsource");

		e2 = mxmlNewElement(e1, "color");

		e3 = mxmlNewElement(e2, "red");
		mxmlNewReal(e3, (double)l.color(0));

		e3 = mxmlNewElement(e2, "green");
		mxmlNewReal(e3, (double)l.color(1));

		e3 = mxmlNewElement(e2, "blue");
		mxmlNewReal(e3, (double)l.color(2));

		e3 = mxmlNewElement(e2, "alpha");
		mxmlNewReal(e3, (double)l.color(3));

		e2 = mxmlNewElement(e1, "p");

		e3 = mxmlNewElement(e2, "x");
		mxmlNewReal(e3, (double)l.p(0));

		e3 = mxmlNewElement(e2, "y");
		mxmlNewReal(e3, (double)l.p(1));

		e3 = mxmlNewElement(e2, "z");
		mxmlNewReal(e3, (double)l.p(2));

	}

	file = fopen(filename, "w");
	mxmlSaveFile(xml, file, MXML_NO_CALLBACK);
	fclose(file);
	mxmlDelete(xml);

	fileToHumanReadableFile(filename);

}

void fileToHumanReadableFile( char *filename ) {

	FILE *i;
	FILE *o;
	char on[4096];
	char c;

	sprintf(on, "%s_tmp", filename);
	i = fopen(filename, "r");
	o = fopen(on, "w");

	while( (c = getc(i)) != EOF ) {
		putc(c, o);
		if( c == '>' ) {
			putc('\n', o);
		}
	}

	fclose(i);
	fclose(o);

	i = fopen(filename, "w");
	o = fopen(on, "r");

	while( (c = getc(o)) != EOF ) {
		putc(c, i);
	}

	fclose(i);
	fclose(o);
	remove(on);

}

void loadModel( set *set, char *filename ) {

	model *m;
	FILE *file;
	mxml_node_t *xml;
	mxml_node_t *e0;
	mxml_node_t *e1;
	mxml_node_t *e2;
	mxml_node_t *e3;
	int i, c;
	char s[3];

	m = &(set->m);

	file = fopen(filename, "r");
	xml = mxmlLoadFile(NULL, file, MXML_REAL_CALLBACK);
	fclose(file);

	e0 = mxmlFindElement(xml, xml, "B", NULL, NULL, MXML_DESCEND_FIRST);
	e1 = mxmlFindElement(e0, e0, "x", NULL, NULL, MXML_DESCEND_FIRST);
	set->B(0) = mxmlGetReal(e1);
	e1 = mxmlFindElement(e0, e0, "y", NULL, NULL, MXML_DESCEND_FIRST);
	set->B(1) = mxmlGetReal(e1);
	e1 = mxmlFindElement(e0, e0, "z", NULL, NULL, MXML_DESCEND_FIRST);
	set->B(2) = mxmlGetReal(e1);
	e0 = mxmlFindElement(xml, xml, "S", NULL, NULL, MXML_DESCEND_FIRST);
	e1 = mxmlFindElement(e0, e0, "x", NULL, NULL, MXML_DESCEND_FIRST);
	set->S(0) = mxmlGetReal(e1);
	e1 = mxmlFindElement(e0, e0, "y", NULL, NULL, MXML_DESCEND_FIRST);
	set->S(1) = mxmlGetReal(e1);
	e1 = mxmlFindElement(e0, e0, "z", NULL, NULL, MXML_DESCEND_FIRST);
	set->S(2) = mxmlGetReal(e1);
	e0 = mxmlFindElement(xml, xml, "U", NULL, NULL, MXML_DESCEND_FIRST);
	e1 = mxmlFindElement(e0, e0, "x", NULL, NULL, MXML_DESCEND_FIRST);
	set->U(0) = mxmlGetReal(e1);
	e1 = mxmlFindElement(e0, e0, "y", NULL, NULL, MXML_DESCEND_FIRST);
	set->U(1) = mxmlGetReal(e1);
	e1 = mxmlFindElement(e0, e0, "z", NULL, NULL, MXML_DESCEND_FIRST);
	set->U(2) = mxmlGetReal(e1);
	e0 = mxmlFindElement(xml, xml, "w", NULL, NULL, MXML_DESCEND_FIRST);
	set->w = mxmlGetReal(e0);
	e0 = mxmlFindElement(xml, xml, "r", NULL, NULL, MXML_DESCEND_FIRST);
	set->r = mxmlGetReal(e0);
	e0 = mxmlFindElement(xml, xml, "nx", NULL, NULL, MXML_DESCEND_FIRST);
	set->nx = mxmlGetReal(e0);
	e0 = mxmlFindElement(xml, xml, "ny", NULL, NULL, MXML_DESCEND_FIRST);
	set->ny = mxmlGetReal(e0);








	//printf("dbg cp 1\n");

	e0 = mxmlFindElement(xml, xml, "triangles_count", NULL, NULL, MXML_DESCEND_FIRST);
	m->triangles_count = mxmlGetReal(e0);
	//printf("num triangles %d\n", m->triangles_count);
	m->triangles = (triangle*)malloc(sizeof(triangle)*m->triangles_count);

	e0 = mxmlFindElement(xml, xml, "triangles", NULL, NULL, MXML_DESCEND_FIRST);
	e1 = mxmlGetFirstChild(e0);
	c = 0;
	while( e1 ) {
		//printf("triangle %d\n", c);
		e2 = mxmlFindElement(e1, e1, "color", NULL, NULL, MXML_DESCEND_FIRST);

		e3 = mxmlFindElement(e2, e2, "red", NULL, NULL, MXML_DESCEND_FIRST);
		//printf("pre t[c].c(0)\n");
		m->triangles[c].color(0) = mxmlGetReal(e3);
		//printf("post t[c].c(0)\n");

		e3 = mxmlFindElement(e2, e2, "green", NULL, NULL, MXML_DESCEND_FIRST);
		m->triangles[c].color(1) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "blue", NULL, NULL, MXML_DESCEND_FIRST);
		m->triangles[c].color(2) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "alpha", NULL, NULL, MXML_DESCEND_FIRST);
		m->triangles[c].color(3) = mxmlGetReal(e3);

		//printf("color %f %f %f %f\n", m->triangles[c].color(0), m->triangles[c].color(1), m->triangles[c].color(2), m->triangles[c].color(3));

		e2 = mxmlFindElement(e1, e1, "normal", NULL, NULL, MXML_DESCEND_FIRST);

		e3 = mxmlFindElement(e2, e2, "x", NULL, NULL, MXML_DESCEND_FIRST);
		m->triangles[c].normal(0) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "y", NULL, NULL, MXML_DESCEND_FIRST);
		m->triangles[c].normal(1) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "z", NULL, NULL, MXML_DESCEND_FIRST);
		m->triangles[c].normal(2) = mxmlGetReal(e3);

		//printf("normal %f %f %f\n", m->triangles[c].normal(0), m->triangles[c].normal(1), m->triangles[c].normal(2));

		for( i = 0; i < 3; i++ ) {
			sprintf(s, "p%d", i);
			e2 = mxmlFindElement(e1, e1, s, NULL, NULL, MXML_DESCEND_FIRST);

			e3 = mxmlFindElement(e2, e2, "x", NULL, NULL, MXML_DESCEND_FIRST);
			m->triangles[c].p[i](0) = mxmlGetReal(e3);

			e3 = mxmlFindElement(e2, e2, "y", NULL, NULL, MXML_DESCEND_FIRST);
			m->triangles[c].p[i](1) = mxmlGetReal(e3);

			e3 = mxmlFindElement(e2, e2, "z", NULL, NULL, MXML_DESCEND_FIRST);
			m->triangles[c].p[i](2) = mxmlGetReal(e3);

			//printf("p %d %f %f %f\n", i, m->triangles[c].p[i](0), m->triangles[c].p[i](1), m->triangles[c].p[i](2));
		}

		//printf("dbg cp pre 2\n");
		c++;
		//printf("dbg cp 2\n");
		e1 = mxmlWalkNext(e1, e0, MXML_NO_DESCEND);
	}

	//printf("dbg cp pre 3\n");

	e0 = mxmlFindElement(xml, xml, "lightsources_count", NULL, NULL, MXML_DESCEND_FIRST);
	m->lightsources_count = mxmlGetReal(e0);
	//printf("num lightsources %d\n", m->lightsources_count);
	//printf("dbg cp pre2 3\n");
	m->lightsources = (lightsource*)malloc(sizeof(lightsource)*m->lightsources_count);

	//printf("dbg cp 3\n");
	e0 = mxmlFindElement(xml, xml, "lightsources", NULL, NULL, MXML_DESCEND_FIRST);
	e1 = mxmlGetFirstChild(e0);
	c = 0;
	while( e1 ) {
		e2 = mxmlFindElement(e1, e1, "color", NULL, NULL, MXML_DESCEND_FIRST);

		e3 = mxmlFindElement(e2, e2, "red", NULL, NULL, MXML_DESCEND_FIRST);
		m->lightsources[c].color(0) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "green", NULL, NULL, MXML_DESCEND_FIRST);
		m->lightsources[c].color(1) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "blue", NULL, NULL, MXML_DESCEND_FIRST);
		m->lightsources[c].color(2) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "alpha", NULL, NULL, MXML_DESCEND_FIRST);
		m->lightsources[c].color(3) = mxmlGetReal(e3);

		e2 = mxmlFindElement(e1, e1, "p", NULL, NULL, MXML_DESCEND_FIRST);

		e3 = mxmlFindElement(e2, e2, "x", NULL, NULL, MXML_DESCEND_FIRST);
		m->lightsources[c].p(0) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "y", NULL, NULL, MXML_DESCEND_FIRST);
		m->lightsources[c].p(1) = mxmlGetReal(e3);

		e3 = mxmlFindElement(e2, e2, "z", NULL, NULL, MXML_DESCEND_FIRST);
		m->lightsources[c].p(2) = mxmlGetReal(e3);

		c++;
		//printf("dbg cp 4\n");
		e1 = mxmlWalkNext(e1, e0, MXML_NO_DESCEND);
	}
	//printf("dbg cp 5\n");

}

void fillNormals( model *m ) {

	for(int i=0;i<m->triangles_count;i++){
		m->triangles[i].normal = ((m->triangles[i].p[1]-m->triangles[i].p[0]).cross(m->triangles[i].p[2]-m->triangles[i].p[0])).normalized();
	}

}

