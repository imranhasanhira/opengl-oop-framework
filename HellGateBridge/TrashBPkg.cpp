/* 
 * File:   TrashBPkg.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 10:08 AM
 */

#include "TrashBPkg.h"

TrashBPkg::TrashBPkg(double height, double length) {
    this->length = length;
    this->height = height;
    Init();
}

TrashBPkg::~TrashBPkg() {

}

void TrashBPkg::Init() {
    this->trashBAngle = 30;
    this->trashBAngleLineLen = 40;
    this->trashBStraightLineLen = 40;
    this->trashBTrashWidth = 3;
    this->trashBjointTriangleBaseWidth = 10;
    this->trashBjointTriangleHeight = 5;
    this->trashBBaseLineLen = this->trashBAngleLineLen * sin(D2R(this->trashBAngle));
    this->unitCount = this->length / this->trashBBaseLineLen;
    this->unitShiftLen = this->trashBStraightLineLen - this->trashBAngleLineLen * cos(D2R(this->trashBAngle));
}

void TrashBPkg::paint() {

    glColor3f(1, 0, 0);
    glPushMatrix();
    {
	//	glEnable(GL_TEXTURE_2D);
	{

	    //glBindTexture(GL_TEXTURE_2D, TrashB::texid); /*  texid isa variablecorrespondsto  the  image*/	    

	    int step = 20;
	    for (int x = -90; x < 270; x += 20) {

		//		    glTranslatef(x,0,this->height * sin(x));
		//		    TrashB trashB(this->trashBStraightLineLen, this->trashBAngleLineLen,
		//		    this->trashBTrashWidth, this->trashBAngle);
		//		    trashB.render();
		glPushMatrix();
		{
		    glBegin(GL_QUADS);
		    {
			glTranslatef(x, 0, this->height * sin(D2R(x)));
			Drawing::DrawRectangleWithTextureFixed(this->trashBStraightLineLen, 5);

			//			int y = this->height * sin(D2R(x));
			//			glTexCoord2f(0, 0);glVertex3f(x, 0, y);
			//			glTexCoord2f(0, 1);glVertex3f(x + this->trashBTrashWidth, 0, 0);
			//			glTexCoord2f(1, 0);glVertex3f(x + this->trashBTrashWidth, 0, y + this->trashBStraightLineLen);			
			//			glTexCoord2f(1, 1);glVertex3f(x + this->trashBTrashWidth, 0, 0);

		    }
		    glEnd();
		}
		glPopMatrix();

	    }
	}
	//	glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    //    glPushMatrix();
    //    {
    //	//for (int i = 0; i < unitCount; i++) {
    //	for (int x = -90; x < 270; x++,count++) {
    //	    
    //	    
    //	}
    //
    //	    
    //	    TrashB trashB(this->trashBStraightLineLen, this->trashBAngleLineLen,
    //		    this->trashBTrashWidth, this->trashBAngle);
    //	    trashB.render();
    //	    
    //	    glTranslatef(this->trashBBaseLineLen + this->trashBjointTriangleBaseWidth/2,0,this->unitShiftLen);
    //	    this->trashBStraightLineLen -= this->unitCount * .5;
    //	    this->trashBAngleLineLen -= this->unitCount * .4;
    //	    this->trashBAngle += this->unitCount * .6;
    //	//}
    //    }
    //    glPopMatrix();

}