/* 
 * File:   World.h
 * Author: Md Imran Hasan
 *
 * Created on May 31, 2012, 11:59 PM
 */

#ifndef WORLD_H
#define	WORLD_H

#include <GL/glut.h>
#include "TrashAPkg.h"

class World {
public:


    World() {
	
    }

    void drawAxis() {
	glBegin(GL_LINES);
	{

	    // X'O line
	    glColor3f(1, 1, 0);
	    glVertex3f(-100, 0, 0);
	    glVertex3f(0, 0, 0);



	    //OX line
	    glColor3f(1.0, 0, 0);
	    glVertex3f(0, 0, 0);
	    glVertex3f(100, 0, 0);


	    //Y'O line
	    glColor3f(1, 0.5, 0);
	    glVertex3f(0, -100, 0);
	    glVertex3f(0, 0, 0);

	    //OY line
	    glColor3f(0, 1.0, 0);
	    glVertex3f(0, 0, 0);
	    glVertex3f(0, 100, 0);

	    //Z'O line
	    glColor3f(0, 1, 0.5);
	    glVertex3f(0, 0, -100);
	    glVertex3f(0, 0, 0);

	    //OZ line
	    glColor3f(0, 0, 1.0);
	    glVertex3f(0, 0, 0);
	    glVertex3f(0, 0, 100);

	}
	glEnd();
    }

    void drawGrid() {
	glBegin(GL_LINES);
	{
	    int i;

	    for (i = -100; i < 100; i += 10) {
		glColor3f(0.4, 0, 0);
		glVertex3f(-100, i, 0);
		glVertex3f(100, i, 0);

		glColor3f(0, 0.4, 0);
		glVertex3f(i, -100, 0);
		glVertex3f(i, 100, 0);

	    }
	}
	glEnd();
    }

    void drawBridgeTrashA() {

	TrashAPkg trashAPkg(20, 120, 100);
	trashAPkg.paintUIElement();

	glTranslatef(0, 100, 0);

	TrashAPkg trashAPkg1(20, 120, 100);
	trashAPkg1.paintUIElement();
    }

   
    
    
private:

};

#endif	/* WORLD_H */

