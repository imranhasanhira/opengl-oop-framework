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
        eyePoint = Vector(70, 70, -30);
        forward = Vector(-100, -100, 100);

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

};



#endif	/* CAMERA_H */

