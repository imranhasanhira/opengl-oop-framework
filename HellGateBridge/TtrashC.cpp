/* 
 * File:   TrashC.cpp
 * Author: Ibrahim
 * 
 * Created on June 24, 2012, 1:22 AM
 */

#include "TrashC.h"

GLuint TrashC::texid = -1;

TrashC::TrashC(double w, double l) : UIElement(0, 0, 0) {
    this->width = w;
    this->length = l;
    Init();
}

TrashC::TrashC(double x, double y, double z, double w, double l) : UIElement(x, y, z) {
    this->width = w;
    this->length = l;
    Init();
}

void TrashC::Init() {
    this->trashWidth = 4;
    this->trashAngleLineLength = sqrt(S(this->length) + S(this->width - this->trashWidth));
    this->trashAngleLineAngle = R2D(atan((this->width - this->trashWidth) / this->length));
}

TrashC::~TrashC() {
}

int TrashC::getWidth() {
    return this->width;
}

void TrashC::setWidth(int w) {
    this->width = w;
}

int TrashC::getLength() {
    return this->length;
}

void TrashC::setLength(int l) {
    this->length = l;
}

void TrashC::TestTexture() {
    glEnable(GL_TEXTURE_2D);
    {

        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, this->texid); /*  texid isa variablecorrespondsto  the  image*/
        glNormal3f(0.0, -1.0, 0.0); //  Normal vector  to  the  polygon
        Drawing::DrawRectangleWithTexture(30, 100);
    }
    glDisable(GL_TEXTURE_2D);
}

void TrashC::paintOneFace() {
    glColor3f(1, 1, 1);
    glPushMatrix();
    {
        glEnable(GL_TEXTURE_2D);
        {
            glBindTexture(GL_TEXTURE_2D, texid); /*  texid isa variablecorrespondsto  the  image*/

            glNormal3f(0.0, -1.0, 0.0);
            Drawing::DrawRectangleWithTexture(this->trashWidth, this->length);

            glPushMatrix();
            {
                glRotatef(-this->trashAngleLineAngle, 0, 1, 0);
                glNormal3f(0.0, -1.0, 0.0);
                Drawing::DrawRectangleWithTexture(this->trashWidth, this->trashAngleLineLength);
            }
            glPopMatrix();

            glTranslatef(0, 0, this->width / 2 - this->trashWidth / 2);

            glNormal3f(0.0, -1.0, 0.0);
            Drawing::DrawRectangleWithTexture(this->trashWidth, this->length);

            glTranslatef(0, 0, this->width / 2 - this->trashWidth / 2);

            glNormal3f(0.0, -1.0, 0.0);
            Drawing::DrawRectangleWithTexture(this->trashWidth, this->length);

            glPushMatrix();
            {
                glRotatef(this->trashAngleLineAngle, 0, 1, 0);
                glNormal3f(0.0, -1.0, 0.0);
                Drawing::DrawRectangleWithTexture(this->trashWidth, this->trashAngleLineLength);
            }
            glPopMatrix();
        }
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

void TrashC::paint() {

    glPushMatrix();
    {
        paintOneFace();
        glTranslatef(0, this->width, 0);
        paintOneFace();
        glRotatef(90, 1, 0, 0);
        paintOneFace();
        glTranslatef(0, this->width, 0);
        paintOneFace();

    }
    glPopMatrix();

}

void TrashC::print() {

}

