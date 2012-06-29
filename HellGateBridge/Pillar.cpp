/* 
 * File:   Pillar.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 2:44 PM
 */



#include "Pillar.h"
#include "drawing.h"
#include "Texture.h"
#include <math.h>

GLuint Pillar::textureID = -1;

Pillar::Pillar(Vector position, double length, double width, double height) : UIElement(position) {

    l = length * .3;
    d = length * .4;
    el = length * .1;
    iel = length * .1;

    w = width * 0.8;
    ew = width * 0.1;

    h = height;
    dh = h / 2;

    calcPoints();
}

void Pillar::calcPoints() {
    points[0] = Point3f(0, 0, 0);
    points[1] = Point3f(l + iel, w, 0);
    points[2] = Point3f(l, w, 0);
    points[3] = Point3f(l, w + ew, 0);
    points[4] = Point3f(0, w + ew, 0);
    points[5] = Point3f(0, w, 0);
    points[6] = Point3f(-el, w, 0);
    points[7] = Point3f(-el, 0, 0);
    points[8] = Point3f(0, 0, 0);
    points[9] = Point3f(0, -ew, 0);
    points[10] = Point3f(l, -ew, 0);
    points[11] = Point3f(l, 0, 0);
    points[12] = Point3f(l + iel, 0, 0);
    points[13] = Point3f(l + iel, w, h);
    points[14] = Point3f(l, w, h);
    points[15] = Point3f(0, w, h);
    points[16] = Point3f(0, 0, h);
    points[17] = Point3f(l, 0, h);
    points[18] = Point3f(l + iel, 0, h);
}

Pillar::Pillar(const Pillar& orig) {
}

Pillar::~Pillar() {
}

void Pillar::drawPillerPartial() {

    int indices[] = {1, 13, 2, 14, 3, 14, 4, 15, 5, 15, 6, 15, 7, 16, 8, 16, 9, 16, 10, 17, 11, 17, 12, 18, 1, 13};
    glEnable(GL_TEXTURE_2D);
    {
        glBegin(GL_QUADS);
        {
            for (int i = 0; i < 23; i += 2) {
                glTexCoord2f(0, 0);
                glVertex3f(points[indices[i]].x, points[indices[i]].y, points[indices[i]].z);
                glTexCoord2f(0, 1);
                glVertex3f(points[indices[i + 1]].x, points[indices[i + 1]].y, points[indices[i + 1]].z);
                glTexCoord2f(1, 0);
                glVertex3f(points[indices[i + 3]].x, points[indices[i + 3]].y, points[indices[i + 3]].z);
                glTexCoord2f(1, 1);
                glVertex3f(points[indices[i + 2]].x, points[indices[i + 2]].y, points[indices[i + 2]].z);
            }
        }
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);

}

void Pillar::drawPillerMiddle() {

    int totalStep = 100;

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUAD_STRIP);
    for (int theta = 0, i = 0; theta < 180; theta += 180.0 / totalStep, i++) {
        double uy = h - dh;
        double lx1 = d * cos(D2R(theta)) / 2;
        double ly1 = uy * sin(D2R(theta)) / 2;
        glTexCoord2f(0, i % 2);
        glVertex3f(lx1, 0, ly1);
        glTexCoord2f(1, i % 2);
        glVertex3f(lx1, 0, uy);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int theta = 0, i = 0; theta < 180; theta += 180.0 / totalStep, i++) {
        double uy = h - dh;
        double lx1 = d * cos(D2R(theta)) / 2;
        double ly1 = uy * sin(D2R(theta)) / 2;
        glTexCoord2f(i % 2, 0);
        glVertex3f(lx1, 0, ly1);
        glTexCoord2f(i % 2, 1);
        glVertex3f(lx1, w, ly1);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int theta = 0, i = 0; theta < 180; theta += 180.0 / totalStep, i++) {
        double uy = h - dh;
        double lx1 = d * cos(D2R(theta)) / 2;
        double ly1 = uy * sin(D2R(theta)) / 2;
        glTexCoord2f(i % 2, 0);
        glVertex3f(lx1, w, ly1);
        glTexCoord2f(i % 2, 1);
        glVertex3f(lx1, w, uy);
    }
    glEnd();


    glDisable(GL_TEXTURE_2D);

}

void Pillar::paint() {

    glPushMatrix();
    {
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, textureID); /*  texid isa variablecorrespondsto  the  image*/

        drawPillerPartial();
        glPushMatrix();
        {
            glTranslatef(l + iel + d / 2, 0, dh);
            drawPillerMiddle();

            glTranslatef(l + iel + d / 2, w, -dh);
            glRotatef(180, 0, 0, 1);
            drawPillerPartial();
        }
        glPopMatrix();
        glTranslatef(0, 0, h);

        glEnable(GL_TEXTURE_2D);
        double len = 2 * l + 2 * iel + d;
        Drawing::DrawBoxWithTexture(5, len, w);

        glBegin(GL_QUAD_STRIP);
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, 0);
        glTexCoord2f(1, 0);
        glVertex3f(0, w, 0);
        glTexCoord2f(0, 1);
        glVertex3f(len, 0, 0);
        glTexCoord2f(1, 1);
        glVertex3f(len, w, 0);
        glEnd();

        glDisable(GL_TEXTURE_2D);


    }
    glPopMatrix();
}

