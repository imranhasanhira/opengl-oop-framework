/* 
 * File:   macros.h
 * Author: Ibrahim
 *
 * Created on June 27, 2012, 12:49 PM
 */

#ifndef MACROS_H
#define	MACROS_H

#define MATH_e  2.718281828
#define printI(X) printf("%d\n",X);
#define printD(X) printf("%lf\n",X);
#define D2R(X) (PI/180)*X
#define R2D(X) (180/PI)*X

#define SIGMA_SQ .2 
#define Gauss(X) 1/sqrt(2 * PI * S(.1) ) * exp(- S(X)/2 * S(.1) );

#endif	/* MACROS_H */

