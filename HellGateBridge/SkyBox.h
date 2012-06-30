/* 
 * File:   SkyBox.h
 * Author: Ibrahim
 *
 * Created on June 30, 2012, 3:50 AM
 */

#ifndef SKYBOX_H
#define	SKYBOX_H

#include "UIElement.h"

#include "Resource.h"

extern Resource resource;

class SkyBox : public UIElement{
public:
    SkyBox(double width,double height);
    SkyBox(const SkyBox& orig);
    virtual ~SkyBox();
    
    static GLuint skyUpId;
    static GLuint skyLeftId;
    static GLuint skyRightId;
    static GLuint skyFrontId;
    static GLuint skyBackId;
protected :
	void paint();
private:
    double width;
    double height;
};

#endif	/* SKYBOX_H */

