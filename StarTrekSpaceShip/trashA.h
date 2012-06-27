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


class TrashA : public UIElement{
public:
    TrashA(double x, double y, double z,double w=10,double l=50);
    virtual ~TrashA();
    
    int getWidth();
    void setWidth(int w);    
    int getLength();
    void setLength(int l);
    void print();
    void InitTextures(void);
    
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
    COGLTexture Tex1, Tex2;
};

#endif	/* TRASHA_H */

