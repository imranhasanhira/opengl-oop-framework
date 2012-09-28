#ifndef __VECTOR_IS_INCLUDED__
#define __VECTOR_IS_INCLUDED__

#include "macros.h"

#define CO(V)	V.x,V.y,V.z
#define S(a) a*a
#define PI 3.1415926535897932

struct Vector {
    double x, y, z;
    Vector();
    Vector(double, double, double);
    bool scan();
    double mag2();
    double mag();
    void norm();
    Vector unit();
    void show();
    void showln();
    bool isZero();

    Vector scale(double s);
};

Vector operator+(Vector a, Vector b);
Vector operator-(Vector a);
Vector operator-(Vector a, Vector b);
Vector operator*(Vector a, Vector b);
Vector operator*(double a, Vector b);
Vector operator*(Vector b, double a);
Vector operator/(Vector b, double a);

double DOT(Vector a, Vector b);
Vector CROSS(Vector a, Vector b);
double BOX(Vector a, Vector b, Vector c);


double projectLength(Vector proj, Vector on);
Vector projectVector(Vector proj, Vector on);
Vector rotateVector(Vector rotatee, Vector axis, double angle);
double getAngle(Vector a, Vector b);



#endif
