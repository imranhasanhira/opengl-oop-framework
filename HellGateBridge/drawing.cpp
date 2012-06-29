
#include "drawing.h"

void Drawing::DrawGrid() {
    glColor3f(0.3, 0.3, 0.3); //grey
    glBegin(GL_LINES);
    {
	for (int i = -10; i <= 10; i++) {
	    if (i == 0)
		continue; //SKIP the MAIN axes
	    //lines parallel to Y-axis
	    glVertex3f(i * 10, -100, 0);
	    glVertex3f(i * 10, 100, 0);

	    //lines parallel to X-axis
	    glVertex3f(-100, i * 10, 0);
	    glVertex3f(100, i * 10, 0);
	}
    }
    glEnd();
}

void Drawing::DrawAxies() {

    glBegin(GL_LINES);
    {
	glColor3f(1, 1, 1); //100% white
	//Y axis
	glVertex3f(0, -150, 0); // intentionally extended to -150 to 150, no big deal
	glVertex3f(0, 150, 0);

	glColor3f(1, 1, 0); //100% white
	//X axis
	glVertex3f(-150, 0, 0);
	glVertex3f(150, 0, 0);

	glColor3f(0, 1, 1); //100% white
	//Z axis
	//glVertex3f(0, 0, -150);
	//glVertex3f(0, 0, 150);
    }
    glEnd();

    /*
    for(int i=-150;i<150;i+=5)
    {
	    glBegin(GL_LINES);{
		    glColor3f(1, 1, 0);	//100% white
		    glVertex3f(0, 0, i);	
		    glVertex3f(-5, 0, i);	
		    glVertex3f(5, 0, i);	
	    }glEnd();
    }*/
}

void Drawing::DrawCircle(GLdouble x_radius, GLdouble higiht) {
    Drawing::DrawElipse(x_radius, x_radius, higiht);
}

void Drawing::DrawElipse(GLdouble x_radius, GLdouble y_radius, GLdouble higiht) {
    glBegin(GL_POINTS);
    {
	for (int i = 0; i < 360; i++) {
	    glVertex3f(x_radius * cos(D2R(i)), y_radius * sin(D2R(i)), higiht);
	    glVertex3f(x_radius * cos(D2R(i + .01)), y_radius * sin(D2R(i + .01)), higiht);
	}
    }
    glEnd();
}

void Drawing::DrawCylinder(GLdouble bottom_radius, GLdouble top_radius, GLdouble cyl_higiht, GLint slices, GLint loops) {
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, bottom_radius, top_radius, cyl_higiht, slices, loops);
}

void Drawing::DrawDisk(GLdouble inner_radius, GLdouble outer_radius, GLint slices, GLint loops) {
    GLUquadric* quad = gluNewQuadric();
    gluDisk(quad, inner_radius, outer_radius, slices, loops);
}

void Drawing::DrawCone(GLdouble base, GLdouble height, GLint slices, GLint stacks) {
    glutSolidCone(base, height, slices, stacks);
}

void Drawing::DrawWireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks) {
    glutWireCone(base, height, slices, stacks);
}

void Drawing::DrawSolidSphare(GLdouble radius, GLint slices, GLint stacks) {
    glutSolidSphere(radius, slices, stacks);
}

void Drawing::DrawWireSphare(GLdouble radius, GLint slices, GLint stacks) {
    glutWireSphere(radius, slices, stacks);
}

void Drawing::DrawRectangle( GLdouble width,GLdouble height) {
    glBegin(GL_QUAD_STRIP);
    {	
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, width);
	glVertex3f(height, 0, 0);
	glVertex3f(height, 0, width);
    }
    glEnd();

}

void Drawing::DrawRectangleWithTexture( GLdouble width,GLdouble height) {
    glBegin(GL_QUAD_STRIP);
    {	
	glTexCoord2f(0, 0);glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);glVertex3f(0, 0, width);
	glTexCoord2f(0, 1);glVertex3f(height, 0, 0);
	glTexCoord2f(1, 1);glVertex3f(height, 0, width);
    }
    glEnd();

}

void Drawing::DrawRectangleWithTextureXY( GLdouble width,GLdouble height) {
    glBegin(GL_QUAD_STRIP);
    {	
	glTexCoord2f(0, 0);glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);glVertex3f(0, width, 0);
	glTexCoord2f(0, 1);glVertex3f(height, 0, 0);
	glTexCoord2f(1, 1);glVertex3f(height, width, 0);
    }
    glEnd();

}

void Drawing::DrawBoxWithTexture(GLdouble height, GLdouble width1, GLdouble width2) {
    glBegin(GL_QUAD_STRIP);
    {
	
	glTexCoord2f(0, 0);glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);glVertex3f(0, 0, height);
	glTexCoord2f(0, 1);glVertex3f(width1, 0, 0);
	glTexCoord2f(1, 1);glVertex3f(width1, 0, height);

	
	glTexCoord2f(0, 0);glVertex3f(width1, width2, 0);
	glTexCoord2f(1, 0);glVertex3f(width1, width2, height);
	glTexCoord2f(0, 1);glVertex3f(0, width2, 0);
	glTexCoord2f(1, 1);glVertex3f(0, width2, height);

	
	glTexCoord2f(0, 0);glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);glVertex3f(0, 0, height);
	glTexCoord2f(0, 1);glVertex3f(width1, 0, 0);
	glTexCoord2f(1, 1);glVertex3f(width1, 0, height);
    }
    glEnd();
}

void Drawing::DrawBox(GLdouble height, GLdouble width1, GLdouble width2) {
    glBegin(GL_QUAD_STRIP);
    {
	glColor3f(.2, .4, .5);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, height);
	glVertex3f(width1, 0, 0);
	glVertex3f(width1, 0, height);

	glColor3f(.2, .2, .2);
	glVertex3f(width1, width2, 0);
	glVertex3f(width1, width2, height);
	glVertex3f(0, width2, 0);
	glVertex3f(0, width2, height);

	glColor3f(.2, .4, .2);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, height);
	glVertex3f(width1, 0, 0);
	glVertex3f(width1, 0, height);
    }
    glEnd();
}

void Drawing::DrawRoundedBox(GLdouble radius, GLdouble height) {
    glBegin(GL_QUAD_STRIP);
    {
	for (int i = 0; i < 360; i++) {
	    glColor3f(.2, .5, .2);
	    GLdouble x = radius * cos(D2R(i));
	    GLdouble y = radius * sin(D2R(i));
	    glVertex3f(x, y, 0);
	    glVertex3f(x, y, height);
	    glVertex3f(x + .01, y, 0);
	    glVertex3f(x + .01, y, height);
	}
    }
    glEnd();
}

void Drawing::DrawTriangles(GLdouble baseWidth,GLdouble height){
    glBegin(GL_TRIANGLES);{	
	glVertex3f(baseWidth/2,0,height);
	glVertex3f(baseWidth,0,0);
	glVertex3f(0,0,0);
	
    }glEnd();
}

void Drawing::DrawFlipedTriangles(GLdouble baseWidth,GLdouble height){
    glBegin(GL_TRIANGLES);{	
	glVertex3f(0,0,height);
	glVertex3f(baseWidth,0,height);	
	glVertex3f(baseWidth/2,0,0);			
    }glEnd();
}