/* 
 * File:   BigPillar.cpp
 * Author: Md Imran Hasan
 * 
 * Created on June 30, 2012, 12:04 AM
 */

#include "BigPillar.h"
#include "Pillar.h"
#include "Logger.h"
extern Logger logger;

BigPillar::BigPillar(Vector position, double length, double width, double height) : UIElement(position) {

    this->length = length;
    this->width = width;
    this->height = height;
}

BigPillar::~BigPillar() {
}

void BigPillar::drawPillerLeft(double l, double w, double h) {


    glPushMatrix();
    {
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S02);
        Drawing::DrawBoxCilinderWithTexture(0.3 * l, 0.3 * w, h, 0.3 * l, 0.3 * w);
        glTranslatef(0.3 * l, 0, .25 * h);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S04);
        Drawing::DrawDoor(0.4 * l, 0.3 * w, 0.75 * h, 100);
        glTranslatef(0.4 * l, 0, -.25 * h);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S02);
        Drawing::DrawBoxCilinderWithTexture(0.3 * l, 0.3 * w, h, 0.3 * l, 0.3 * w);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(0, 0.7 * w, 0);
        Drawing::DrawBoxCilinderWithTexture(0.3 * l, 0.3 * w, h, 0.3 * l, 0.3 * w);
        glTranslatef(0.3 * l, 0, .25 * h);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S04);
        Drawing::DrawDoor(0.4 * l, 0.3 * w, .75 * h, 100);
        glTranslatef(0.4 * l, 0, -.25 * h);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S02);
        Drawing::DrawBoxCilinderWithTexture(0.3 * l, 0.3 * w, h, 0.3 * l, 0.3 * w);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glRotatef(90, 0, 0, 1);
        glTranslatef(0.3 * w, -0.3 * l, .33 * h);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S04);
        Drawing::DrawDoor(0.4 * w, 0.3 * l, .67 * h, 100);
        glTranslatef(0, -0.7 * l, .17 * h);
        Drawing::DrawDoor(0.4 * w, 0.3 * l, .5 * h, 100);
    }
    glPopMatrix();
    glPushMatrix();
    {
        double dh = 0.05 * h;

        glTranslatef(.3 * l, .1 * w, 0);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S04);
        Drawing::DrawBoxCilinderWithTexture(.05 * l, .1 * w, h + 8, .05 * l, .1 * w);
        glTranslatef(-.3 * l, -.1 * w, h);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S01);
        Drawing::DrawBoxCilinderWithTexture(l, w, dh, l + dh, w + dh);
        glTranslatef(-dh / 2, -dh / 2, dh);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S04);
        Drawing::DrawBoxCilinderWithTexture(l + dh, w + dh, dh, l + dh, w + dh);
        glTranslatef(0, 0, dh);
        glBindTexture(GL_TEXTURE_2D, Texture::TEX_ASH_BRICK);
        Drawing::DrawRectangleWithTextureXY(w + dh, l + dh);
        glTranslatef(2.5, 2.5, -h - 5 - 3);
    }
    glPopMatrix();


}

void BigPillar::paint() {

    double dl = width * 0.05;
    double dw = length * 0.05;

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_BIG);
    Drawing::DrawBoxCilinderWithTexture(width + 4 * dl, length + 4 * dw, .1 * height, width, length);
    glTranslatef(2 * dl, 2 * dw, .1 * height);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_SMALL);
    Drawing::DrawBoxCilinderWithTexture(width, length, .1 * height, width + 2 * dl, length + 2 * dw);
    glTranslatef(-dl, -dw, .1 * height);

    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_BIG);
    Drawing::DrawBoxCilinderWithTexture(width + 2 * dl, length + 2 * dw, 3, width, length);
    glTranslatef(dl, dw, 3);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_SMALL);
    Drawing::DrawBoxCilinderWithTexture(width, length, 10, width - dl, length - dw);
    glTranslatef(dl / 2, dw / 2, 10);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_BIG);
    Drawing::DrawBoxCilinderWithTexture(width - dl, length - dw, .5 * height, width - dl, length - dw);
    width -= dl;
    length -= dw;
    glTranslatef(0, 0, .5 * height);
    Drawing::DrawRectangleWithTextureXY(length, width);



    glBindTexture(GL_TEXTURE_2D, Texture::TEX_ASH_BRICK);
    drawPillerLeft(0.3 * width, length, height);
    glPushMatrix();
    {
        glTranslatef(.3 * width, .1 * length, .6 * height);
        Drawing::DrawDoor(0.4 * width, 0.8 * length, .4 * height + 8, 100);
        glTranslatef(2.5, 0, .4 * height + 8);
        Drawing::DrawRectangleWithTextureXY(0.8 * length, .4 * width - 5);
        glTranslatef(-2.5, 0, -height - 8);
        glRotatef(180, 0, 0, 1);
        glTranslatef(-.7 * width, -.9 * length, 0);
        drawPillerLeft(0.3 * width, length, height);
    }
    glPopMatrix();



    glDisable(GL_TEXTURE_2D);
}
