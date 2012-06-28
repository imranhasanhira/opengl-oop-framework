/* 
 * File:   trashA.h
 * Author: Ibrahim
 *
 * Created on June 24, 2012, 1:22 AM
 */

#ifndef TRASHB_H
#define	TRASHB_H

#include "UIElement.h"
#include <cmath>

#include "Texture.h"


class TrashB : public UIElement{
public:
    TrashB(double x, double y, double z,double len1, double len2, double trashWidth,double angle);
    TrashB(double len1,double len2,double trashWidth,double angle);
    virtual ~TrashB();
    
  
    void print();
    void TestTexture();
    void Init();
    static GLuint texid;
    
    double straightLineLen;
    double angleLineLen;
    double angle;
    double trashWidth;
    double jointTriangleBaseWidth;
    double jointTriangleHeight;
    
protected:
    void paint();
    
private:
   
    
    
    
};

#endif	/* TRASHA_H */

