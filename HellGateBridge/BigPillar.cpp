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

BigPillar::BigPillar(Vector position) : UIElement(position) {

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


    glTranslatef(.3 * l, .1 * w, 0);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S04);
    Drawing::DrawBoxCilinderWithTexture(.05 * l, .1 * w, h + 8, .05 * l, .1 * w);
    glTranslatef(-.3 * l, -.1 * w, h);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S01);
    Drawing::DrawBoxCilinderWithTexture(l, w, 5, l + 5, w + 5);
    glTranslatef(-2.5, -2.5, 5);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_S04);
        Drawing::DrawBoxCilinderWithTexture(l + 5, w + 5, 3, l + 5, w + 5);
    glTranslatef(0, 0, 3);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_ASH_BRICK);
    Drawing::DrawRectangleWithTextureXY(w + 5, l + 5);
    glTranslatef(2.5, 2.5, -h - 5 - 3);
    
    
    
}

void BigPillar::paint() {

    double l = 40;
    double w = 30;
    double h = 30;
    double dl = l * 0.1;
    double dw = w * 0.1;


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_BIG);
    Drawing::DrawBoxCilinderWithTexture(l + 4 * dl, w + 4 * dw, 5, l, w);
    glTranslatef(2 * dl, 2 * dw, 5);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_SMALL);
    Drawing::DrawBoxCilinderWithTexture(l, w, 3, l + 2 * dl, w + 2 * dw);
    glTranslatef(-dl, -dw, 3);

    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_BIG);
    Drawing::DrawBoxCilinderWithTexture(l + 2 * dl, w + 2 * dw, 3, l, w);
    glTranslatef(dl, dw, 3);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_SMALL);
    Drawing::DrawBoxCilinderWithTexture(l, w, 10, l - dl, w - dw);
    glTranslatef(dl / 2, dw / 2, 10);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_BIG);
    Drawing::DrawBoxCilinderWithTexture(l - dl, w - dw, 30, l - dl, w - dw);
    l -= dl;
    w -= dw;
    glTranslatef(0, 0, 30);
    Drawing::DrawRectangleWithTextureXY(w, l);

    glBindTexture(GL_TEXTURE_2D, Texture::TEX_ASH_BRICK);

    drawPillerLeft(0.3 * l, w, h);
    glPushMatrix();
    {
        glTranslatef(.3 * l, .1 * w, .6 * h);
        Drawing::DrawDoor(0.4 * l, 0.8 * w, .4 * h + 8, 50);
        glTranslatef(2.5, 0, .4 * h + 8);
        Drawing::DrawRectangleWithTextureXY(0.8 * w, .4 * l - 5);
        glTranslatef(-2.5, 0, -h - 8);
        glRotatef(180, 0, 0, 1);
        glTranslatef(-.7 * l, -.9 * w, 0);
        drawPillerLeft(0.3 * l, w, h);
    }
    glPopMatrix();



    glDisable(GL_TEXTURE_2D);
}
