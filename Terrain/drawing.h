#ifndef __DRAWING_IS_INCLUDED__
#define __DRAWING_IS_INCLUDED__

#include "cmath"
#include <GL/glut.h>         /* glut.h includes gl.h and glu.h*/

#include <stdio.h>
#include <iostream>
#include "Vector.h"

using namespace std;

class Drawing {
public:
    GLint static slices;
    GLint static loops;
    void static DrawGrid();
    void static DrawAxies();
    void static DrawTriangles(GLdouble baseWidth, GLdouble height);
    void static DrawFlipedTriangles(GLdouble baseWidth, GLdouble height);
    void static DrawRectangle(GLdouble height, GLdouble width);
    void static DrawRectangleWithTexture(GLdouble width, GLdouble height);
    void static DrawRectangleWithTextureXY(GLdouble width, GLdouble height);
    void static DrawBoxWithTexture(GLdouble height, GLdouble width1, GLdouble width2);
    void static DrawRectangleWithTextureFixed(GLdouble width, GLdouble height);
    void static DrawRectangleWithTextureRot90(GLdouble width, GLdouble height);

    void static DrawSkyBoxWithTexture(GLdouble height, GLdouble width1, GLdouble width2);

    void static DrawCircle(GLdouble x, GLdouble y);
    void static DrawElipse(GLdouble x_radius, GLdouble y_radius, GLdouble height);
    void static DrawCylinder(GLdouble bottom_radius, GLdouble top_radius, GLdouble cyl_higiht, GLint slices = 1000, GLint loops = 1000);
    void static DrawDisk(GLdouble inner_radius, GLdouble outer_radius, GLint slices = 1000, GLint loops = 1000);

    void static DrawCone(GLdouble base, GLdouble height, GLint slices = 1000, GLint loops = 1000);
    void static DrawWireCone(GLdouble base, GLdouble height, GLint slices = 1000, GLint loops = 1000);
    void static DrawSolidSphare(GLdouble radius, GLint slices = 1000, GLint loops = 1000);
    void static DrawWireSphare(GLdouble radius, GLint slices = 1000, GLint loops = 1000);
    void static DrawBox(GLdouble height, GLdouble width1, GLdouble width2);
    void static DrawRoundedBox(GLdouble radius, GLdouble height);
    void static DrawBoxCilinderWithTexture(GLdouble length, GLdouble width, GLdouble height, GLdouble upperLength, GLdouble upperWidth);



    void static DrawDoor(double l, double w, double h, int step);
};



#endif
