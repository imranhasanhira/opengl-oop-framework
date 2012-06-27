/* 
 * File:   TrashA.cpp
 * Author: Ibrahim
 * 
 * Created on June 24, 2012, 1:22 AM
 */

#include "TrashA.h"

TrashA::TrashA(double x, double y, double z, double w, double l) : UIElement(x, y, z) {
    this->width = w;
    this->length = l;
    this->trashAngleLineAngle  = 60;    
    this->trashBaseLineWidth  = 6;
    this->triangleBaseLength = 20;
    this->trashAngleLineWidth  = 2;    
    this->triangleDistance = 10;
    this->triangleCount = this->length/this->triangleBaseLength - 1;
    this->trashBaseLineLength = this->length + this->triangleCount * this->triangleDistance;
    this->trashAngleLineLength = sqrt(S(this->triangleBaseLength/2) + S(this->width)) + this->trashBaseLineWidth/4;
    
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

void TrashA::paint() {
 
    glTranslatef(-60,0,0);
    glColor3f(.2,.2,.3);
    glPushMatrix();
    {
	Drawing::DrawRectangle(this->trashAngleLineWidth,this->trashBaseLineLength);	
	glTranslatef(0,0,this->width);
	Drawing::DrawRectangle(this->trashAngleLineWidth,this->trashBaseLineLength);	
    }
    glPopMatrix();        
    glPushMatrix();
    {		
	glTranslatef(this->trashAngleLineWidth,0,0);
	for(int i=0;i<this->triangleCount;i++){	    
	    glPushMatrix();
	    {			
		glTranslatef( i*(this->triangleBaseLength + this->triangleDistance) ,0,this->trashBaseLineWidth/4);
		glRotatef(-this->trashAngleLineAngle,0,1,0);
		Drawing::DrawRectangle(this->trashAngleLineWidth,this->trashAngleLineLength);
		glRotatef(this->trashAngleLineAngle,0,1,0);
		glTranslatef( this->triangleBaseLength + this->triangleDistance/2 + this->trashAngleLineWidth/2, 0 , 0 );		
		glRotatef(-2*this->trashAngleLineAngle,0,1,0);
		Drawing::DrawRectangle(this->trashAngleLineWidth,this->trashAngleLineLength);
		
	    }
	    glPopMatrix();
	}
    }
    
    
    
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

void TrashA::print(){
    printf("Width :%d\n", this->width);
    printf("Height :%d\n", this->length);
    printf("TrashBaseLineWidth :%d\n", this->trashBaseLineWidth);
    printf("tTrashBaseLineHeight :%d\n", this->trashBaseLineLength);
    printf("TrashAngleLineWidth :%d\n", this->trashAngleLineWidth);
    printf("tTrasAngleLineHeight :%d\n", this->trashAngleLineLength);
}

void TrashA::InitTextures(void)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

	Tex1.LoadFromFile("tex1.bmp");
	Tex2.LoadFromFile("tex2.bmp");

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

}