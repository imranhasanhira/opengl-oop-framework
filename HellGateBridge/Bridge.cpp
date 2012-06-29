/* 
 * File:   Bridge.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 4:27 PM
 */

#include "Bridge.h"


Bridge::Bridge(double width,double height){
    this->width = width;
    this->height = height;
}

Bridge::Bridge(const Bridge& orig) {
}

Bridge::~Bridge() {
}


void Bridge::paint(){
    
    glPushMatrix();
    {
	RoadPkg road(this->width,this->height);
	road.render();
	
    }
    glPopMatrix();
    
}
