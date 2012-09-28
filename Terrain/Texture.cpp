/* 
 * File:   Texture.cpp
 * Author: Ibrahim
 * 
 * Created on June 27, 2012, 4:00 PM
 */

#include "Texture.h"

int Texture::num_texture = -1;

GLuint Texture::TEX_ASH_BRICK = -1;
GLuint Texture::TEX_PILLER_BIG = -1;
GLuint Texture::TEX_PILLER_SMALL = -1;
GLuint Texture::TEX_PILLER_S01 = -1;
GLuint Texture::TEX_PILLER_S02 = -1;
GLuint Texture::TEX_PILLER_S03 = -1;
GLuint Texture::TEX_PILLER_S04 = -1;
GLuint Texture::TEX_PILLER_S06 = -1;

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
    l_texture = (byte*) malloc(infoheader.biWidth * infoheader.biHeight * 4);
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

void Texture::initTextures() {
    TEX_PILLER_SMALL = Texture::LoadMyBitmap("images/pillar_b.bmp");
    TEX_PILLER_BIG = Texture::LoadMyBitmap("images/pillar_base.bmp");
    TEX_ASH_BRICK = Texture::LoadMyBitmap("images/brick.bmp");
    TEX_PILLER_S01 = Texture::LoadMyBitmap("images/s01.bmp");
    TEX_PILLER_S02 = Texture::LoadMyBitmap("images/s02.bmp");
    TEX_PILLER_S03 = Texture::LoadMyBitmap("images/s03.bmp");
    TEX_PILLER_S04 = Texture::LoadMyBitmap("images/s04.bmp");
    TEX_PILLER_S06 = Texture::LoadMyBitmap("images/s06.bmp");


}