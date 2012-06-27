/* 
 * File:   Constants.h
 * Author: Ibrahim
 *
 * Created on June 25, 2012, 7:52 PM
 */

#ifndef CONSTANTS_H
#define	CONSTANTS_H

#include <windows.h>

class Constants {

    Constants();
    Constants(const Constants& orig);
    virtual ~Constants();
    
public:
    static const int CAMERA_INIT_X = 30;
    static const int CAMERA_INIT_Y = 30;
    static const int CAMERA_INIT_Z = 30;
    


};

#endif	/* CONSTANTS_H */

