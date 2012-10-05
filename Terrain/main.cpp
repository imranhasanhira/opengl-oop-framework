
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
using namespace std;

#include "Resource.h"
#include "Logger.h"
#include "World.h"

#include "camera.h"
#include "light.h"
#include "Texture.h"

#include "macros.h"

#include "SkyBox.h"
#include "Water.h"




bool keys[255] = {false};
const int VIRTUAL_KEY_UP = 150;
const int VIRTUAL_KEY_DOWN = 151;
const int VIRTUAL_KEY_LEFT = 152;
const int VIRTUAL_KEY_RIGHT = 153;
const int VIRTUAL_KEY_PAGE_UP = 154;
const int VIRTUAL_KEY_PAGE_DOWN = 155;

Resource resource;
Logger logger;

SkyBox *skyBox;
Water *water;
Camera *camera;
//Camera camera(Vector(-8.57, -382.55, 89.60), Vector(8.57, 382.55, -89.60), Vector(767.51, 34275.08, 146421.71));
World *world;
Light *light;
double fps;
int previousTime, frameCount;

void LoadTexture() {

    SkyBox::skyUpId = Texture::LoadMyBitmap("images/skyup1.bmp");
    SkyBox::skyBackId = Texture::LoadMyBitmap("images/skyback1.bmp");
    SkyBox::skyLeftId = Texture::LoadMyBitmap("images/leftsky.bmp");
    SkyBox::skyFrontId = Texture::LoadMyBitmap("images/frontsky.bmp");
    SkyBox::skyRightId = Texture::LoadMyBitmap("images/rightsky.bmp");

    Water::texid = Texture::LoadMyBitmap("images/water.bmp");
    Texture::ROCK_TILE = Texture::LoadMyBitmap("images/rock.bmp");

}

void handlekey() {


    //step light
    if (keys['9']) {
        light->stepPlus();
    }

    if (keys['0']) {
        light->stepMinus();
    }


    if (keys['w']) {
        camera->stepForward();
    }
    if (keys['s']) {
        camera->stepBackward();
    }
    if (keys['a']) {
        camera->pitchPlus();
    }
    if (keys['d']) {
        camera->pitchMinus();
    }
    if (keys['q']) {
        camera->stepUp();
    }
    if (keys['e']) {
        camera->stepDown();
    }


    if (keys['i']) {
        camera->yowUp();
    }
    if (keys['k']) {
        camera->yowDown();
    }
    if (keys['j']) {
        camera->stepRight();
    }
    if (keys['l']) {
        camera->stepLeft();
    }
    if (keys['u']) {
        camera->rolePlus();
    }
    if (keys['o']) {
        camera->roleMinus();
    }


    if (keys['R']) {
        camera->reset();
    }


    if (keys['f']) {

    }
    if (keys['h']) {

    }
    if (keys['t']) {

    }
    if (keys['g']) {

    }
    if (keys['r']) {

    }
    if (keys['y']) {

    }




    if (keys['1']) {

        camera->print();
    }

    if (keys['/']) {

    }

    if (keys[VIRTUAL_KEY_DOWN]) {
        camera->circularDown();
        //        printf("DOWN\n");
    }
    if (keys[VIRTUAL_KEY_UP]) {
        camera->circularUp();
        //        printf("UP\n");
    }

    if (keys[VIRTUAL_KEY_RIGHT]) {
        camera->circularLeft();
        //        printf("right\n");
    }

    if (keys[VIRTUAL_KEY_LEFT]) {
        camera->circularRight();
        //        printf("left\n");
    }

    if (keys[VIRTUAL_KEY_PAGE_UP]) {
        light->stepPlus();
    }
    if (keys[VIRTUAL_KEY_PAGE_DOWN]) {
        light->stepMinus();
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
    //cout << "Drag : " << x << ", " << y << endl;
}

void mousePassiveMotionListener(int x, int y) {
    //cout << "Move : " << x << ", " << y << endl;
}

void TestGuassian() {
    glPushMatrix();
    {
        glTranslatef(0, 0, 15);
        glScalef(5, 0, 5);
        for (double x = -40.0; x < 40; x += .01) {
            double y = Gauss(x);
            glBegin(GL_LINES);
            {
                glVertex3f(x, 10, y);
                glVertex3f(x, 10, y + .5);
            }
            glEnd();
        }
    }
    glPopMatrix();


    glTranslatef(0, 0, 5);
    glScalef(5, 0, 0);
    for (double i = 0; i < 180; i += .1) {
        double x = 40 * cos(D2R(i));
        double y = 20 * sin(D2R(i));
        glBegin(GL_LINE_STRIP);
        {
            glVertex3f(x, 0, y);
            glVertex3f(x, 0, y + .5);
        }
        glEnd();
    }
}

void animate() {
    glutPostRedisplay(); //Redraw the view port
}

//-------------------------------------------------------------------------
// Calculates the frames per second
//-------------------------------------------------------------------------

void calculateFPS() {
    //  Increase frame count
    frameCount++;

    //  Get the number of milliseconds since glutInit called
    //  (or first call to glutGet(GLUT ELAPSED TIME)).
    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    //  Calculate time passed
    int timeInterval = currentTime - previousTime;

    if (timeInterval > 1000) {
        //  calculate the number of frames per second
        fps = frameCount / (timeInterval / 1000.0f);

        //  Set time
        previousTime = currentTime;

        //  Reset frame count
        frameCount = 0;
    }
}

void RenderString(float x, float y, void *font, const char* string) {
    char *c;

    glColor3f(1, 0, 0);
    glRasterPos2f(x, y);
    for (int i = 0; string[i] != 0; i++) {
        glColor3f(1, 0, 0);
        glutBitmapCharacter(font, string[i]);
    }
}

void display(void) {

    //calculateFPS();
    //printf("%f\n", fps);
    //RenderString(100.0f, 100.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Hello");

    /* clear window */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    handlekey();

    //Exposing camera
    camera->expose();

    //Light
    light->expose();

    //World
    world->render();


    //Skybox & Water
    //    skyBox.render();
    //    glTranslatef(0, 0, -1000);
    //    water.render();


    glutSwapBuffers();

}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //    gluPerspective(50, w / (float) h, 1.0f, 1000.0f);
    gluPerspective(70, w / (float) h, 0.1f, 100000.0f);

    //glOrtho(0, 0, 1000, 1000, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW); //set the matrix back to model
}

void init() {

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH);

    glEnable(GL_SMOOTH);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice Perspective Correction

    glEnable(GL_NORMALIZE);

    //Lighting
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 1.0f, 0.1f, 100000.0f);

    glutIgnoreKeyRepeat(1);

    memset(keys, 0, sizeof (keys));
    LoadTexture();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

    //    glutInitWindowSize(800, 600);
    //    glutInitWindowPosition(50, 0);
    //    glutCreateWindow("Hell Gate");

    glutGameModeString("1366x768:32@75"); //the settings for fullscreen mode
    glutEnterGameMode(); //set glut to fullscreen using the settings in the line above

    init(); //call the init function


    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutReshapeFunc(reshape);


    //ADD keyboard listeners:
    glutKeyboardFunc(keyboardListener);
    glutKeyboardUpFunc(keyboardUpListener);
    glutSpecialFunc(specialKeyListener);
    glutSpecialUpFunc(specialKeyUpListener);
    glutMotionFunc(mouseMotionListener);
    glutPassiveMotionFunc(mousePassiveMotionListener);

    //ADD mouse listeners:
    glutMouseFunc(mouseListener);

    skyBox = new SkyBox(resource.worldWidth, resource.worldWidth);
    water = new Water(resource.worldWidth, resource.worldWidth);
    camera = new Camera(Vector(-20, 750, 175), Vector(13.57, -392.76, 1.17), Vector(-0.00, 0.00, 1.00));
    light = new Light(0, 0, 1, 1000, 1000, 2);

    world = new World();

    glutMainLoop();

}