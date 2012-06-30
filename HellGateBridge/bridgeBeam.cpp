/* 
 * File:   bridgeBeam.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 10:42 AM
 */

#include "BridgeBeam.h"


GLuint BridgeBeam::texid = -1;

BridgeBeam::BridgeBeam(double width, double length,double height) {

    this->width = width;
    this->length = length;
    this->height = height;
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

void BridgeBeam::paintOne(bool horizontal) {
    glColor3f(1,1,1);
    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{
	    glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/	    
	    glBegin(GL_QUAD_STRIP);
	    {
		int count=0;
		for (int x = -90; x < 270; x++,count++) {

		    glNormal3f(0,-1,0);
		    if(horizontal){
			glTexCoord2f((count % 2), 1);glVertex3f(x, 0, this->height * sin(D2R(x)));
			glTexCoord2f((count % 2), 0);glVertex3f(x, this->width , this->height * sin(D2R(x)));
		    }else{
			glTexCoord2f((count % 2), 1);glVertex3f(x, 0, this->height * sin(D2R(x)));
			glTexCoord2f((count % 2), 0);glVertex3f(x, 0, this->height * sin(D2R(x)) - this->width);
		    }
		    

		}
	    }
	    glEnd();
	}
	glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

}

void BridgeBeam::paint() {

    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{
	    this->paintOne();
	    glTranslatef(0,this->width,0);
	    this->paintOne();	    	    
	    glTranslatef(0,-this->width,0);
	    this->paintOne(true);
	    glTranslatef(0,0,-this->width);
	    this->paintOne(true);
	}
	glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

//void BridgeBeam::paint() {
//
//    glPushMatrix();
//    {
//	glEnable(GL_TEXTURE_2D);
//	{	    
//	    glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/
//	     	    
//	    Drawing::DrawRectangleWithTextureXY(this->width, this->length);
//	   	   
//	    glTranslatef(0,0,this->width);
//		    
//	    Drawing::DrawRectangleWithTextureXY(this->width, this->length);
//	
//	    glRotatef(-90,1,0,0);
//	    	    
//	    Drawing::DrawRectangleWithTextureXY(this->width, this->length);
//	
//	    glTranslatef(0,0,this->width);	
//	    	    
//	    Drawing::DrawRectangleWithTextureXY(this->width, this->length);	
//	    
//	}
//	glDisable(GL_TEXTURE_2D);
//
//    }
//    glPopMatrix();
//
//}


