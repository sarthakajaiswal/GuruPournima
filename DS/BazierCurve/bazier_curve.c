#include "bazier_curve.h" 

Point* bazierPoints = NULL; 
size_t size; 

#pragma comment(lib, "opengl32.lib") 

// extern FILE* gpFile; 

void initBazierCurve(Point pointsArray[]) 
{
    // variable declarations 
    size_t inputArraySize = sizeof(pointsArray); 

    // code 
    size = inputArraySize; 
    bazierPoints = (Point*)sizeof(size); 
    if(bazierPoints == 0) 
    {
        // fprintf(gpFile, "failed to allocate array for bazier points\n"); 
        exit(EXIT_FAILURE); 
    }

    memcpy(bazierPoints, pointsArray, inputArraySize); 
} 

void displayBazierCurve(void) 
{
    // variable declarations 
    Point instantantaneousPoint; 
    float t = 0.0f; 
    
    // code  
    glBegin(GL_LINE_STRIP); 
    while(t < 1.0f) 
    {
        glVertex3f(
            getPointOnBazierCurveX(0, size, t), 
            getPointOnBazierCurveY(0, size, t), 
            getPointOnBazierCurveZ(0, size, t) 
        ); 
        t = t + 0.001f; 
    }
    glEnd(); 
} 

float getPointOnBazierCurveX(int start_index, int end_index, double t) 
{
    // code 
    if(end_index-start_index == 1) 
        return ((1-t) * bazierPoints[start_index].x) + (t * bazierPoints[end_index].x); 
    else 
        return ((1-t) * getPointOnBazierCurveY(start_index, end_index-1, t)); 
} 

float getPointOnBazierCurveY(int start_index, int end_index, double t) 
{
    // code 
    if(end_index-start_index == 1) 
        return ((1-t) * bazierPoints[start_index].y) + (t * bazierPoints[end_index].y); 
    else 
        return ((1-t) * getPointOnBazierCurveY(start_index, end_index-1, t)); 
} 

float getPointOnBazierCurveZ(int start_index, int end_index, double t) 
{
    // code 
    if(end_index-start_index == 1) 
        return ((1-t) * bazierPoints[start_index].z) + (t * bazierPoints[end_index].z); 
    else 
        return ((1-t) * getPointOnBazierCurveY(start_index, end_index-1, t)); 
} 

void updateBazierCurve(void) 
{
    // code 
} 

void uninitializeBazierCurve(void) 
{
    // code 
    if(bazierPoints) 
    {
        free(bazierPoints); 
        bazierPoints = NULL; 
    }
} 
