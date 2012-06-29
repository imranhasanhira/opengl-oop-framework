/* 
 * File:   Water.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 12:08 PM
 */

#ifndef WATER_H
#define	WATER_H

#include "UIElement.h"

class Water : public UIElement {
public:
    Water(double baseWidth, double baseHeight);
    Water(const Water& orig);
    virtual ~Water();
    static GLuint texid;

protected:
    void paint();

private:
    double baseWidth;
    double baseHeight;
};

#endif	/* WATER_H */

