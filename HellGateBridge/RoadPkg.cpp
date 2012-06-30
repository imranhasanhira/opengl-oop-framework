/* 
 * File:   RoadPkg.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 12:52 AM
 */

#include "RoadPkg.h"

RoadPkg::RoadPkg(double width, double length) {
    this->width = width;
    this->length = length;
    Init();
}

RoadPkg::RoadPkg(const RoadPkg& orig) {
}

RoadPkg::~RoadPkg() {

}

void RoadPkg::Init(){
    this->roadLength = 20;
    this->unitCount = this->length/this->roadLength;
}

void RoadPkg::paint() {
    glPushMatrix();
    {
	glRotatef(90,1,0,0);
	for (int i = 0; i < this->unitCount ; i++) {
	    Road road(this->width,this->roadLength);
	    road.render();
	    glTranslatef(20, 0, 0);
	}
    }
    glPopMatrix();

}

