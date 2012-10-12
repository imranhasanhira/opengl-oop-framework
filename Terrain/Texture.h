/* 
 * File:   Texture.h
 * Author: Ibrahim
 *
 * Created on June 27, 2012, 4:00 PM
 */
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>  
#include <GL/glext.h>

#ifndef Texture_H
#define	Texture_H

class ColorRGBA {
public:
    BYTE r;
    BYTE g;
    BYTE b;
    BYTE a;

    ColorRGBA(BYTE r = 255, BYTE g = 255, BYTE b = 255, BYTE a = 255) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    ColorRGBA(RGBTRIPLE rgb) {
        *this = ColorRGBA(rgb.rgbtRed, rgb.rgbtGreen, rgb.rgbtBlue, 255);
    }

    void pr() {
        printf("(%d, %d, %d, %d) ", r, g, b, a);
    }
};

class ImageHeader {
public:
    int width;
    int height;
    ColorRGBA** pixels;

    ImageHeader(int width, int height, ColorRGBA** pixels) {
        this->width = width;
        this->height = height;
        this->pixels = pixels;
    }

    ~ImageHeader() {
        if (pixels != NULL) {
            for (int i = 0; i < width; i++) {
                delete(pixels[i]);
            }
            delete(pixels);
        }
    }

    static ImageHeader* getNewInstance(int width, int height) {
        ColorRGBA** pixels = new ColorRGBA*[width];
        for (int i = 0; i < width; i++) {
            pixels[i] = new ColorRGBA[height];
            memset(pixels[i], 0, height * sizeof (ColorRGBA));
        }
        return new ImageHeader(width, height, pixels);
    }

    void pr() {
        printf("Width: %d, Height: %d\n", width, height);
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                pixels[i ][j].pr();
            }
            printf("\n");
        }
        printf("\n");
    }

};

class Texture {
public:
    Texture();
    static int LoadMyBitmap(char* filename);
    static ImageHeader* LoadBitmapPixelData(char* filename);
    virtual ~Texture();

    static GLuint ROCK_TILE;

    static void initTextures();


private:
    static int num_texture;

};


#endif	/* Texture_H */

