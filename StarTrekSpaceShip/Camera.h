/* 
 * File:   Camera.h
 * Author: Md Imran Hasan
 *
 * Created on May 31, 2012, 11:47 PM
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include <GL/glut.h>
#include "Element.h"
#include "Vector.h"

class Camera : public Element {
    Vector eyePoint;
    Vector forward;
    Vector up;

    void role(double angle) {
        forward = rotateVector(forward, up, angle);
        //up = rotateVector(up, Vector(0, 0, 1), angle);
    }

    void pitch(double angle) {
        up = rotateVector(up, forward, angle);
    }

    void yow(double angle) {
        Vector along = forward*up;
        forward = rotateVector(forward, along, angle);
        up = rotateVector(up, along, angle);
    }

    void stepX(double delStep) {
        eyePoint = eyePoint + (forward * up).unit() * delStep;
    }

    void stepY(double delStep) {
        eyePoint = eyePoint + forward.unit() * delStep;
    }

    void stepZ(double delStep) {
        eyePoint = eyePoint + up.unit() * delStep;
    }

public:

    Camera() {
        reset();
    }

    void reset() {
       eyePoint = Vector(-10, -160, 70);
       forward = Vector(10, 136, -45);

        Vector along = CROSS(forward, Vector(0, 0, 1));
        up = along * forward;
    }

    /**
     * Exposes the camera with gluLookAt function
     */
    void expose() {
        Vector target = eyePoint + forward;
        gluLookAt(eyePoint.x, eyePoint.y, eyePoint.z, target.x, target.y, target.z, up.x, up.y, up.z);
    }
    
    void print(){
	printf("Eye Vector : ");
	this->eyePoint.print();
	printf("Forward Vector : ");
	this->forward.print();
	printf("Up Vector : ");
	this->up.print();
    }

};



#endif	/* CAMERA_H */

