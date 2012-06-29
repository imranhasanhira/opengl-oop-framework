/* 
 * File:   Pillar.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 2:44 PM
 */

#include "Pillar.h"

GLuint Pillar::baseTexId = -1;

Pillar::Pillar() {
}

Pillar::Pillar(const Pillar& orig) {
}

Pillar::~Pillar() {
}


void Pillar::paint(){
    
    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{	    
	    glBindTexture(GL_TEXTURE_2D, this->baseTexId); /*  texid isa variablecorrespondsto  the  image*/
	    
	    Drawing::DrawBoxWithTexture(20,50,40);
	    glTranslatef(0,0,20);
	    Drawing::DrawBoxWithTexture(20,30,60);
	    glTranslatef(0,0,20);
	    Drawing::DrawBoxWithTexture(20,60,30);
	    
	    
	    
	}glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

