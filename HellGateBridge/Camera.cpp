#include "Camera.h"
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "Resource.h"
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
    up = CROSS(along, initialForward);
}

/**
 * Exposes the camera with gluLookAt function
 */
void Camera::expose() {
    Vector target = position + forward;
    gluLookAt(CO(position), CO(target), CO(up));
}

void Camera::setFaceToOrigin() {

    //position.showln();

    double rad = position.mag();

    position.x = rad * cos(theta) * cos(gamma);
    position.y = rad * sin(theta) * cos(gamma);
    position.z = rad * sin(gamma);

    forward = -position;
    up = CROSS(CROSS(forward, Vector(0, 0, 1)), forward);
}

void Camera::circularUp() {
    gamma += resource.delTheta;
    if (gamma >= 360) {
        gamma = 0;
    }
    setFaceToOrigin();
}

void Camera::circularDown() {
    setFaceToOrigin();
    gamma -= resource.delTheta;
    if (gamma < 0) {
        gamma = 360;
    }
}

void Camera::circularLeft() {
    setFaceToOrigin();
    theta += resource.delTheta;
    if (theta >= 360) {
        theta = 0;
    }
}

void Camera::circularRight() {
    setFaceToOrigin();
    theta -= resource.delTheta;
    if (theta < 0) {
        theta = 360;
    }
}