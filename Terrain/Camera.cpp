#include "Camera.h"
#include <GL/glut.h>
#include <math.h>
#include "Resource.h"
#include "Logger.h"
extern Logger logger;
extern Resource resource;

Camera::Camera(Vector tPosition, Vector tForward, Vector tUp) {
    initialPosition = tPosition;
    initialForward = tForward;
    initialUp = tUp;
    reset();
}

void Camera::reset() {
    position = initialPosition;
    forward = initialForward;
    Vector along = CROSS(initialForward, initialUp);
    up = CROSS(along, initialForward).unit();
    theta = gamma = 0;
}

Vector Camera::getPosition() {
    return position;
}

/**
 * Exposes the camera with gluLookAt function
 */
void Camera::expose() {
    
    Vector target = position + forward;
    gluLookAt(CO(position), CO(target), CO(up));
    
    drawAxis();
}

void Camera::setFaceToOrigin() {
    //    logger.prs(theta);
    //    logger.prl(gamma);

    double rad = position.mag();

    position.x = rad * cos(D2R(theta)) * cos(D2R(gamma));
    position.y = rad * sin(D2R(theta)) * cos(D2R(gamma));
    position.z = rad * sin(D2R(gamma));

    forward = -position;
    up = CROSS(CROSS(forward, Vector(0, 0, 1)), forward);
}

void Camera::circularUp() {
    if (gamma < 89) {
        gamma += resource.delTheta;
    }
    setFaceToOrigin();
}

void Camera::circularDown() {
    if (gamma > -89) {
        gamma -= resource.delTheta;
    }
    setFaceToOrigin();
}

void Camera::circularLeft() {
    theta += resource.delTheta;
    if (theta > 360) {
        theta = 0;
    }
    setFaceToOrigin();
}

void Camera::circularRight() {
    theta -= resource.delTheta;
    if (theta < 0) {
        theta = 360;
    }
    setFaceToOrigin();
}

void Camera::print() {
    position.showln();
    forward.showln();
    up.showln();
}