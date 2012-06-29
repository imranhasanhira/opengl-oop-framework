#include "UIElement.h"

#include <windows.h>
#include <GL/glut.h>

void UIElement::paint() {
}

UIElement::UIElement(double posX, double posY, double posZ) {
    position = Vector(posX, posY, posZ);
    forward = Vector(0, 1, 0);
    up = Vector(0, 0, 1);
}

UIElement::UIElement(Vector tPosition, Vector tForward, Vector tUp) {
    position = tPosition;
    forward = tForward;
    Vector along = CROSS(tForward, tUp);
    up = along * tForward;

}

int UIElement::getChildsCount() {
    return childs.size();
}

UIElement UIElement::getChildAt(int index) {
    return childs[index];
}

int UIElement::addChild(UIElement child) {
    childs.push_back(child);
    return childs.size() - 1;
}

void UIElement::removeChild(int index) {
    childs.erase(childs.begin() + index);
}

void UIElement::render() {
    glPushMatrix();
    {
        glTranslated(position.x, position.y, position.z);

        paint();
        for (int i = 0; i < childs.size(); i++) {
            childs[i].paint();
        }
    }
    glPopMatrix();


    /*glBegin(GL_LINES);
        {
            //UP magenta
            glColor3f(1, 0, 1);
            glVertex3f(0, 0, 0);
            glVertex3f(CO(up.scale(30)));

            //forward yellow
            glColor3f(1, 1, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(CO(forward.scale(30)));

            Vector along = forward * up;
            glColor3f(0, 1, 1);
            glVertex3f(0, 0, 0);
            glVertex3f(CO(along.scale(30)));

        }
        glEnd();*/
}

