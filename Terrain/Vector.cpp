#include<stdio.h>
#include<math.h>
#include "Vector.h"

Vector::Vector() {
}

Vector::Vector(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
}

bool Vector::scan() {
    return scanf("%lf%lf%lf", &x, &y, &z) == 3;
}

double Vector::mag2() {
    return S(x) + S(y) + S(z);
}

double Vector::mag() {
    return sqrt(mag2());
}

void Vector::norm() {
    double d = mag();
    x /= d;
    y /= d;
    z /= d;
}

Vector Vector::unit() {
    Vector ret = *this;
    ret.norm();
    return ret;
}

bool Vector::isZero() {
    return mag2() < 1e-9;
}

Vector Vector::scale(double s) {
    return Vector(this->x * s, this->y * s, this->z * s);
}

void Vector::show() {
    printf("[%.2lf, %.2lf, %.2lf]", x, y, z);
}

void Vector::showln() {
    printf("[%.2lf, %.2lf, %.2lf]\n", x, y, z);
}

Vector operator+(Vector a, Vector b) {
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(Vector a) {
    return Vector(-a.x, -a.y, -a.z);
}

Vector operator-(Vector a, Vector b) {
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(Vector a, Vector b) {
    return CROSS(a, b);
}

Vector operator*(double a, Vector b) {
    return Vector(a * b.x, a * b.y, a * b.z);
}

Vector operator*(Vector b, double a) {
    return Vector(a * b.x, a * b.y, a * b.z);
}

Vector operator/(Vector b, double a) {
    return Vector(b.x / a, b.y / a, b.z / a);
}

double DOT(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector CROSS(Vector a, Vector b) {
    return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double BOX(Vector a, Vector b, Vector c) {
    return DOT(a, CROSS(b, c));
}

double projectLength(Vector proj, Vector on) {
    on.norm();
    return DOT(on, proj);
}

Vector projectVector(Vector proj, Vector on) {
    on.norm();
    return on * projectLength(proj, on);
}

Vector rotateVector(Vector rotatee, Vector axis, double angle) {

    angle = angle * PI / 180.;
    axis.norm();
    if (axis.isZero()) return rotatee;
    Vector normal = (axis * rotatee).unit();
    if (normal.isZero()) return rotatee;
    Vector mid = (normal * axis).unit();
    if (mid.isZero()) return rotatee;
    double r = projectLength(rotatee, mid);
    return (r * mid * cos(angle) + r * normal * sin(angle) + projectVector(rotatee, axis));
}

double abs(double a) {
    return a < 0 ? -a : a;
}

double getAngle(Vector a, Vector b) {

    Vector ta = a;
    Vector tb = b;
    ta.norm();
    tb.norm();

    return atan2(DOT((ta * tb).unit(), a * b), DOT(a, b));


    double divisor = a.mag() * b.mag();
    double sinVal = asin(CROSS(a, b).mag() / divisor);
    double cosVal = acos(DOT(a, b) / divisor);
    return cosVal;
    if (cosVal <= PI / 2) {
        return sinVal;
    } else if (sinVal > 0) {
        return cosVal;
    } else {
        return -cosVal;
    }
}