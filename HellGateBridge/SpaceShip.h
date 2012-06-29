/* 
 * File:   SpaceShip.h
 * Author: Md Imran Hasan
 *
 * Created on May 31, 2012, 11:42 PM
 */

#ifndef SPACESHIP_H
#define	SPACESHIP_H

#include "UIElement.h"

class SpaceShip : public UIElement {
public:

    SpaceShip(double x, double y, double z) ;

protected:
    void paint();

};




#endif	/* SPACESHIP_H */

