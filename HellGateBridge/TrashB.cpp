/* 
 * File:   TrashA.cpp
 * Author: Ibrahim
 * 
 * Created on June 24, 2012, 1:22 AM
 */

#include "TrashB.h"

GLuint TrashB::texid = -1;

TrashB::TrashB(double straightLineLen, double angleLineLen, double trashWidth, double angle) : UIElement(0, 0, 0) {
    this->straightLineLen = straightLineLen;
    this->angleLineLen = angleLineLen;
    this->angle = angle;
    this->trashWidth = trashWidth;
    Init();
}

TrashB::TrashB(double x, double y, double z, double straightLineLen, double angleLineLen, double trashWidth, double angle) : UIElement(x, y, z) {
    this->straightLineLen = straightLineLen;
    this->angleLineLen = angleLineLen;
    this->angle = angle;
    this->trashWidth = trashWidth;
    Init();
}

void TrashB::Init() {
    this->jointTriangleBaseWidth = 10;
    this->jointTriangleHeight = 5;
}

TrashB::~TrashB() {

}

void TrashB::TestTexture() {
    glEnable(GL_TEXTURE_2D);
    {
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, this->texid); /*  texid isa variablecorrespondsto  the  image*/
	glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	Drawing::DrawRectangleWithTexture(30, 100);
    }
    glDisable(GL_TEXTURE_2D);
}

void TrashB::paint() {
    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{	    
	    glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/
	    glPushMatrix();
	    {
		glNormal3f(0.0, -1.0, 0.0);
		Drawing::DrawRectangleWithTexture(this->straightLineLen, this->trashWidth);

		glTranslatef(-this->jointTriangleBaseWidth/4,0,this->straightLineLen - this->jointTriangleHeight);
		glNormal3f(0.0, -1.0, 0.0);
		Drawing::DrawFlipedTriangles(this->jointTriangleBaseWidth,this->jointTriangleHeight);	    

		glTranslatef(this->jointTriangleBaseWidth/1.5,0,this->jointTriangleHeight);	    
		
		glRotatef(180 - this->angle, 0, 1, 0);
		glNormal3f(0.0, -1.0, 0.0);
		Drawing::DrawRectangleWithTexture(this->angleLineLen, this->trashWidth);

	    }
	    glPopMatrix();
	    	    
	    glTranslatef(this->angleLineLen * sin(D2R(this->angle)), 0 , (this->straightLineLen - this->angleLineLen * cos(D2R(this->angle)))/2 );
	    Drawing::DrawTriangles(this->jointTriangleBaseWidth,this->jointTriangleHeight);	    
	    

	}
	glDisable(GL_TEXTURE_2D);

    }
    glPopMatrix();

}

void TrashB::print() {

}

