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
    //    logger.prl(10);
    glBindTexture(GL_TEXTURE_2D, Texture::TEX_PILLER_SMALL);

    glPushMatrix();
    {
        Drawing::DrawBoxCilinderWithTexture(0.3 * l, 0.3 * w, h, 0.3 * l, 0.3 * w);
        glTranslatef(0.5 * l, 0, h / 2);
        Drawing::DrawDoor(0.4 * l, 0.3 * w, h / 2, 100);
        glTranslatef(0.2 * l, 0, -h / 2);
        Drawing::DrawBoxCilinderWithTexture(0.3 * l, 0.3 * w, h, 0.3 * l, 0.3 * w);
    }
    glPopMatrix();

    glRotatef(90, 0, 0, 1);
    glTranslatef(0.3 * w, 0, h / 2);
    Drawing::DrawDoor(0.4 * w, 0.1 * l, h / 2, 100);
    //    glTranslatef(0, 0.3 * w, -h / 2);

    glPopMatrix();
}

void BigPillar::paint() {

    double l = 40;
    double w = 30;
    double h = 50;
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


    drawPillerLeft(0.3 * l, 0.3 * w, h);




    glDisable(GL_TEXTURE_2D);
}
