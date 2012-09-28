/* 
 * File:   SkyBox.cpp
 * Author: Ibrahim
 * 
 * Created on June 30, 2012, 3:50 AM
 */

#include "SkyBox.h"


GLuint SkyBox::skyUpId = -1;
GLuint SkyBox::skyLeftId = -1;
GLuint SkyBox::skyRightId = -1;
GLuint SkyBox::skyFrontId = -1;
GLuint SkyBox::skyBackId = -1;

SkyBox::SkyBox(double width, double height) {
    this->width = width;
    this->height = height;
}

SkyBox::SkyBox(const SkyBox& orig) {
}

SkyBox::~SkyBox() {
}

void SkyBox::paint() {

    glPushMatrix();
    {
	glEnable(GL_TEXTURE_2D);
	{
	    glTranslatef(-resource.worldWidth / 2, -resource.worldWidth / 2, -resource.worldWidth / 4);
	    glBindTexture(GL_TEXTURE_2D, skyLeftId); /*  texid isa variablecorrespondsto  the  image*/

	    Drawing::DrawRectangleWithTexture(resource.worldWidth, resource.worldWidth);

	    glBindTexture(GL_TEXTURE_2D, skyRightId); /*  texid isa variablecorrespondsto  the  image*/
	    glTranslatef(0, resource.worldWidth, 0);

	    Drawing::DrawRectangleWithTexture(resource.worldWidth, resource.worldWidth);

	    glPushMatrix();
	    {
		glTranslatef(0, 0, resource.worldWidth);
		glRotatef(90, 1, 0, 0);

		glBindTexture(GL_TEXTURE_2D, skyUpId); /*  texid isa variablecorrespondsto  the  image*/
		Drawing::DrawRectangleWithTexture(resource.worldWidth, resource.worldWidth);
	    }
	    glPopMatrix();
   
	    glRotatef(-90, 0, 0, 1);
	    glBindTexture(GL_TEXTURE_2D, skyBackId); /*  texid isa variablecorrespondsto  the  image*/
	    Drawing::DrawRectangleWithTexture(resource.worldWidth, resource.worldWidth);

	    glTranslatef(0, resource.worldWidth, 0);

	    glBindTexture(GL_TEXTURE_2D, skyFrontId); /*  texid isa variablecorrespondsto  the  image*/
	    Drawing::DrawRectangleWithTexture(resource.worldWidth, resource.worldWidth);


	}
	glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

