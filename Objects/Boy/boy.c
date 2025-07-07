#include "boy.h" 

GLUquadric* boyQuadric; 

extern FILE* gpFile; 
extern float tx, ty, tz, sx, sy, sz, rx, ry, rz; 

GLfloat legAngle; 

int initializeBoy(void) 
{
    // code 
    boyQuadric = gluNewQuadric(); 
    if(boyQuadric == NULL) 
    {
        fprintf(gpFile, "failed to get new quadric for boy\n"); 
        return (-1); 
    }

    return (0); 
} 

void displayBoy(void) 
{
    // code 
    // drawTexturedCube(tx, ty, tz, sx, sy, sz, 1.0f, 1.0f, 1.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // body 
    drawTexturedCube(0.0, 0.00, 0.00, 1.15, 2.05, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // body 

    glTranslatef(0.0f, -1.025f, 0.0f); 

    glPushMatrix(); 
    {
        glRotatef(legAngle, 1, 0, 0); 
        // left leg 
        drawTexturedCube(-0.55, -3.0, 0.00, 0.35, 2.20, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // leg 
        drawTexturedCube(-0.55, -5.40, -0.25, 0.35, 0.25, 0.70, 1.0f, 0.0f, 0.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // shoes 
    }
    glPopMatrix(); 

    glPushMatrix(); 
    {
        glRotatef(legAngle, -1, 0, 0); 
        // right leg 
        drawTexturedCube(0.55, -3.0, 0.00, 0.35, 2.20, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // leg 
        drawTexturedCube(0.55, -5.40, -0.25, 0.35, 0.25, 0.70, 1.0f, 0.0f, 0.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // shoes 
    } 
    glPopMatrix();  


    drawTexturedCube(tx, ty, tz, sx, sy, sz, 1.0f, 1.0f, 1.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // leg  
} 

void updateBoy(void) 
{
    // code 
} 

void uninitializeBoy(void) 
{
    // code 
    if(boyQuadric)
    {
        gluDeleteQuadric(boyQuadric); 
        boyQuadric = NULL; 
    }
} 
