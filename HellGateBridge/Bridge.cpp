/* 
 * File:   Bridge.cpp
 * Author: Ibrahim
 * 
 * Created on June 29, 2012, 4:27 PM
 */

#include "Bridge.h"

Bridge::Bridge(double width, double length, double height) {
    this->width = width;
    this->length = length;
    this->height = height;
    this->trashAWidth = 22;
    this->trashBWidth = 22;
    this->trashCWidth = 22;

    this->beamWidth = 10;

    this->roadWidth = this->width / 2.5;

    this->bridgeLeftWidth = this->width / 4;

    this->trashARepeatDistance = 40;
    this->trashACount = 750 / this->trashARepeatDistance;
}

Bridge::Bridge(const Bridge& orig) {
}

Bridge::~Bridge() {
}

void Bridge::paint() {

    glPushMatrix();
    {
        glTranslatef(-400, -20, 4);



        // Road
        glPushMatrix();
        {

            glTranslatef(-1100, 0, 0);
            RoadPkg road(this->roadWidth, 4000);
            road.render();
        }
        glPopMatrix();
        glPushMatrix();
        {
            glTranslatef(300, 0, -2);
            //Left TrashC
            glPushMatrix();
            {
                int leftWidth = this->bridgeLeftWidth;

                glTranslatef(0, leftWidth / 5, -this->trashCWidth);

                TrashCPkg trashC(this->trashCWidth, 750);
                trashC.render();

                glTranslatef(0, 2 * leftWidth / 5, 0);

                TrashCPkg trashC1(this->trashCWidth, 750);
                trashC1.render();
            }
            glPopMatrix();

            //Right TrashC
            glPushMatrix();
            {
                int rightWidth = this->bridgeLeftWidth;
                //glTranslatef(0,-40 - this->roadWidth,-this->trashCWidth);
                glTranslatef(0, -2 * rightWidth / 5 - this->roadWidth, -this->trashCWidth);

                TrashCPkg trashC(this->trashCWidth, 750);
                trashC.render();

                glTranslatef(0, -2 * rightWidth / 5, 0);

                TrashCPkg trashC1(this->trashCWidth, 750);
                trashC1.render();
            }
            glPopMatrix();


            //Road SupportTrashA
            glPushMatrix();
            {
                glRotatef(-90, 0, 0, 1);
                glTranslatef(-this->bridgeLeftWidth + 20, 5, -1.5 * this->trashAWidth + 2);
                for (int i = 0; i<this->trashACount; i++) {

                    TrashA trashA(this->trashAWidth, this->width - 40);
                    trashA.render();
                    glTranslatef(0, this->trashARepeatDistance, 0);
                }

            }
            glPopMatrix();

        }
        glPopMatrix();





        //BridgeSinCurve;	
        glPushMatrix();
        {
            glTranslatef(400, 20, -4);

            glScalef(2, 1, 1);
            glPushMatrix();
            {
                int beamRadius = 40;
                int beamStart = 40;

                glTranslatef(beamStart, 0, this->height);

                BridgeBeam beamLeft(this->beamWidth, this->beamWidth, beamRadius);
                beamLeft.render();

                glTranslatef(0, -this->roadWidth - 40, 0);
                BridgeBeam beamRight(this->beamWidth, this->beamWidth, beamRadius);
                beamRight.render();
            }
            glPopMatrix();

            glPushMatrix();
            {
                int beamRadius = 60;
                int beamStart = 40;

                glTranslatef(beamStart, 0, 0);
                BridgeBeam beamLeft(this->beamWidth, this->beamWidth, beamRadius);
                beamLeft.render();

                glTranslatef(0, -this->roadWidth - 40, 0);
                BridgeBeam beamRight(this->beamWidth, this->beamWidth, beamRadius);
                beamRight.render();
            }
            glPopMatrix();


            glPushMatrix();
            {
                glColor3f(1, .4, 1);
                glTranslatef(0, 0, 50);
                TrashAPkg trashA(20, 20, 20);
                trashA.render();
            }
            glPopMatrix();

            //            glPushMatrix();
            //            {
            //                glTranslatef(0, 0, 40);
            //                int beamRadius = 40;
            //                TrashBPkg trashB(100, beamRadius);
            //                trashB.render();
            //            }
            //            glPopMatrix();


        }
        glPopMatrix();

    }
    glPopMatrix();

}
