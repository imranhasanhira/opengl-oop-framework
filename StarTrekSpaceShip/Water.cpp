/* 
 * File:   Water.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 12:08 PM
 */

#include "Water.h"

GLuint Water::texid = -1;

Water::Water(double baseWidth, double baseHeight) {
    this->baseWidth = baseWidth;
    this->baseHeight = baseHeight;
}

Water::Water(const Water& orig) {
}

Water::~Water() {

}

void Water::paint() {
    glPushMatrix();
    {
	
	
	//glRotatef(90, 1, 0, 0);
	glTranslatef(-this->baseWidth/2,-this->baseHeight/2,0);
	glEnable(GL_TEXTURE_2D);
	{
	    glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/
	    glNormal3f(0,0,1);
	    Drawing::DrawRectangleWithTextureXY(this->baseWidth, this->baseHeight);
	}
	glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

