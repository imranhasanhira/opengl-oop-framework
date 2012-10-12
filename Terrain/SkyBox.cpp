/* 
 * File:   SkyBox.cpp
 * Author: Ibrahim
 * 
 * Created on June 30, 2012, 3:50 AM
 */

#include "SkyBox.h"


GLuint SkyBox::skyTopId = -1;
GLuint SkyBox::skyLeftId = -1;
GLuint SkyBox::skyRightId = -1;
GLuint SkyBox::skyFrontId = -1;
GLuint SkyBox::skyBackId = -1;

SkyBox::SkyBox(double width, double height, Vector cameraPosition) {
    this->width = width;
    this->height = height;
    this->setPosition(cameraPosition);
}

SkyBox::SkyBox(const SkyBox& orig) {
}

SkyBox::~SkyBox() {
}

void SkyBox::setPosition(Vector position) {
    this->position = Vector(position.x - width / 2, position.y - width / 2, position.z - width / 2);
}

void SkyBox::frontBack() {
    glPushMatrix();
    {
        glNormal3f(0, 1, 0);
        //        glRotatef(270, 0, 0, 1);
        glBindTexture(GL_TEXTURE_2D, skyFrontId);
        glBegin(GL_QUAD_STRIP);
        {
            glTexCoord2f(0, 0);
            glVertex3f(width, 0, 0);

            glTexCoord2f(0, 1);
            glVertex3f(width, 0, height);

            glTexCoord2f(1, 0);
            glVertex3f(0, 0, 0);

            glTexCoord2f(1, 1);
            glVertex3f(0, 0, height);
        }
        glEnd();

        glTranslatef(0, height, 0);

        glBindTexture(GL_TEXTURE_2D, skyBackId);
        glBegin(GL_QUAD_STRIP);
        {
            glTexCoord2f(0, 0);
            glVertex3f(0, 0, 0);

            glTexCoord2f(0, 1);
            glVertex3f(0, 0, height);

            glTexCoord2f(1, 0);
            glVertex3f(width, 0, 0);

            glTexCoord2f(1, 1);
            glVertex3f(width, 0, height);
        }
        glEnd();

    }
    glPopMatrix();



}

void SkyBox::leftRight() {

    glPushMatrix();
    {

        glNormal3f(0, 1, 0);
        glBindTexture(GL_TEXTURE_2D, skyRightId);
        glBegin(GL_QUAD_STRIP);
        {
            glTexCoord2f(0, 0);
            glVertex3f(width, 0, 0);

            glTexCoord2f(0, 1);
            glVertex3f(width, 0, height);

            glTexCoord2f(1, 0);
            glVertex3f(0, 0, 0);

            glTexCoord2f(1, 1);
            glVertex3f(0, 0, height);
        }
        glEnd();

        glTranslatef(0, height, 0);

        glBindTexture(GL_TEXTURE_2D, skyLeftId);
        glBegin(GL_QUAD_STRIP);
        {
            glTexCoord2f(0, 0);
            glVertex3f(0, 0, 0);

            glTexCoord2f(0, 1);
            glVertex3f(0, 0, height);

            glTexCoord2f(1, 0);
            glVertex3f(width, 0, 0);

            glTexCoord2f(1, 1);
            glVertex3f(width, 0, height);

        }
        glEnd();

    }
    glPopMatrix();
}

void SkyBox::top() {

    glPushMatrix();
    {
        glNormal3f(0, 0, 1);
        glBindTexture(GL_TEXTURE_2D, skyTopId);
        glBegin(GL_QUAD_STRIP);
        {
            glTexCoord2f(0, 0);
            glVertex3f(height, height, height);

            glTexCoord2f(0, 1);
            glVertex3f(0, height, height);

            glTexCoord2f(1, 0);
            glVertex3f(height, 0, height);

            glTexCoord2f(1, 1);
            glVertex3f(0, 0, height);

        }
        glEnd();
    }
    glPopMatrix();

}

void SkyBox::paint() {
    //    position.showln();

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glPushMatrix();
    {
        glEnable(GL_TEXTURE_2D);
        {
            frontBack();
            glTranslatef(0, width, 0);
            glRotatef(-90, 0, 0, 1);
            leftRight();
            top();
        }
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

}
