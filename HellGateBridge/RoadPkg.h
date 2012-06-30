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
    RoadPkg(double width,double length);
    RoadPkg(const RoadPkg& orig);
    virtual ~RoadPkg();
    void Init();
    
protected:
    void paint();
    
private:
    double width;
    double length;
    double unitCount;
    double roadLength;

};

#endif	/* ROADPKG_H */

