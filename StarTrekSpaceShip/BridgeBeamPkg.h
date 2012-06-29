/* 
 * File:   BridgeBeamPkg.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 12:52 AM
 */

#ifndef BRIDGEBEAMPKG_H
#define	BRIDGEBEAMPKG_H

#include "BridgeBeam.h"

class BridgeBeamPkg : public UIElement{
public:
    BridgeBeamPkg(double width,double height);
    BridgeBeamPkg(const BridgeBeamPkg& orig);
    virtual ~BridgeBeamPkg();
    void Init();
    
protected:
    void paint();
    
private:
    double width;
    double length;
    double unitCount;
    double bridgeBeamWidth;
    double bridgeBeamLength;

};

#endif	/* ROADPKG_H */

