/* 
 * File:   W.h
 * Author: Md Imran Hasan
 *
 * Created on June 1, 2012, 1:39 AM
 */

#ifndef W_H
#define	W_H

class Resource {
private:

public:

    double delTheta;
    double delStep;

    double worldWidth;
    double worldHeight;

    Resource() {
        delTheta = 2;
        delStep = 50;

        worldWidth = 20000;
        worldHeight = 20000;
    }


};

#endif	/* W_H */

