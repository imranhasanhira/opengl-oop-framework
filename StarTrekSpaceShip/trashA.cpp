/* 
 * File:   TrashA.cpp
 * Author: Ibrahim
 * 
 * Created on June 24, 2012, 1:22 AM
 */

#include "TrashA.h"

GLuint TrashA::texid = -1;

TrashA::TrashA(double w, double l) : UIElement(0, 0, 0){    
    this->width = w;
    this->length = l;
    Init();
}
TrashA::TrashA(double x, double y, double z, double w, double l) : UIElement(x, y, z) {
    this->width = w;
    this->length = l;
    Init();
}

void TrashA::Init(){
    this->trashAngleLineAngle = 60;
    this->trashBaseLineWidth = 6;
    this->triangleBaseLength = 20;
    this->trashAngleLineWidth = 2;
    this->triangleDistance = 10;
    this->triangleCount = this->length / (this->triangleBaseLength + this->triangleDistance);
    this->trashBaseLineLength = this->length ;
    this->trashAngleLineLength = sqrt(S(this->triangleBaseLength / 2) + S(this->width)) + this->trashBaseLineWidth / 4;    
}

TrashA::~TrashA() {
}

int TrashA::getWidth() {
    return this->width;
}

void TrashA::setWidth(int w) {
    this->width = w;
}

int TrashA::getLength() {
    return this->length;
}

void TrashA::setLength(int l) {
    this->length = l;
}

void TrashA::TestTexture() {
    glEnable(GL_TEXTURE_2D);
    {

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, this->texid); /*  texid isa variablecorrespondsto  the  image*/
	glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
	Drawing::DrawRectangleWithTexture(30, 100);
    }
    glDisable(GL_TEXTURE_2D);
}

void TrashA::paint() {


    //    glEnable(GL_TEXTURE_2D);
    //    {
    glColor3f(1, 1, 1);
    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{	    
	    glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/
	    glNormal3f(0.0, -1.0, 0.0);
	    Drawing::DrawRectangleWithTexture(this->trashAngleLineWidth, this->trashBaseLineLength);
	    glTranslatef(0, 0, this->width);
	    glNormal3f(0.0, -1.0, 0.0);
	    Drawing::DrawRectangleWithTexture(this->trashAngleLineWidth, this->trashBaseLineLength);
	}
	glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
    glPushMatrix();
    {
	glTranslatef(this->trashAngleLineWidth, 0, 0);

	for (int i = 0; i<this->triangleCount; i++) {
	    glPushMatrix();
	    {
		glEnable(GL_TEXTURE_2D);
		{
		    glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/		    
		    glTranslatef(i * (this->triangleBaseLength + this->triangleDistance), 0, this->trashBaseLineWidth / 4);
		    glRotatef(-this->trashAngleLineAngle, 0, 1, 0);
		    glNormal3f(0.0, -1.0, 0.0);
		    Drawing::DrawRectangleWithTexture(this->trashAngleLineWidth, this->trashAngleLineLength);
		    
		    glRotatef(this->trashAngleLineAngle, 0, 1, 0);
		    glTranslatef(this->triangleBaseLength + this->triangleDistance / 2 + this->trashAngleLineWidth / 2, 0, 0);
		    glRotatef(-2 * this->trashAngleLineAngle, 0, 1, 0);
		    
		    glNormal3f(0.0, -1.0, 0.0);
		    Drawing::DrawRectangleWithTexture(this->trashAngleLineWidth, this->trashAngleLineLength);
		}
		glDisable(GL_TEXTURE_2D);

	    }
	    glPopMatrix();
	}


    }
    //    }glDisable(GL_TEXTURE_2D);



    //    glPushMatrix();
    //    {	
    //	
    //	for(int i=1;i<=this->triangleCount;i++){
    //	    glPushMatrix();
    //	    {
    ////		printI(i*this->triangleBaseLength + this->trashAngleLineWidth);		
    //		glTranslatef( i*(this->triangleBaseLength) + this->triangleDistance + 2*this->trashAngleLineWidth,0,this->trashBaseLineWidth/2);
    //		glRotatef(-2*this->trashAngleLineAngle,0,1,0);
    //		Drawing::DrawRectangle(this->trashAngleLineWidth,this->trashAngleLineLength);
    //		
    //	    }
    //	    glPopMatrix();
    //	}
    //    }
    //    glPopMatrix();
}

void TrashA::print() {
    printf("Width :%d\n", this->width);
    printf("Height :%d\n", this->length);
    printf("TrashBaseLineWidth :%d\n", this->trashBaseLineWidth);
    printf("tTrashBaseLineHeight :%d\n", this->trashBaseLineLength);
    printf("TrashAngleLineWidth :%d\n", this->trashAngleLineWidth);
    printf("tTrasAngleLineHeight :%d\n", this->trashAngleLineLength);
}

