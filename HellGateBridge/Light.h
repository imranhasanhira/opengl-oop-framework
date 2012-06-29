/* 
 * File:   Light.h
 * Author: Md Imran Hasan
 *
 * Created on June 29, 2012, 12:33 PM
 */

#ifndef LIGHT_H
#define	LIGHT_H

#include "Vector.h"

class Light {
    Vector position;
    double radiousA;
    double radiousB;
    double theta;

public:
    Light(double posX, double posY, double posZ, double radiousA, double radiousB);
    virtual ~Light();
    void step();
    void expose();
private:

};

#endif	/* LIGHT_H */

