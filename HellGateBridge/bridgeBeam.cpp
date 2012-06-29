/* 
 * File:   bridgeBeam.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 10:42 AM
 */

#include "BridgeBeam.h"


GLuint BridgeBeam::texid = -1;

BridgeBeam::BridgeBeam(double width, double length) {

    this->width = width;
    this->length = length;
    Init();
}

BridgeBeam::BridgeBeam(const BridgeBeam& orig) {

}

BridgeBeam::~BridgeBeam() {

}

void BridgeBeam::Init() {

}

void BridgeBeam::TestTexture() {
    glEnable(GL_TEXTURE_2D);
    {

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, this->texid); /*  texid isa variablecorrespondsto  the  image*/
	glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	Drawing::DrawRectangleWithTexture(30, 100);
    }
    glDisable(GL_TEXTURE_2D);
}

void BridgeBeam::paint() {

    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{	    
	    glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/
	     
	    glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	    Drawing::DrawRectangleWithTexture(this->width, this->length);
	   	   
	    glTranslatef(0,this->width,0);
	
	    glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	    Drawing::DrawRectangleWithTexture(this->width, this->length);
	
	    glRotatef(90,1,0,0);
	    
	    glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	    Drawing::DrawRectangleWithTexture(this->width, this->length);
	
	    glTranslatef(0,this->width,0);	
	    
	    glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	    Drawing::DrawRectangleWithTexture(this->width, this->length);	
	    
	}
	glDisable(GL_TEXTURE_2D);

    }
    glPopMatrix();

}


