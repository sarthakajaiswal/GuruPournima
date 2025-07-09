#ifndef _BAZIER_CURVE_H 
#define _BAZIER_CURVE_H 

#include <Windows.h> 
#include <stdio.h> 

#include <gl/GL.h> 

typedef struct point{
    float x, y, z; 
}Point; 

void initBazierCurve(Point* pointsArray); 
void displayBazierCurve(void); 

float getPointOnBazierCurveX(int start_index, int end_index, double t); 
float getPointOnBazierCurveY(int start_index, int end_index, double t); 
float getPointOnBazierCurveZ(int start_index, int end_index, double t); 

Point getPointOnBazierCurve(double t); 
void updateBazierCurve(void); 
void uninitializeBazierCurve(void); 

#endif /* _BAZIER_CURVE_H */
