/* 
 * File:   TrashC.h
 * Author: Ibrahim
 *
 * Created on June 24, 2012, 1:22 AM
 */

#ifndef TRASHC_H
#define	TRASHC_H

#include "UIElement.h"
#include <cmath>

#include "Texture.h"


class TrashC : public UIElement{
public:
    TrashC(double x, double y, double z,double w=10,double l=50);
    TrashC(double w=10,double l=50);
    virtual ~TrashC();
    
    int getWidth();
    void setWidth(int w);    
    int getLength();
    void setLength(int l);
    void print();
    void TestTexture();
    void Init();
    static GLuint texid;
  
    
protected:
    void paint();
    void paintOneFace();
    
private:
    double width;
    double length;
    double trashAngleLineLength;
    double trashAngleLineAngle;
    double trashWidth;
    
    
    
    
};

#endif	/* TrashC_H */

