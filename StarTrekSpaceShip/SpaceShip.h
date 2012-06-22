/* 
 * File:   SpaceShip.h
 * Author: Md Imran Hasan
 *
 * Created on May 31, 2012, 11:42 PM
 */

#ifndef SPACESHIP_H
#define	SPACESHIP_H

#include "UIElement.h"
#include "Vector.h"

class SpaceShip : public UIElement {
public:

    SpaceShip(double x, double y, double z) : UIElement(x, y, z) {

    }

protected:

    void paint() {

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


        //translate the world back to where it was before drawing this spaceship
        //glTranslatef(-origin.x, -origin.y, -origin.z);

    }

};




#endif	/* SPACESHIP_H */

