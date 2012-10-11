/* 
 * File:   Texture.cpp
 * Author: Ibrahim
 * 
 * Created on June 27, 2012, 4:00 PM
 */

#include "Texture.h"


int Texture::num_texture = -1;
GLuint Texture::ROCK_TILE = -1;

Texture::Texture() {

}

Texture::~Texture() {

}

int Texture::LoadMyBitmap(char* filename) {
    int i, j = 0;
    FILE *l_file;
    unsigned char *l_texture;
    BITMAPFILEHEADER fileheader;
    BITMAPINFOHEADER infoheader;
    RGBTRIPLE rgb;
    num_texture++;
    if ((l_file = fopen(filename, "rb")) == NULL) {
        printf("Exiting");
        exit(0);
        return (-1);
    }
    fread(&fileheader, sizeof (fileheader), 1, l_file);
    fseek(l_file, sizeof (fileheader), SEEK_SET);
    fseek(l_file, sizeof (fileheader), SEEK_SET);
    fread(&infoheader, sizeof (infoheader), 1, l_file);
    l_texture = (unsigned char *) malloc(infoheader.biWidth * infoheader.biHeight * 4);
    memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);
    for (i = 0; i < infoheader.biWidth * infoheader.biHeight; i++) {
        fread(&rgb, sizeof (rgb), 1, l_file);
        l_texture[j + 0] = rgb.rgbtRed;
        l_texture[j + 1] = rgb.rgbtGreen;
        l_texture[j + 2] = rgb.rgbtBlue;
        l_texture[j + 3] = 255;
        j += 4;
    }
    fclose(l_file);
    glBindTexture(GL_TEXTURE_2D, num_texture);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
            l_texture);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 44, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
    free(l_texture);
    return (num_texture);
}

ImageHeader* Texture::LoadBitmapPixelData(char* filename) {
    int i, j = 0;
    FILE *l_file;
    BITMAPFILEHEADER fileheader;
    BITMAPINFOHEADER infoheader;
    RGBTRIPLE rgb;
    num_texture++;
    if ((l_file = fopen(filename, "rb")) == NULL) {
        printf("Exiting");
        exit(0);
        return NULL;
    }
    fread(&fileheader, sizeof (fileheader), 1, l_file);
    fseek(l_file, sizeof (fileheader), SEEK_SET);
    fseek(l_file, sizeof (fileheader), SEEK_SET);
    fread(&infoheader, sizeof (infoheader), 1, l_file);

    ImageHeader* imageHeader = ImageHeader::getNewInstance(infoheader.biWidth, infoheader.biHeight);
    //    exit(0);
    for (i = 0; i < infoheader.biWidth; i++) {
        for (j = 0; j < infoheader.biHeight; j++) {
            fread(&rgb, sizeof (rgb), 1, l_file);
            imageHeader->pixels[i][j] = ColorRGBA(rgb);
        }
    }
    fclose(l_file);
    return imageHeader;
}
