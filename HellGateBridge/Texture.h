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
private:
    static int num_texture;
    
};

#endif	/* Texture_H */

