/* 
 * File:   main.cpp
 * Author: Md Imran Hasan
 *
 * Created on May 17, 2012, 12:44 PM
 */

#include "cmath"
#include <windows.h>
#include <GL/glut.h>         /* glut.h includes gl.h and glu.h*/

#include <stdio.h>
#include <iostream>

#include "Resource.h"
#include "Logger.h"
#include "World.h"
#include "SpaceShip.h"
#include "Camera.h"

using namespace std;


bool keys[255] = {false};
const int VIRTUAL_KEY_UP = 150;
const int VIRTUAL_KEY_DOWN = 151;
const int VIRTUAL_KEY_LEFT = 152;
const int VIRTUAL_KEY_RIGHT = 153;
const int VIRTUAL_KEY_PAGE_UP = 154;
const int VIRTUAL_KEY_PAGE_DOWN = 155;

Resource resource;
Logger logger;

World world;
Camera camera;
SpaceShip spaceShip(10, 10, 0);

void resize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, w / (float) h, 1.0f, 1000.0f);

    //glOrtho(0, 0, 1000, 1000, 1.0f, 1000.0f);
}

void animate() {


    glutPostRedisplay(); //Redraw the view port
}

void handlekey() {

    /*  Start -- Spaceship step*/
    if (keys['w']) {
        spaceShip.pitchClockWise();
    }
    if (keys['s']) {
        spaceShip.pitchCounterClockWise();
    }
    if (keys['a']) {
        spaceShip.roleLeft();
    }
    if (keys['d']) {
        spaceShip.roleRight();
    }
    if (keys['q']) {
        spaceShip.yowDown();
    }
    if (keys['e']) {
        spaceShip.yowUp();
    }
    /* END -- Spaceship Step */



    /*  Start -- Spaceship Rotation*/
    if (keys['i']) {
        spaceShip.stepDown();
    }
    if (keys['k']) {
        spaceShip.stepUp();
    }
    if (keys['j']) {
        spaceShip.stepLeft();
    }
    if (keys['l']) {
        spaceShip.stepRight();
    }
    if (keys['u']) {
        spaceShip.stepForward();
    }
    if (keys['o']) {
        spaceShip.stepBackward();
    }
    /* END -- Spaceship Rotation */


    if (keys['R']) {
        camera.reset();
    }

    /* Start -- Camera Step */
    if (keys['f']) {
        camera.stepRight();
    }

    if (keys['h']) {
        camera.stepLeft();
    }

    if (keys['t']) {
        camera.stepForward();
    }
    if (keys['g']) {
        camera.stepBackward();
    }

    if (keys['r']) {
        camera.stepUp();
    }

    if (keys['y']) {
        camera.stepDown();
    }
    /*
     *   END -- Camera Step */

    /* Start -- Camera Rotation 
     */
    if (keys['1']) {
        camera.pitchClockWise();
    }

    if (keys['/']) {
        camera.pitchCounterClockWise();
    }

    if (keys[VIRTUAL_KEY_DOWN]) {
        camera.yowDown();
    }
    if (keys[VIRTUAL_KEY_UP]) {
        camera.yowUp();
    }

    if (keys[VIRTUAL_KEY_RIGHT]) {
        camera.roleRight();
    }

    if (keys[VIRTUAL_KEY_LEFT]) {
        camera.roleLeft();
    }
    /*
     *  END -- Camera Rotation */

    if (keys[VIRTUAL_KEY_PAGE_UP]) {

    }
    if (keys[VIRTUAL_KEY_PAGE_DOWN]) {

    }


    if (keys[27]) {
        exit(0);
    }
}

void keyboardListener(unsigned char key, int x, int y) {

    //cout << "KEY PRESSED : (" << key << "(" << (int) key << "), " << x << ", " << y << ")" << endl;
    keys[key] = true;

}

void specialKeyListener(int key, int x, int y) {
    //cout << "SPECIAL_KEY PRESSED : (" << key << "(" << (int) key << "), " << x << ", " << y << ")" << endl;

    switch (key) {
        case GLUT_KEY_DOWN: //down arrow key
            keys[VIRTUAL_KEY_DOWN] = true;
            break;

        case GLUT_KEY_UP: // up arrow key
            keys[VIRTUAL_KEY_UP] = true;
            break;

        case GLUT_KEY_RIGHT:
            keys[VIRTUAL_KEY_RIGHT] = true;
            break;

        case GLUT_KEY_LEFT:
            keys[VIRTUAL_KEY_LEFT] = true;
            break;

        case GLUT_KEY_PAGE_UP:
            keys[VIRTUAL_KEY_PAGE_UP] = true;
            break;

        case GLUT_KEY_PAGE_DOWN:
            keys[VIRTUAL_KEY_PAGE_DOWN] = true;
            break;

        case GLUT_KEY_INSERT:

            break;

        case GLUT_KEY_HOME:
            break;
        case GLUT_KEY_END:
            break;

        default:
            break;
    }

}

void keyboardUpListener(unsigned char key, int x, int y) {
    keys[key] = false;
}

void specialKeyUpListener(int key, int x, int y) {
    //cout << "SPECIAL_KEY RELEASED: (" << key << "(" << (int) key << "), " << x << ", " << y << ")" << endl;

    switch (key) {
        case GLUT_KEY_DOWN: //down arrow key
            keys[VIRTUAL_KEY_DOWN] = false;
            break;

        case GLUT_KEY_UP: // up arrow key
            keys[VIRTUAL_KEY_UP] = false;
            break;

        case GLUT_KEY_RIGHT:
            keys[VIRTUAL_KEY_RIGHT] = false;
            break;

        case GLUT_KEY_LEFT:
            keys[VIRTUAL_KEY_LEFT] = false;
            break;

        case GLUT_KEY_PAGE_UP:
            keys[VIRTUAL_KEY_PAGE_UP] = false;
            break;

        case GLUT_KEY_PAGE_DOWN:
            keys[VIRTUAL_KEY_PAGE_DOWN] = false;
            break;

        case GLUT_KEY_INSERT:
            break;

        case GLUT_KEY_HOME:
            break;
        case GLUT_KEY_END:
            break;

        default:
            break;
    }

}

void mouseListener(int button, int state, int x, int y) { //x, y is the x-y of the screen (2D)

    switch (button) {
        case GLUT_LEFT_BUTTON:
            break;

        case GLUT_RIGHT_BUTTON:
            //........
            break;

        case GLUT_MIDDLE_BUTTON:
            //........
            break;

        default:
            break;
    }
}

void mouseMotionListener(int x, int y) {
    cout << "Drag : " << x << ", " << y << endl;
}

void mousePassiveMotionListener(int x, int y) {
    cout << "Move : " << x << ", " << y << endl;
}

void display(void) {
    /* clear window */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    handlekey();

    //Exposing camera
    camera.expose();

    //Drawing world details
    world.drawGrid();
    world.drawAxis();

    //Drawing spaceship details
    spaceShip.paintUIElement();




    glutSwapBuffers();

}

void init() {


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_SMOOTH);
    glEnable(GL_BLEND);
    //glEnable(GL_LINE_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 1.0f, 1.0f, 1000.0f);

    glutIgnoreKeyRepeat(1);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("simple");

    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutReshapeFunc(resize);


    //ADD keyboard listeners:
    glutKeyboardFunc(keyboardListener);
    glutKeyboardUpFunc(keyboardUpListener);
    glutSpecialFunc(specialKeyListener);
    glutSpecialUpFunc(specialKeyUpListener);
    glutMotionFunc(mouseMotionListener);
    glutPassiveMotionFunc(mousePassiveMotionListener);

    //ADD mouse listeners:
    glutMouseFunc(mouseListener);


    init();
    glutMainLoop();

}