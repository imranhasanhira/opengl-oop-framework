/* 
 * File:   Pillar.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 2:44 PM
 */

#ifndef PILLAR_H
#define	PILLAR_H

#include "UIElement.h"
#include "Texture.h"

class Pillar : public UIElement {
public:
    Pillar();
    Pillar(const Pillar& orig);
    virtual ~Pillar();
    static GLuint baseTexId;    
    
protected:
    void paint();
	
private:
    
    

};

#endif	/* PILLAR_H */

