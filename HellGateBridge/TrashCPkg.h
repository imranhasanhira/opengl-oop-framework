/* 
 * File:   TrashCPkg.h
 * Author: Ibrahim
 *
 * Created on June 29, 2012, 1:10 AM
 */

#ifndef TRASHCPKG_H
#define	TRASHCPKG_H

#include "TrashC.h"

class TrashCPkg : public UIElement {
public:
    TrashCPkg(double width, double length);
    virtual ~TrashCPkg();
private:
    void Init();
    double width;
    double length;
    double trashCWidth;
    double trashCLength;    
    double trashCCount;

protected:
    void paint();

};

#endif	/* TrashCPkg_H */

