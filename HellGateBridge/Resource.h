/* 
 * File:   W.h
 * Author: Md Imran Hasan
 *
 * Created on June 1, 2012, 1:39 AM
 */

#ifndef W_H
#define	W_H

class Resource {
public:

    double delTheta;
    double delStep;

    double worldWidth;
    double worldHeight;

    Resource() {
        delTheta = 0.5;
        delStep = 0.8;

	worldWidth = 20000;
	worldHeight = 20000;
    }
private:

};

#endif	/* W_H */

