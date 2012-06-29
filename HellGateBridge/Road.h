/* 
 * File:   Road.h
 * Author: Ibrahim
 *
 * Created on June 24, 2012, 1:22 AM
 */

#ifndef ROAD_H
#define	ROAD_H

#include "UIElement.h"
#include <cmath>

#include "Texture.h"


class Road : public UIElement{
public:
    Road(double x, double y, double z,double w=10,double l=50);
    Road(double w=10,double l=50);
    virtual ~Road();
    
    int getWidth();
    void setWidth(int w);    
    int getLength();
    void setLength(int l);
    void print();
    void TestTexture();
    void Init();
    static GLuint roadTexId;
    static GLuint railTexId;
  
    
protected:
    void paint();
    
    
private:
    double railWidth;
    double width;
    double length;    
    
};

#endif	/* Road_H */

