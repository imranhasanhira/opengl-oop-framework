#include <windows.h>
#include <GL/glut.h>
#include "World.h"
#include "Texture.h"
#include "SkyBox.h"
#include "time.h"

World::World() {
    terrainScale = 5;


    ImageHeader* imageHeader = Texture::LoadBitmapPixelData("images/hm.bmp");
    //    imageHeader->pr();
    width = imageHeader->width;
    height = imageHeader->height;
    heightMap = new double*[width];
    for (int i = 0; i < width; i++) {
        heightMap[i] = new double[height];
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            ColorRGBA p = imageHeader->pixels[i][j];
            heightMap[i][j] = (p.r + p.g + p.b) / 3;
            heightMap[i][j] *= terrainScale / 2;
        }
    }


    normalValue = new Vector*[width];
    for (int i = 0; i < width; i++) {
        normalValue[i] = new Vector[height];
    }

    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            Point3f up(i, j - 1, heightMap[i][j - 1]);
            Point3f right(i + 1, j, heightMap[i + 1][j]);
            Point3f down(i, j + 1, heightMap[i][j + 1]);
            Point3f left(i - 1, j, heightMap[i - 1][j]);
            Point3f self(i, j, heightMap[i][j]);
            Vector upRight = CROSS(right - self, up - self);
            Vector upLeft = CROSS(up - self, left - self);
            Vector downLeft = CROSS(left - self, down - self);
            Vector downRight = CROSS(down - self, right - self);
            normalValue[i][j] = -(upRight + upLeft + downLeft + downRight / 4);
        }
    }

    for (int i = 0; i < width; i++) {
        normalValue[i][0] = Vector(0, 0, 1);
        normalValue[i][height - 1] = Vector(0, 0, 1);
    }
    for (int i = 0; i < height; i++) {
        normalValue[0][i] = Vector(0, 0, 1);
        normalValue[width - 1][i] = Vector(0, 0, 1);
    }





    srand(time(NULL));

    generateTerrain();

    delete(imageHeader);
}

World::~World() {
    for (int i = 0; i < width; i++) {
        delete(heightMap[i]);
    }
    delete(heightMap);
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
    glTranslatef(-width * terrainScale / 2.0, -height * terrainScale / 2.0, 0);
    glBindTexture(GL_TEXTURE_2D, Texture::ROCK_TILE);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    for (int i = 0; i < height - 1; i++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j < width - 1; j++) {
            glNormal3f(CO(normalValue[j][i]));
            //            glColor3f(heightMap[j][i] / 255.0, heightMap[j][i] / 255.0, heightMap[j][i] / 255.0);
            glTexCoord2f(0, 0);
            glVertex3f(j * terrainScale, i * terrainScale, heightMap[j][i]);

            glNormal3f(CO(normalValue[j][i + 1]));
            //            glColor3f(heightMap[j][i + 1] / 255.0, heightMap[j][i + 1] / 255.0, heightMap[j][i + 1] / 255.0);
            glTexCoord2f(0, 1);
            glVertex3f(j * terrainScale, (i + 1) * terrainScale, heightMap[j][i + 1]);

            glNormal3f(CO(normalValue[j + 1][i]));
            //            glColor3f(heightMap[j + 1][i ] / 255.0, heightMap[j + 1][i ] / 255.0, heightMap[j + 1][i] / 255.0);
            glTexCoord2f(1, 0);
            glVertex3f((j + 1) * terrainScale, (i) * terrainScale, heightMap[j + 1][i ]);

            glNormal3f(CO(normalValue[j + 1][i + 1]));
            //            glColor3f(heightMap[j + 1][i + 1] / 255.0, heightMap[j + 1][i + 1] / 255.0, heightMap[j + 1][i + 1] / 255.0);
            glTexCoord2f(1, 1);
            glVertex3f((j + 1) * terrainScale, (i + 1) * terrainScale, heightMap[j + 1][i + 1]);


        }
        glEnd();
    }

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

void World::paint() {
    drawAxis();
    //    drawGrid();
    glCallList(terrainCallListId);

//        drawTerrain();


}