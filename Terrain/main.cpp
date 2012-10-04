
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

#include "Camera.h"
#include "Light.h"
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

SkyBox skyBox(resource.worldWidth, resource.worldWidth);
Water water(resource.worldWidth, resource.worldWidth);

Camera camera(Vector(20, -150, 50), Vector(10, 100, -20), Vector(0, 0, 1));
//Camera camera(Vector(-8.57, -382.55, 89.60), Vector(8.57, 382.55, -89.60), Vector(767.51, 34275.08, 146421.71));
World world;
Light light(0, 0, 1, 800, 800, 2);

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
        light.step();
    }


    if (keys['w']) {
        camera.stepForward();
    }
    if (keys['s']) {
        camera.stepBackward();
    }
    if (keys['a']) {
        camera.pitchPlus();
    }
    if (keys['d']) {
        camera.pitchMinus();
    }
    if (keys['q']) {
        camera.stepUp();
    }
    if (keys['e']) {
        camera.stepDown();
    }


    if (keys['i']) {
        camera.yowUp();
    }
    if (keys['k']) {
        camera.yowDown();
    }
    if (keys['j']) {
        camera.stepRight();
    }
    if (keys['l']) {
        camera.stepLeft();
    }
    if (keys['u']) {
        camera.rolePlus();
    }
    if (keys['o']) {
        camera.roleMinus();
    }


    if (keys['R']) {
        camera.reset();
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

        camera.print();
    }

    if (keys['/']) {

    }

    if (keys[VIRTUAL_KEY_DOWN]) {
        camera.circularDown();
    }
    if (keys[VIRTUAL_KEY_UP]) {
        camera.circularUp();
    }

    if (keys[VIRTUAL_KEY_RIGHT]) {
        camera.circularLeft();
    }

    if (keys[VIRTUAL_KEY_LEFT]) {
        camera.circularRight();
    }

    if (keys[VIRTUAL_KEY_PAGE_UP]) {
        light.step();
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

void display(void) {
    /* clear window */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    handlekey();

    //Exposing camera
    camera.expose();

    //Light
    light.expose();

    //World
    world.render();

    glColor3f(1, 1, 1);

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


    glutMainLoop();

}


//GLuint cubelist; //we are going to hold our list in here
//
////create the cube display list
//
//void createcube(void) {
//    cubelist = glGenLists(1); //set the cube list to Generate a List
//    glNewList(cubelist, GL_COMPILE); //compile the new list
//    glPushMatrix();
//    glutSolidCube(1); //draw the cube
//    glPopMatrix();
//    glEndList(); //end the list
//}
//
//void init(void) {
//    glEnable(GL_DEPTH_TEST); //enable the depth testing
//    glEnable(GL_LIGHTING); //enable the lighting
//    glEnable(GL_LIGHT0); //enable LIGHT0, our Diffuse Light
//    glShadeModel(GL_SMOOTH); //set the shader to smooth shader
//
//    createcube(); //call the command to create the cube
//}
//
//void display(void) {
//    glClearColor(0.0, 0.0, 0.0, 1.0); //clear the screen to black
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    //clear the color buffer and the depth buffer
//    glLoadIdentity();
//    glTranslatef(0, 0, -5);
//    glCallList(cubelist); //call the cube list
//    glutSwapBuffers(); //swap the buffers
//}
//
//void reshape(int w, int h) {
//    glViewport(0, 0, (GLsizei) w, (GLsizei) h); //set the viewport to the current window specifications
//    glMatrixMode(GL_PROJECTION); //set the matrix to projection
//
//    glLoadIdentity();
//    gluPerspective(60, (GLfloat) w / (GLfloat) h, 1.0, 100.0); //set the perspective (angle of sight, width, height, , depth    )
//    glMatrixMode(GL_MODELVIEW); //set the matrix back to model
//
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    if (key == 27) {
//        glutLeaveGameMode(); //set the resolution how it was
//        exit(0); //quit the program
//    }
//}
//

//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); //set     the display to Double buffer, with depth
//    glutGameModeString("1366x768:32@75"); //the settings for fullscreen mode
//    glutEnterGameMode(); //set glut to fullscreen using the settings in the line above
//    init(); //call the init function
//    glutDisplayFunc(display); //use the display function to draw everything
//    glutIdleFunc(display); //update any variables in display, display can be changed to anyhing, as long as you move the variables to be updated, in this case, angle++;
//    glutReshapeFunc(reshape); //reshape the window accordingly
//
//    glutKeyboardFunc(keyboardListener); //check the keyboard
//    glutMainLoop(); //call the main loop
//    return 0;
//}