#include <windows.h>
#include <GL/glut.h>
#include "World.h"
#include "Texture.h"

World::World() {
    ImageHeader* imageHeader = Texture::LoadBitmapPixelData("images/hm1.bmp");
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
        }
    }

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
    //starting displaylist
    terrainCallListId = glGenLists(1);
    glNewList(terrainCallListId, GL_COMPILE);

    //starting drawing terrain
    double scale = 10;
    glTranslatef(-width * scale / 2.0, -height * scale / 2.0, 0);

    glNormal3f(0, 0, 1);
    glColor3f(0, 1, .5);
    for (int i = 0; i < height - 1; i++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j < width; j++) {
            glColor3f(heightMap[j][i], heightMap[j][i], heightMap[j][i]);
            glVertex3f(j * scale, i * scale, heightMap[j][i]);

            glColor3f(heightMap[j][i + 1], heightMap[j][i + 1], heightMap[j][i + 1]);
            glVertex3f(j * scale, (i + 1) * scale, heightMap[j][i + 1]);
            //            glNormal3f(0, 0, 1);
        }
        glEnd();
    }

    //finalizing displaylist
    glEndList();

}

void World::paint() {
    //    drawAxis();
    //    drawGrid();

    glCallList(terrainCallListId);
}