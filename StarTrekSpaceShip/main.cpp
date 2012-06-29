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
#include "TrashAPkg.h"
#include "TrashBPkg.h"
#include "TrashCPkg.h"
#include "RoadPkg.h"
#include "BridgeBeamPkg.h"
#include "Water.h"

#include "Camera.h"

#include "Texture.h"
#include "Pillar.h"



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
Water water(400,400);
SpaceShip spaceShip(10, 10, 0);

void resize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, w / (float) h, 1.0f, 1000.0f);

    //glOrtho(0, 0, 1000, 1000, 1.0f, 1000.0f);
}

void LoadTexture() {
    
    TrashA::texid = Texture::LoadMyBitmap("D:\\trashA.bmp");
    TrashB::texid = Texture::LoadMyBitmap("D:\\trashB.bmp");
    TrashC::texid = TrashA::texid;
    Road::roadTexId = Texture::LoadMyBitmap("D:\\road.bmp");
    Road::railTexId = Texture::LoadMyBitmap("D:\\rail.bmp");
    BridgeBeam::texid = Texture::LoadMyBitmap("D:\\beam.bmp");
    Water::texid = Texture::LoadMyBitmap("D:\\water.bmp");
    Pillar::baseTexId = Texture::LoadMyBitmap("D:\\pillerBaseTexture.bmp");
    
}

void handlekey() {

    /*  Start -- Spaceship step*/
    if (keys['w']) {
	spaceShip.pitchClockWise();
	//	trashA1.pitchClockWise();
    }
    if (keys['s']) {
	spaceShip.pitchCounterClockWise();
	//	trashA1.pitchCounterClockWise();
    }
    if (keys['a']) {
	spaceShip.roleLeft();
	//	trashA1.roleLeft();
    }
    if (keys['d']) {
	spaceShip.roleRight();
	//	trashA1.roleRight();
    }
    if (keys['q']) {
	spaceShip.yowDown();
	//	trashA1.yowDown();
    }
    if (keys['e']) {
	spaceShip.yowUp();	
	//	trashA1.yowUp();
    }
    /* END -- Spaceship Step */



    /*  Start -- Spaceship Rotation*/
    if (keys['i']) {
	spaceShip.stepDown();
	//	trashA1.stepDown();
    }
    if (keys['k']) {
	spaceShip.stepUp();
	//	trashA1.stepUp();
    }
    if (keys['j']) {
	spaceShip.stepLeft();
	//	trashA1.stepLeft();
    }
    if (keys['l']) {
	spaceShip.stepRight();
	//	trashA1.stepRight();
    }
    if (keys['u']) {
	spaceShip.stepForward();
	//	trashA1.stepForward();
    }
    if (keys['o']) {
	spaceShip.stepBackward();
	//	trashA1.stepBackward();	
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

    if (keys['0']) {
	camera.print();
	//	trashA1.print();	
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

void animate() {

    handlekey();
    glutPostRedisplay(); //Redraw the view port
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

void TestGuassian(){
    glPushMatrix();
    {
	glTranslatef(0,0,15);    
	glScalef(5,0,5);
	for (double x = -40.0; x < 40; x+=.01) {
	    double y = Gauss(x);
	    glBegin(GL_LINES);
	    {	    	    
		glVertex3f(x,10,y);
		glVertex3f(x,10,y+.5);	    
	    }
	    glEnd();
	}
    }
    glPopMatrix();

    
    glTranslatef(0,0,5);    
    glScalef(5,0,0);
    for (double i = 0; i < 180; i+=.1) {

	double x = 40*cos(D2R(i));
	double y = 20*sin(D2R(i));
	glBegin(GL_LINE_STRIP);
	{	    
	    glVertex3f(x,0,y);
	    glVertex3f(x,0,y+.5);	    
	}
	glEnd();
    }
}

void display(void) {
    /* clear window */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    //Exposing camera
    camera.expose();

    //Drawing world details
    //world.drawGrid();    
    world.drawAxis();
    
    water.paintUIElement();
    
    
    //Drawing spaceship details
    //spaceShip.paintUIElement();
//    glRotatef(90, 0, 0, 1);
//    glTranslatef(0, -60, 0);

//    world.drawBridgeTrashA();
    
    

    glColor3f(1,0.5,.8);
    
//    TrashB trashB(40.0,40.0,3.0,30.0);
//    trashB.paintUIElement();
    
//    TrashC trashC(20,60);
//    trashC.paintUIElement();
    
    
//    RoadPkg roadPkg(130,300);
//    roadPkg.paintUIElement();

//    TrashBPkg trashBPkg(40,120);
//    trashBPkg.paintUIElement();
    
//    TrashCPkg trashCPkg(20,200);
//    trashCPkg.paintUIElement();
    
//    glRotatef(90,1,0,0);
//    
//    BridgeBeam bridgeBeam(21,100);
//    bridgeBeam.paintUIElement();
    
//    BridgeBeamPkg bridgeBeamPkg(21,400);
//    bridgeBeamPkg.paintUIElement();
    
    
    Pillar pillar;
    pillar.paintUIElement();
    
    
    glutSwapBuffers();

}

void init() {


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEPTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);    
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_SMOOTH);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 1.0f, 1.0f, 1000.0f);

    glutIgnoreKeyRepeat(1);
    memset(keys, 0, sizeof (keys));

    LoadTexture();


}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Hell Gate");



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