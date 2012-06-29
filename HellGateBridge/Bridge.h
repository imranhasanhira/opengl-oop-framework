/* 
 * File:   Bridge.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 4:27 PM
 */

#ifndef BRIDGE_H
#define	BRIDGE_H

#include "UIElement.h"
#include "TrashAPkg.h"
#include "TrashBPkg.h"
#include "TrashCPkg.h"
#include "BridgeBeamPkg.h"
#include "RoadPkg.h"

class Bridge : public UIElement {
public:
    Bridge(double width,double height);
    Bridge(const Bridge& orig);
    virtual ~Bridge();

protected:
    void paint();
private:
    
    double width;
    double height;

};

#endif	/* BRIDGE_H */

