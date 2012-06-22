/* 
 * File:   UIElement.h
 * Author: Md Imran Hasan
 *
 * Created on June 1, 2012, 8:51 PM
 */

#ifndef UIELEMENT_H
#define	UIELEMENT_H

#include "Logger.h"
#include "Vector.h"
#include "Element.h"
#include <GL/glut.h>

extern Logger logger;

class UIElement : public Element {
private:
    Vector position;
    Vector forward;
    Vector up;

protected:

    virtual void role(double angle) {
        up = rotateVector(up, forward, angle);
    }

    virtual void pitch(double angle) {
        forward = rotateVector(forward, up, angle);
    }

    virtual void yow(double angle) {
        Vector along = forward * up;
        forward = rotateVector(forward, along, angle);
        up = rotateVector(up, along, angle);
    }

    virtual void stepX(double delStep) {
        position = position + (forward * up).unit() * delStep;
    }

    virtual void stepY(double delStep) {
        position = position + up.unit() * delStep;
    }

    virtual void stepZ(double delStep) {
        position = position + forward.unit() * delStep;
    }

    virtual void paint() {
    }

public:

    UIElement(double positionX = 0, double positionY = 0, double positionZ = 0, double targetX = 0, double targetY = 1, double targetZ = 0, double topX = 0, double topY = 0, double topZ = 1) {
        position = Vector(positionX, positionY, positionZ);
        forward = Vector(targetX, targetY, targetZ);
        up = Vector(topX, topY, topZ);
    }

    double getAngle(Vector a, Vector b) {

        double sinVal = asin((a * b).mag() / (a.mag() * b.mag()));
        double cosVal = acos(DOT(a, b) / (a.mag() * b.mag()));
        if (cosVal <= PI / 2) {
            return sinVal;
        } else if (sinVal > 0) {
            return cosVal;
        } else {
            return -cosVal;
        }
    }

    void paintUIElement() {
        glPushMatrix();
        {
            glTranslated(position.x, position.y, position.z);

            Vector zAxis = Vector(0, 0, 1);
            Vector surfaceRotatingAxis = up * zAxis;

            double thetaUpVsZ = getAngle(up, zAxis) * 180 / PI;
            glRotated(-thetaUpVsZ, surfaceRotatingAxis.x, surfaceRotatingAxis.y, surfaceRotatingAxis.z);

            Vector tempForward = rotateVector(forward, surfaceRotatingAxis, thetaUpVsZ);

            Vector yAxis = Vector(0, 1, 0);
            double thetaY = getAngle(tempForward, yAxis) * 180 / PI;
            glRotated(-thetaY, zAxis.x, zAxis.y, zAxis.z);

            paint();
        }
        glPopMatrix();
    }

};

#endif	/* UIELEMENT_H */

