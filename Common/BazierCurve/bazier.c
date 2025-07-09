#include "bazier.h" 

extern FILE* gpFile; 

BazierCurve* getBazierCurve(Point pointsArray[]) 
{
    // variable declarations 
    size_t inputArrayNrElements; 
    BazierCurve* pCurve; 

    // code 
    inputArrayNrElements = sizeof(pointsArray)/sizeof(pointsArray[0]); 

    pCurve = (BazierCurve*)malloc(sizeof(BazierCurve)); 
    if(pCurve == NULL) 
    {
        fprintf(gpFile, "Error in allocating memory for bazier curve\n"); 
        exit(EXIT_FAILURE); 
    }

    pCurve->nr_vertices = inputArrayNrElements; 
    pCurve->vertices = (Point*)malloc(sizeof(Point) * inputArrayNrElements); 
    if(pCurve == NULL) 
    {
        fprintf(gpFile, "Error in allocating memory for bazier curve\n"); 
        exit(EXIT_FAILURE); 
    }

    for(size_t i = 0; i < inputArrayNrElements; ++i) 
        pCurve->vertices[i] = pointsArray[i]; 
} 

float getPointOnBazierCurveX(Point bazierPoints[], int start_index, int end_index, double t) 
{
    // code 
    if(end_index-start_index == 1) 
        // fprintf(gpFile, "%.2f %.2f %.2f %.2f %.2f \n", start_index, end_index, bazierPoints[start_index], bazierPoints[end_index], t); 
        return ((1-t) * bazierPoints[start_index].x) + (t * bazierPoints[end_index].x); 
    else 
        return ((1-t) * getPointOnBazierCurveX(bazierPoints, start_index, end_index-1, t)) + (t * getPointOnBazierCurveX(bazierPoints, start_index+1, end_index, t)); 
} 

float getPointOnBazierCurveY(Point bazierPoints[], int start_index, int end_index, double t) 
{
    // code 
    if(end_index-start_index == 1) 
        return ((1-t) * bazierPoints[start_index].y) + (t * bazierPoints[end_index].y); 
    else 
        return ((1-t) * getPointOnBazierCurveY(bazierPoints, start_index, end_index-1, t)) + (t * getPointOnBazierCurveY(bazierPoints, start_index+1, end_index, t));  
} 

float getPointOnBazierCurveZ(Point bazierPoints[], int start_index, int end_index, double t) 
{
    // code 
    if(end_index-start_index == 1) 
        return ((1-t) * bazierPoints[start_index].z) + (t * bazierPoints[end_index].z); 
    else 
        return ((1-t) * getPointOnBazierCurveZ(bazierPoints, start_index, end_index-1, t)) + (t * getPointOnBazierCurveZ(bazierPoints, start_index+1, end_index, t));  
} 

void displayBazierCurve(Point pointsArray[], size_t size) 
{
    // variable declarations 
    float t = 0.0f; 
    
    // code  
    // glColor3f(1.0f, 1.0f, 1.0f); 
    
    glPointSize(6.0f); 
    glBegin(GL_POINTS); 
    for(size_t i = 0; i < size; ++i) 
    {
        glColor3f(1.0f, 0.0f, 0.0f);  
        glVertex3f(pointsArray[i].x, pointsArray[i].y, pointsArray[i].z); 
    }
    glEnd(); 
    
    glLineWidth(2.0f); 
    glBegin(GL_LINE_STRIP); 
    while(t <= 1.0f) 
    {
        glVertex3f(
            getPointOnBazierCurveX(pointsArray, 0, size-1, t), 
            getPointOnBazierCurveY(pointsArray, 0, size-1, t), 
            getPointOnBazierCurveZ(pointsArray, 0, size-1, t) 
        );
    
        t = t + 0.02f; 
    }
    glEnd(); 
} 



void uninitializeBazierCurve(BazierCurve* curve) 
{} 