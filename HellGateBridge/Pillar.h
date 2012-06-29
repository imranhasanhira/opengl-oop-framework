/* 
 * File:   Pillar.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 2:44 PM
 */

#ifndef PILLAR_H
#define	PILLAR_H

#include "UIElement.h"
#include "Texture.h"

class Pillar : public UIElement {
public:
    Pillar(Vector position, double length, double width, double height);
    Pillar(const Pillar& orig);
    virtual ~Pillar();

protected:
    void paint();
    void calcPoints();
    void drawPillerPartial();
    void drawPillerTop();
    Point3f points[20];

private:
    double l; //length
    double w; //width
    double h; // height
    double el; // extraLength
    double ew; //extraWIdth
    double iel; //inner extra length
    double d; //distance
    double dh; //door height

};

#endif	/* PILLAR_H */

