/* 
 * File:   Texture.h
 * Author: Ibrahim
 *
 * Created on June 27, 2012, 4:00 PM
 */
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>  

#ifndef Texture_H
#define	Texture_H

class Texture {
public:
    Texture();
    static int LoadMyBitmap(char* filename);
    virtual ~Texture();
    char* filename;

    static GLuint TEX_ASH_BRICK;
    static GLuint TEX_PILLER_SMALL;
    static GLuint TEX_PILLER_BIG;
    static GLuint TEX_PILLER_S01;
    static GLuint TEX_PILLER_S02;
    static GLuint TEX_PILLER_S03;
    static GLuint TEX_PILLER_S04;
    static GLuint TEX_PILLER_S06;

    static void initTextures();


private:
    static int num_texture;

};

#endif	/* Texture_H */

