/* 
 * File:   TrashCPkg.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 1:10 AM
 */

#include "TrashCPkg.h"

TrashCPkg::TrashCPkg(double width, double length) {
    this->width = width;
    this->length = length;
    Init();
}

void TrashCPkg::Init() {
    this->trashCWidth = this->width;
    this->trashCLength = 60;

    this->trashCCount = this->length / this->trashCLength;
}

TrashCPkg::~TrashCPkg() {
}

void TrashCPkg::paint() {

    glPushMatrix();
    {
	for (int i = 0; i<this->trashCCount; i++) {
	    TrashC trashC(this->trashCWidth, this->trashCLength);
	    trashC.paintUIElement();

	    glTranslatef(this->trashCLength,0,0);
	}
    }
    glPopMatrix();


}

