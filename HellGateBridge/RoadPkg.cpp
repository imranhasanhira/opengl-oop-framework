/* 
 * File:   RoadPkg.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 12:52 AM
 */

#include "RoadPkg.h"

RoadPkg::RoadPkg(double width, double height) {
    this->width = width;
    this->height = height;
}

RoadPkg::RoadPkg(const RoadPkg& orig) {
}

RoadPkg::~RoadPkg() {

}

void RoadPkg::paint() {
    glPushMatrix();
    {
	glRotatef(90,1,0,0);
	for (int i = 0; i < 100; i++) {
	    Road road(130, 20);
	    road.render();
	    glTranslatef(20, 0, 0);
	}
    }
    glPopMatrix();

}

