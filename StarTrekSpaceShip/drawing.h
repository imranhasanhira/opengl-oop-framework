#ifndef __DRAWING_IS_INCLUDED__
#define __DRAWING_IS_INCLUDED__

#include "cmath"
#include <windows.h>
#include <GL/glut.h>         /* glut.h includes gl.h and glu.h*/

#include <stdio.h>
#include <iostream>
#include "Vector.h"


class Drawing
{
public:	
	GLint static slices;
	GLint static loops;	
	void static DrawGrid();
	void static DrawAxies();
	void static DrawRectangle(GLdouble height,GLdouble width);
	void static DrawCircle(GLdouble x,GLdouble y);
	void static DrawElipse(GLdouble x_radius,GLdouble y_radius,GLdouble height);
	void static DrawCylinder(GLdouble bottom_radius,GLdouble top_radius,GLdouble cyl_higiht, GLint slices=1000,GLint loops=1000);
	void static DrawDisk(GLdouble   inner_radius,  GLdouble   outer_radius, GLint slices=1000,GLint loops=1000);

	void static DrawCone(GLdouble base, GLdouble height, GLint slices=1000,GLint loops=1000);
	void static DrawWireCone(GLdouble base, GLdouble height, GLint slices=1000,GLint loops=1000);
	void static DrawSolidSphare(GLdouble radius, GLint slices=1000,GLint loops=1000);
	void static DrawWireSphare(GLdouble radius, GLint slices=1000,GLint loops=1000);
	void static DrawBox(GLdouble height, GLdouble width1, GLdouble width2);
	void static DrawRoundedBox(GLdouble radius,GLdouble height);
	
};



#endif
