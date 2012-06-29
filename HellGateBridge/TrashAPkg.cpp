/* 
 * File:   TrashAPkg.cpp
 * Author: Ibrahim
 * 
 * Created on June 27, 2012, 10:42 PM
 */

#include "TrashAPkg.h"

TrashAPkg::TrashAPkg(int trashWidth,int trashLength,int pkgHeight){
    
    this->pkgHeight = pkgHeight;    
    this->trashWidth = trashWidth;
    this->trashLength = trashLength;    
    this->crossLength = sqrt(S(trashLength) + S(pkgHeight));
    
}


TrashAPkg::~TrashAPkg() {
}



void TrashAPkg::paint(){
    
     glPushMatrix();
    {		
			
	TrashA trashA1(this->trashWidth, this->trashLength);
	trashA1.render();
		
	glRotatef(45,0,0,1);
	TrashA trashA3(this->trashWidth, this->crossLength);
	trashA3.render();	
	glRotatef(-45,0,0,1);
	
	
	glTranslatef(0,this->pkgHeight,0);
			
	TrashA trashA2(this->trashWidth, this->trashLength);
	trashA2.render();
	
	glRotatef(-45,0,0,1);
	TrashA trashA4(0, 0, 0, this->trashWidth, this->crossLength);
	trashA4.render();	
	glRotatef(-45,0,0,1);
	
	
    }
    glPopMatrix();

}
