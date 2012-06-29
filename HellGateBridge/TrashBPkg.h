/* 
 * File:   TrashBPkg.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 10:08 AM
 */

#ifndef TRASHBPKG_H
#define	TRASHBPKG_H

#include "UIElement.h"
#include "TrashB.h"

class TrashBPkg : public UIElement {
public:
    TrashBPkg(double height,double length);
    TrashBPkg(const TrashBPkg& orig);
    virtual ~TrashBPkg();
    
    void TestTexture();
    void Init();
protected:
    void paint();    
    
private:
            
    double height;
    double length;
    double unitCount;
    double unitShiftLen;
    
    double trashBStraightLineLen;
    double trashBAngleLineLen;
    double trashBAngle;
    double trashBTrashWidth;
    double trashBBaseLineLen;
    
    
    
    double trashBjointTriangleBaseWidth;
    double trashBjointTriangleHeight;

};

#endif	/* TRASHBPKG_H */

