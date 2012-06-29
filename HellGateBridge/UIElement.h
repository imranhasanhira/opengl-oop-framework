/* 
 * File:   UIElement.h
 * Author: Md Imran Hasan
 *
 * Created on June 1, 2012, 8:51 PM
 */

#ifndef UIELEMENT_H
#define	UIELEMENT_H


#include <vector>
#include "Vector.h"
#include "Element.h"
#include "drawing.h"
typedef Vector Point3f;

using namespace std;

class UIElement : public Element {
private:
    vector<UIElement> childs;

protected:
    virtual void paint();

public:
    UIElement(double posX, double posY, double posZ);
    UIElement(Vector tPosition = Vector(0, 0, 0), Vector tForward = Vector(0, 1, 0), Vector tUp = Vector(0, 0, 1));
    int getChildsCount();
    UIElement getChildAt(int index);
    int addChild(UIElement child);
    void removeChild(int index);
    void render();

};

#endif	/* UIELEMENT_H */

