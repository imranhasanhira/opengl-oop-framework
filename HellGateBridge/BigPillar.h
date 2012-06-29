/* 
 * File:   BigPillar.h
 * Author: Md Imran Hasan
 *
 * Created on June 30, 2012, 12:04 AM
 */

#ifndef BIGPILLAR_H
#define	BIGPILLAR_H
#include "UIElement.h"

class BigPillar : public UIElement {
public:
    BigPillar(Vector position);
    virtual ~BigPillar();
protected:
    void paint();
    void drawPillerLeft(double l, double w, double h);
private:

};

#endif	/* BIGPILLAR_H */

