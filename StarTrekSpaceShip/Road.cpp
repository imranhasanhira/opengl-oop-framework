/* 
 * File:   Road.cpp
 * Author: Ibrahim
 * 
 * Created on June 24, 2012, 1:22 AM
 */

#include "Road.h"

GLuint Road::railTexId = -1;
GLuint Road::roadTexId = -1;

Road::Road(double w, double l) : UIElement(0, 0, 0) {
    this->width = w;
    this->length = l;
    Init();
}

Road::Road(double x, double y, double z, double w, double l) : UIElement(x, y, z) {
    this->width = w;
    this->length = l;
    Init();
}

void Road::Init() {
    this->railWidth = 20;
}

Road::~Road() {
}

int Road::getWidth() {
    return this->width;
}

void Road::setWidth(int w) {
    this->width = w;
}

int Road::getLength() {
    return this->length;
}

void Road::setLength(int l) {
    this->length = l;
}

void Road::TestTexture() {
    glEnable(GL_TEXTURE_2D);
    {

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, this->roadTexId); /*  texid isa variablecorrespondsto  the  image*/
	glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	Drawing::DrawRectangleWithTexture(30, 100);
    }
    glDisable(GL_TEXTURE_2D);
}

void Road::paint() {

    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{
	    glBindTexture(GL_TEXTURE_2D, this->roadTexId); /*  texid isa variablecorrespondsto  the  image*/
	    glNormal3f(0.0, 0.0, 1.0); //  Normal vector  to  the  polygon
	    Drawing::DrawRectangleWithTexture(this->width, this->length);

	    glBindTexture(GL_TEXTURE_2D, this->railTexId); /*  texid isa variablecorrespondsto  the  image*/
	    
	    glTranslatef(0, .5, 20);
	    glNormal3f(0.0, 0.0, 1.0); //  Normal vector  to  the  polygon	    
	    Drawing::DrawRectangleWithTexture(this->railWidth, this->length);
	    
	    glTranslatef(0, 0, 30);
	    glNormal3f(0.0, 0.0, 1.0); //  Normal vector  to  the  polygon	    
	    Drawing::DrawRectangleWithTexture(this->railWidth, this->length);
	    
	    glTranslatef(0, 0, 40);	    
	    glNormal3f(0.0, 0.0, 1.0); //  Normal vector  to  the  polygon	    
	    Drawing::DrawRectangleWithTexture(this->railWidth, this->length);
	}
	glDisable(GL_TEXTURE_2D);

    }
    glPopMatrix();

}

void Road::print() {

}

