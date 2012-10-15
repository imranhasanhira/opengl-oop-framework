/* 
 * File:   World.h
 * Author: Md Imran Hasan
 *
 * Created on May 31, 2012, 11:59 PM
 */

#ifndef WORLD_H
#define	WORLD_H


#include "UIElement.h"
#include "Texture.h"
#include "stdlib.h"

class World : public UIElement {
public:
    World(Vector position, int skyBoxWidth);
    ~World();
    int terrainWidth, terrainHeight;
    double** terrainHeightMap;
    ColorRGBA** terrainColorMap;
    Vector** normalValue;
    int numberOfTextureImage;

    GLuint terrainCallListId;
    double terrainScale;

    void generateTerrain();

    void drawTerrain();

    ColorRGBA blend(ImageHeader** textures, int i, int j);

    
protected:
    void paint();

};

#endif	/* WORLD_H */

