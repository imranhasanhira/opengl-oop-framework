#include <GL/glut.h>
#include "World.h"
#include "SkyBox.h"
#include "time.h"

World::World(Vector position, int worldWidth) {
    this->position = position;
    ImageHeader* heightMapImageHeader = Texture::LoadBitmapPixelData("images/hm6.bmp");
    //    heightMapImageHeader->pr();


    numberOfTextureImage = 5;
    ImageHeader** textures = new ImageHeader*[numberOfTextureImage];
    for (int i = 0; i < numberOfTextureImage; i++) {
        string name("images/hm_tex");
        char *c;
        *c = i + '0';
        name.append(c).append(".bmp");
        textures[i] = Texture::LoadBitmapPixelData(name.c_str());
    }


    terrainWidth = heightMapImageHeader->width;
    terrainHeight = heightMapImageHeader->height;
    terrainScale = worldWidth / (double) terrainWidth;

    terrainHeightMap = new double*[terrainWidth];
    terrainColorMap = new ColorRGBA*[terrainWidth];
    for (int i = 0; i < terrainWidth; i++) {
        terrainHeightMap[i] = new double[terrainHeight];
        terrainColorMap[i] = new ColorRGBA[terrainHeight];
    }
    for (int i = 0; i < terrainWidth; i++) {
        for (int j = 0; j < terrainHeight; j++) {
            ColorRGBA p = heightMapImageHeader->pixels[i][j];
            terrainHeightMap[i][j] = (p.r + p.g + p.b) / 3;
            terrainColorMap[i][j] = blend(textures, i, j);
            
            terrainHeightMap[i][j] *= 3;

        }
    }


    //NOrmal calculation
    normalValue = new Vector*[terrainWidth];
    for (int i = 0; i < terrainWidth; i++) {
        normalValue[i] = new Vector[terrainHeight];
    }
    for (int i = 0; i < terrainWidth; i++) {
        normalValue[i][0] = Vector(0, 0, 1);
        normalValue[i][terrainHeight - 1] = Vector(0, 0, 1);
    }
    for (int i = 0; i < terrainHeight; i++) {
        normalValue[0][i] = Vector(0, 0, 1);
        normalValue[terrainWidth - 1][i] = Vector(0, 0, 1);
    }
    for (int i = 1; i < terrainWidth - 1; i++) {
        for (int j = 1; j < terrainHeight - 1; j++) {
            Point3f up(i, j - 1, terrainHeightMap[i][j - 1]);
            Point3f right(i + 1, j, terrainHeightMap[i + 1][j]);
            Point3f down(i, j + 1, terrainHeightMap[i][j + 1]);
            Point3f left(i - 1, j, terrainHeightMap[i - 1][j]);
            Point3f self(i, j, terrainHeightMap[i][j]);
            Vector upRight = CROSS(right - self, up - self);
            Vector upLeft = CROSS(up - self, left - self);
            Vector downLeft = CROSS(left - self, down - self);
            Vector downRight = CROSS(down - self, right - self);
            normalValue[i][j] = -(upRight + upLeft + downLeft + downRight / 4);
        }
    }


    generateTerrain();
    srand(time(NULL));
    delete heightMapImageHeader;
    delete [] textures;

    //    printf("%d, %d \t %d, %d\n", );


}

World::~World() {
    for (int i = 0; i < terrainWidth; i++) {
        delete(terrainHeightMap[i]);
    }
    delete(terrainHeightMap);
}



ColorRGBA World::blend(ImageHeader** textures, int i, int j) {

    if (terrainHeightMap[i][j] < 50) {
        return textures[0]->pixels[i][j];

    } else if (terrainHeightMap[i][j] < 100) {
        return textures[1]->pixels[i][j];

    } else if (terrainHeightMap[i][j] < 150) {
        return textures[2]->pixels[i][j];

    } else if (terrainHeightMap[i][j] < 200) {
        return textures[3]->pixels[i][j];

    } else {
        return textures[4]->pixels[i][j];
    }

}

void World::generateTerrain() {
    terrainCallListId = 0;
    terrainCallListId = glGenLists(1);

    glNewList(terrainCallListId, GL_COMPILE);
    drawTerrain();
    glEndList();

    printf("list generated");
}

void World::drawTerrain() {

    glPushMatrix();

    //starting drawing terrain
    glTranslatef(-terrainWidth * terrainScale / 2.0, -terrainHeight * terrainScale / 2.0, 0);
    glBindTexture(GL_TEXTURE_2D, Texture::ROCK_TILE);

    //    glEnable(GL_TEXTURE_2D);
    {
        glColor3f(1, 1, 1);
        for (int i = 0; i < terrainHeight - 1; i++) {
            glBegin(GL_TRIANGLE_STRIP);
            {
                for (int j = 0; j < terrainWidth - 1; j++) {
                    glNormal3f(CO(normalValue[j][i]));
                    glTexCoord2f(0, 0);
                    glColor3f(CO(terrainColorMap[j][i].norm()));
                    glVertex3f(j * terrainScale, i * terrainScale, terrainHeightMap[j][i]);

                    glNormal3f(CO(normalValue[j][i + 1]));
                    glTexCoord2f(0, 1);
                    glColor3f(CO(terrainColorMap[j][i + 1].norm()));
                    glVertex3f(j * terrainScale, (i + 1) * terrainScale, terrainHeightMap[j][i + 1]);

                    glNormal3f(CO(normalValue[j + 1][i]));
                    glTexCoord2f(1, 0);
                    glColor3f(CO(terrainColorMap[j + 1][i].norm()));
                    glVertex3f((j + 1) * terrainScale, (i) * terrainScale, terrainHeightMap[j + 1][i ]);

                    glNormal3f(CO(normalValue[j + 1][i + 1]));
                    glTexCoord2f(1, 1);
                    glColor3f(CO(terrainColorMap[j + 1][i + 1].norm()));
                    glVertex3f((j + 1) * terrainScale, (i + 1) * terrainScale, terrainHeightMap[j + 1][i + 1]);

                }
            }
            glEnd();
        }

    }
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();

}

void World::paint() {
    //        drawAxis();
    //        drawGrid();
    //    glCallList(terrainCallListId);
    drawTerrain();


}