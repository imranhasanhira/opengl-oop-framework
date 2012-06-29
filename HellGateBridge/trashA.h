/* 
 * File:   trashA.h
 * Author: Ibrahim
 *
 * Created on June 24, 2012, 1:22 AM
 */

#ifndef TRASHA_H
#define	TRASHA_H

#include "UIElement.h"
#include <cmath>

#include "Texture.h"


class TrashA : public UIElement{
public:
    TrashA(double x, double y, double z,double w=10,double l=50);
    TrashA(double w=10,double l=50);
    virtual ~TrashA();
    
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
    
private:
    int width;
    int length;
    double trashAngleLineAngle;
    int trashBaseLineWidth;
    int trashBaseLineLength;
    int trashAngleLineWidth;
    int trashAngleLineLength;
    int triangleBaseLength;
    int triangleCount;
    int triangleDistance;
    
    
    
};

#endif	/* TRASHA_H */

