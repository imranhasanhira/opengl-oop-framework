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

    glPushMatrix();
    {
	for (int i = 0; i < unitCount; i++) {
	    TrashB trashB(this->trashBStraightLineLen, this->trashBAngleLineLen,
		    this->trashBTrashWidth, this->trashBAngle);
	    trashB.paintUIElement();
	    
	    glTranslatef(this->trashBBaseLineLen + this->trashBjointTriangleBaseWidth/2,0,this->unitShiftLen);
	    this->trashBStraightLineLen -= this->unitCount * .5;
	    this->trashBAngleLineLen -= this->unitCount * .4;
	    this->trashBAngle += this->unitCount * .6;
	}
    }
    glPopMatrix();

}