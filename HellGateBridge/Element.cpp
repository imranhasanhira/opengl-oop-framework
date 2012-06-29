#include "Element.h"

void Element::role(double angle) {
    forward = rotateVector(forward, up, angle);
}

void Element::pitch(double angle) {
    up = rotateVector(up, forward, angle);
}

void Element::yow(double angle) {
    Vector along = forward*up;
    forward = rotateVector(forward, along, angle);
    up = rotateVector(up, along, angle);
}

void Element::stepX(double delStep) {
    position = position + (forward * up).unit() * delStep;
}

void Element::stepY(double delStep) {
    position = position + forward.unit() * delStep;
}

void Element::stepZ(double delStep) {
    position = position + up.unit() * delStep;
}

void Element::pitchPlus(double angle) {
    role(angle);
}

void Element::pitchMinus(double angle) {
    role(angle);
}

void Element::rolePlus(double angle) {
    pitch(angle);
}

void Element::roleMinus(double angle) {
    pitch(angle);
}

void Element::yowUp(double angle) {
    yow(angle);
}

void Element::yowDown(double angle) {
    yow(angle);
}

void Element::stepLeft(double delStep) {
    stepX(delStep);
}

void Element::stepRight(double delStep) {
    stepX(delStep);
}

void Element::stepDown(double delStep) {
    stepZ(delStep);
}

void Element::stepUp(double delStep) {
    stepZ(delStep);
}

void Element::stepForward(double delStep) {
    stepY(delStep);
}

void Element::stepBackward(double delStep) {
    stepY(delStep);
}
