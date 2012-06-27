/* 
 * File:   TrashAPkg.h
 * Author: Ibrahim
 *
 * Created on June 27, 2012, 10:42 PM
 */

#ifndef TRASHAPKG_H
#define	TRASHAPKG_H

#include "UIElement.h"
#include <cmath>

#include "TrashA.h"

class TrashAPkg : public UIElement{
public:
    TrashAPkg();    
    TrashAPkg(int trashWidth,int trashLength,int pkgHeight);    
    virtual ~TrashAPkg();
    
protected:
    void paint();
    
private:
    int trashWidth;
    int trashLength;    
    int pkgHeight;
    int crossLength;    

};

#endif	/* TRASHAPKG_H */

