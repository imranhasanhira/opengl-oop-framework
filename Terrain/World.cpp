#include <GL/glut.h>
#include "World.h"
#include "Texture.h"
#include "SkyBox.h"
#include "time.h"

World::World(Vector position,int skyBoxWidth) {
    
    
    this->position = position;
    ImageHeader* imageHeader = Texture::LoadBitmapPixelData("images/hm.bmp");
    //    imageHeader->pr();
    terrainWidth = imageHeader->width;
    terrainHeight = imageHeader->height;
    terrainHeightMap = new double*[terrainWidth];
    for (int i = 0; i < terrainWidth; i++) {
        terrainHeightMap[i] = new double[terrainHeight];
    }
    for (int i = 0; i < terrainWidth; i++) {
        for (int j = 0; j < terrainHeight; j++) {
            ColorRGBA p = imageHeader->pixels[i][j];
            terrainHeightMap[i][j] = (p.r + p.g + p.b) / 3;
            terrainHeightMap[i][j] *= terrainScale / 2;
        }
    }


    normalValue = new Vector*[terrainWidth];
    for (int i = 0; i < terrainWidth; i++) {
        normalValue[i] = new Vector[terrainHeight];
    }

    for (int i = 1; i < terrainWidth - 1; i++) {
        for (int j = 1; j < terrainHeight - 1; j++) {
            Point3f up(i, j - 1, terrainHeightMap[i][j - 1]);
            Point3f right(i + 1, j, terrainHeightMap[i + 1][j]);
            Point3f down(i, j + 1, terrainHeightMap[i][j + 1]);
            Point3f left(i - 1, j, terrainHeightMap[i - 1][j]);
            Point3f self(i, j, terrainHeightMap[i][j]);
            Vector upRight = CROSS(right - self, up - self);
            Vector upLeft = CROSS(up - self, left - self);
            Vector downLeft = CROSS(left - self, down - self);
            Vector downRight = CROSS(down - self, right - self);
            normalValue[i][j] = -(upRight + upLeft + downLeft + downRight / 4);
        }
    }

    for (int i = 0; i < terrainWidth; i++) {
        normalValue[i][0] = Vector(0, 0, 1);
        normalValue[i][terrainHeight - 1] = Vector(0, 0, 1);
    }
    for (int i = 0; i < terrainHeight; i++) {
        normalValue[0][i] = Vector(0, 0, 1);
        normalValue[terrainWidth - 1][i] = Vector(0, 0, 1);
    }

    generateTerrain();
    srand(time(NULL));    
    delete(imageHeader);
    
    terrainScale = skyBoxWidth/(double)terrainWidth;
}

World::~World() {
    for (int i = 0; i < terrainWidth; i++) {
        delete(terrainHeightMap[i]);
    }
    delete(terrainHeightMap);
}

void World::drawAxis() {
    glBegin(GL_LINES);
    {

        // X'O line
        glColor3f(0.5, 0, 0);
        glVertex3f(-100, 0, 0);
        glVertex3f(0, 0, 0);


        //OX line
        glColor3f(1.0, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(100, 0, 0);

        //Y'O line
        glColor3f(0, 0.5, 0);
        glVertex3f(0, -100, 0);
        glVertex3f(0, 0, 0);
        //OY line
        glColor3f(0, 1.0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 100, 0);

        //Z'O line
        glColor3f(0, 0, 0.5);
        glVertex3f(0, 0, -100);
        glVertex3f(0, 0, 0);
        //OZ line
        glColor3f(0, 0, 1.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 100);
    }
    glEnd();
}

void World::drawGrid() {

    glBegin(GL_LINES);
    {
        int i;

        for (i = -100; i < 100; i += 10) {
            glColor3f(0.1, 0, 0);
            glVertex3f(-100, i, 0);
            glVertex3f(100, i, 0);

            glColor3f(0, 0.1, 0);
            glVertex3f(i, -100, 0);
            glVertex3f(i, 100, 0);

        }
    }
    glEnd();
}

void World::generateTerrain() {
    terrainCallListId = 0;
    terrainCallListId = glGenLists(1);

    glNewList(terrainCallListId, GL_COMPILE);

    drawTerrain();

    glEndList();
    printf("list generated");
}

void World::drawTerrain() {
    glPushMatrix();

    //starting drawing terrain
    glTranslatef(-terrainWidth * terrainScale / 2.0, -terrainHeight * terrainScale / 2.0, 0);
    glBindTexture(GL_TEXTURE_2D, Texture::ROCK_TILE);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    for (int i = 0; i < terrainHeight - 1; i++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j < terrainWidth - 1; j++) {
            glNormal3f(CO(normalValue[j][i]));
            //            glColor3f(heightMap[j][i] / 255.0, heightMap[j][i] / 255.0, heightMap[j][i] / 255.0);
            glTexCoord2f(0, 0);
            glVertex3f(j * terrainScale, i * terrainScale, terrainHeightMap[j][i]);

            glNormal3f(CO(normalValue[j][i + 1]));
            //            glColor3f(heightMap[j][i + 1] / 255.0, heightMap[j][i + 1] / 255.0, heightMap[j][i + 1] / 255.0);
            glTexCoord2f(0, 1);
            glVertex3f(j * terrainScale, (i + 1) * terrainScale, terrainHeightMap[j][i + 1]);

            glNormal3f(CO(normalValue[j + 1][i]));
            //            glColor3f(heightMap[j + 1][i ] / 255.0, heightMap[j + 1][i ] / 255.0, heightMap[j + 1][i] / 255.0);
            glTexCoord2f(1, 0);
            glVertex3f((j + 1) * terrainScale, (i) * terrainScale, terrainHeightMap[j + 1][i ]);

            glNormal3f(CO(normalValue[j + 1][i + 1]));
            //            glColor3f(heightMap[j + 1][i + 1] / 255.0, heightMap[j + 1][i + 1] / 255.0, heightMap[j + 1][i + 1] / 255.0);
            glTexCoord2f(1, 1);
            glVertex3f((j + 1) * terrainScale, (i + 1) * terrainScale, terrainHeightMap[j + 1][i + 1]);


        }
        glEnd();
    }

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void World::paint() {
    //    drawGrid();
        glCallList(terrainCallListId);
    drawAxis();
//    drawTerrain();


}