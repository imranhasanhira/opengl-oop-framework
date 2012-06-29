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

Light::Light(double posX, double posY, double posZ, double radiousA, double radiousB) {

    position = Vector(posX, posY, posZ);
    if (position.x == 0) {
        theta = M_PI / 2;
    } else {
        theta = position.y / position.x;
    }
    this->radiousA = radiousA;
    this->radiousB = radiousB;
}

Light::~Light() {

}

void Light::step() {
    theta += resource.delTheta;
    if (theta >= 360) {
        theta = 0;
    }
    position.x = radiousA * cos(theta);
    position.y = 0;
    position.z = radiousB * sin(theta);

    //logger.prs(radiousA);
    //logger.prs(radiousB);
    //logger.prs(theta);
    //position.showln();
}

void Light::expose() {
    GLfloat lightPosition[4] = {CO(position), 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    GLfloat lightAmbiant[4] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbiant);
    GLfloat lightDiffuse[4] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    GLfloat lightSpecular[4] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glColor3f(lightAmbiant[0], lightAmbiant[1], lightAmbiant[2]);
    glPushMatrix();
    glTranslatef(CO(position));
    glutSolidSphere(1, 10, 10);
    glPopMatrix();
}