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
    ~World();
    void drawAxis();
    void drawGrid();
    int width, height;
    double** heightMap;
    Vector** normalValue;

    GLuint terrainCallListId;
    double terrainScale;

    void generateTerrain();

    void drawTerrain();

protected:
    void paint();

};

#endif	/* WORLD_H */

