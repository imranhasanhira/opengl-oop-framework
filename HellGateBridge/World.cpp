#include <windows.h>
#include <GL/glut.h>
#include "World.h"

World::World() {
    //roleMinus();
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

void World::paint() {
    drawAxis();
    //drawGrid();
}