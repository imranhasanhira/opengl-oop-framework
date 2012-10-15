/* 
 * File:   Object.h
 * Author: Md Imran Hasan
 *
 * Created on June 1, 2012, 7:37 PM
 */

#ifndef OBJECT_H
#define	OBJECT_H


#include "Resource.h"
#include "Vector.h"

extern Resource resource;

class Element {
protected:
    Vector position;
    Vector forward;
    Vector up;

    void role(double angle);
    void pitch(double angle);
    void yow(double angle);
    void stepX(double delStep);
    void stepY(double delStep);
    void stepZ(double delStep);


public:
    
    void drawAxis();
    void drawGrid();

    void pitchPlus(double angle = resource.delTheta);

    void pitchMinus(double angle = -resource.delTheta);

    void rolePlus(double angle = resource.delTheta);

    void roleMinus(double angle = -resource.delTheta);

    void yowUp(double angle = resource.delTheta);

    void yowDown(double angle = -resource.delTheta);

    void stepLeft(double delStep = resource.delStep);

    void stepRight(double delStep = -resource.delStep);

    void stepDown(double delStep = resource.delStep);

    void stepUp(double delStep = -resource.delStep);

    void stepForward(double delStep = resource.delStep);

    void stepBackward(double delStep = -resource.delStep);
};

#endif	/* OBJECT_H */

