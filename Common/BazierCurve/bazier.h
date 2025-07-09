#ifndef _BAZIER_H 
#define _BAZIER_H 

#include <stdio.h> 
#include <Windows.h> 

#include <gl/GL.h> 

typedef struct Point 
{
    float x, y, z; 
}Point; 

typedef struct BazierCurve
{
    Point* vertices; 
    size_t nr_vertices; 
}BazierCurve; 

// BazierCurve* getBazierCurve(Point pointsArray[]); 
// void displayBazierCurve(BazierCurve* curve); 
void testdisplayBazierCurve(Point pointsArray[], size_t size); 
Point getPointOnBazierCurve(Point pointsArray[], size_t size, double t); 
// void uninitializeBazierCurve(BazierCurve* curve); 

#endif 
