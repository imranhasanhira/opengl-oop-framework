#include "windows.h"
#include <GL/glut.h>
#include "SpaceShip.h"
#include "Vector.h"

SpaceShip::SpaceShip(double x, double y, double z) : UIElement(Vector(x, y, z)) {

}

void SpaceShip::paint() {

    //Transalate the world to spaceship center
    //glTranslatef(origin.x, origin.y, origin.z);

    glPushMatrix(); //Upper Disk
    {
        glScaled(0.2, 0.2, 1);
        glColor3f(1.0, 0.9, 0.5);
        glutSolidSphere(3.2, 100, 100);
    }
    glPopMatrix();

    glPushMatrix(); //Upper Disk
    {
        glScaled(1, 1, 0.15);
        glColor3f(0.2, 0.2, 0.1);
        glutSolidSphere(15, 100, 100);
    }
    glPopMatrix();

    glTranslated(0, -8, 1);
    glPushMatrix(); // Joint between Upper Disk and Body
    {
        glRotated(40, 1, 0, 0);
        glScaled(0.2, 1, 1);
        GLUquadric* quad = gluNewQuadric();
        gluCylinder(quad, 2, 1.6, 13, 100, 100);
    }
    glPopMatrix();

    glTranslated(0, 0, 10);
    glPushMatrix(); // Body
    {
        glRotated(90, 1, 0, 0);
        GLUquadric* quad = gluNewQuadric();
        gluCylinder(quad, 2.5, 2.2, 20, 100, 100);
        glColor3f(1, .6, 0);
        glutSolidSphere(2.4, 30, 30);
    }
    glPopMatrix();


    glPushMatrix(); // Left Cylinder
    {
        glTranslated(5, -10, -5);
        glRotated(90, 1, 0, 0);
        //glScaled(0.2, 1, 1);
        GLUquadric* quad = gluNewQuadric();
        glColor3f(.5, .5, .5);
        gluCylinder(quad, 1.8, 1.6, 15, 100, 100);
        glColor3f(.8, .7, .5);
        glutSolidSphere(1.6, 30, 30);
    }
    glPopMatrix();


    glPushMatrix(); // Right Cylinder
    {
        glTranslated(-5, -10, -5);
        glRotated(90, 1, 0, 0);
        //glScaled(0.2, 1, 1);
        GLUquadric* quad = gluNewQuadric();
        glColor3f(.5, .5, .5);
        gluCylinder(quad, 1.8, 1.6, 15, 100, 100);
        glColor3f(.8, .7, .5);
        glutSolidSphere(1.6, 30, 30);
    }
    glPopMatrix();

    glutSolidCube(20);


    //translate the world back to where it was before drawing this spaceship
    //glTranslatef(-origin.x, -origin.y, -origin.z);

}