/* 
 * File:   World.h
 * Author: Md Imran Hasan
 *
 * Created on May 31, 2012, 11:59 PM
 */

#ifndef WORLD_H
#define	WORLD_H


#include "UIElement.h"

class World : public UIElement {
public:
    World();
    void drawAxis();
    void drawGrid();

protected:
    void paint();

};

#endif	/* WORLD_H */
