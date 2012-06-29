/* 
 * File:   BridgeBeamPkg.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 12:52 AM
 */

#include "BridgeBeamPkg.h"

BridgeBeamPkg::BridgeBeamPkg(double width, double length) {
    this->width = width;
    this->length = length;
    Init();
}

BridgeBeamPkg::BridgeBeamPkg(const BridgeBeamPkg& orig) {
}

BridgeBeamPkg::~BridgeBeamPkg() {

}

void BridgeBeamPkg::Init(){
    this->bridgeBeamLength = 100;
    this->bridgeBeamWidth = 21;
    this->unitCount = this->length / this->bridgeBeamLength;
}

void BridgeBeamPkg::paint() {
    glPushMatrix();
    {
	glRotatef(90,1,0,0);
	for (int i = 0; i < this->unitCount; i++) {
	    BridgeBeam bridgeBeam(this->bridgeBeamWidth, this->bridgeBeamLength);
	    bridgeBeam.paintUIElement();
	    glTranslatef(this->bridgeBeamLength, 0, 0);
	}
    }
    glPopMatrix();

}

