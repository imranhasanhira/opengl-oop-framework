/* 
 * File:   bridgeBeam.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 10:42 AM
 */

#ifndef BRIDGEBEAM_H
#define	BRIDGEBEAM_H

#include "UIElement.h"

class BridgeBeam : public UIElement{
public:
    BridgeBeam(double width,double height);
    BridgeBeam(const BridgeBeam& orig);
    virtual ~BridgeBeam();
    void TestTexture();
    void Init();
    static GLuint texid;
    
protected:
    void paint();
    
private:
    double width;
    double length;    


};

#endif	/* BRIDGEBEAM_H */

