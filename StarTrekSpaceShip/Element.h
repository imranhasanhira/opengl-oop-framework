/* 
 * File:   Object.h
 * Author: Md Imran Hasan
 *
 * Created on June 1, 2012, 7:37 PM
 */

#ifndef OBJECT_H
#define	OBJECT_H


#include "Resource.h"

extern Resource resource;

class Element {
protected:

    virtual void role(double angle) = 0;

    virtual void pitch(double angle) = 0;

    virtual void yow(double angle) = 0;

    virtual void stepX(double delStep) = 0;

    virtual void stepY(double delStep) = 0;

    virtual void stepZ(double delStep) = 0;

public:

    void roleLeft(double angle = resource.delTheta) {
        role(angle);
    }

    void roleRight(double angle = -resource.delTheta) {
        role(angle);
    }

    void pitchClockWise(double angle = resource.delTheta) {
        pitch(angle);
    }

    void pitchCounterClockWise(double angle = -resource.delTheta) {
        pitch(angle);
    }

    void yowUp(double angle = resource.delTheta) {
        yow(angle);
    }

    void yowDown(double angle = -resource.delTheta) {
        yow(angle);
    }

    void stepLeft(double delStep = resource.delStep) {
        stepX(delStep);
    }

    void stepRight(double delStep = -resource.delStep) {
        stepX(delStep);
    }

    void stepDown(double delStep = resource.delStep) {
        stepZ(delStep);
    }

    void stepUp(double delStep = -resource.delStep) {
        stepZ(delStep);
    }

    void stepForward(double delStep = resource.delStep) {
        stepY(delStep);
    }

    void stepBackward(double delStep = -resource.delStep) {
        stepY(delStep);
    }
};

#endif	/* OBJECT_H */

