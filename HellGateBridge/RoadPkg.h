/* 
 * File:   RoadPkg.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 12:52 AM
 */

#ifndef ROADPKG_H
#define	ROADPKG_H

#include "Road.h"

class RoadPkg : public UIElement{
public:
    RoadPkg(double width,double height);
    RoadPkg(const RoadPkg& orig);
    virtual ~RoadPkg();
    
protected:
    void paint();
    
private:
    double width;
    double height;

};

#endif	/* ROADPKG_H */

