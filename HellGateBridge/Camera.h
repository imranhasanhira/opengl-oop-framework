/* 
 * File:   Camera.h
 * Author: Md Imran Hasan
 *
 * Created on May 31, 2012, 11:47 PM
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include "Element.h"
#include "Vector.h"

class Camera : public Element {
    Vector initialPosition;
    Vector initialForward;
    Vector initialUp;

    double theta;
    double gamma;

    void setFaceToOrigin();

public:

    Camera(Vector tEye, Vector tForward, Vector tUp);
    void reset();
    void expose();

    void circularUp();
    void circularDown();
    void circularLeft();
    void circularRight();

};



#endif	/* CAMERA_H */

