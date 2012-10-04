/* 
 * File:   Light.cpp
 * Author: Md Imran Hasan
 * 
 * Created on June 29, 2012, 12:33 PM
 */
#include "Light.h"

#include <windows.h>
#include <GL/glut.h>
#include "Resource.h"
#include <math.h>

#include "Logger.h"
extern Logger logger;

extern Resource resource;

Light::Light(double posX, double posY, double posZ, double radiousA, double radiousB, double thetaStep) {

    position = Vector(posX, posY, posZ);
    //    if (position.x == 0) {
    //        theta = 180;
    //    } else {
    //        theta = acos(position.y / position.x);
    //    }
    this->radiousA = radiousA;
    this->radiousB = radiousB;
    this->theta = 0;
    this->thetaStep = thetaStep;
}

Light::~Light() {

}

void Light::adjustTheta() {
    position.x = radiousA * cos(D2R(theta));
    position.y = 0;
    position.z = radiousB * sin(D2R(theta));

    //logger.prs(radiousA);
    //logger.prs(radiousB);
    //logger.prs(theta);
    //position.showln();
}

void Light::stepPlus() {
    theta += thetaStep;
    if (theta >= 360) {
        theta = 0;
    }
}

void Light::stepMinus() {
    theta -= thetaStep;
    if (theta < 0) {
        theta = 359.99999;
    }
}

void Light::expose() {
    GLfloat lightPosition[4] = {CO(position), 0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    GLfloat lightAmbiant[4] = {.1, .1, .1, 1};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbiant);
    GLfloat lightDiffuse[4] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    GLfloat lightSpecular[4] = {.1, .1, .1, .1};
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glColor3f(lightAmbiant[0], lightAmbiant[1], lightAmbiant[2]);
    glPushMatrix();
    glTranslatef(CO(position));
    glutSolidSphere(10, 10, 10);
    glPopMatrix();
}