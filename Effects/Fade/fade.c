#include "fade.h" 
#include <stdio.h> 
extern FILE* gpFile; 


extern float cameraX, cameraY, cameraZ; 
extern float updateFadeDensityStep; 

static GLUquadric* fadeQuadric = NULL; 
static float fadeDensity; 
BOOL isFadingIn = FALSE; 
BOOL isFadingOut = FALSE; 

int initializeFade(void) 
{
    fadeQuadric = gluNewQuadric(); 
    if(fadeQuadric == NULL) 
    {
        fprintf(gpFile, "Failed to create fade quadric\n"); 
        return (-1); 
    }
    gluQuadricNormals(fadeQuadric, GLU_NONE); 

    return (0); 
}

BOOL fadeIn(void) 
{   
    // variable declarations 
    static BOOL isThisFirstCall = TRUE; 

    if(isThisFirstCall) 
    {
        fadeDensity = 1.0f; 
        isFadingIn = TRUE; 

        isThisFirstCall = FALSE; 
    } 

    if(isFadingIn) 
    {
        glEnable(GL_BLEND); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        glColor4f(0.0f, 0.0f, 0.0f, fadeDensity); 
        glPushMatrix(); 
        glTranslatef(cameraX, cameraY, cameraZ); 
        gluSphere(fadeQuadric, 0.5, 16, 16); 
        glPopMatrix();  
        glDisable(GL_BLEND); 
        
        return (TRUE);  // if fading still going on 
    } 

    isThisFirstCall = TRUE; 
    return (FALSE); // if fading is completed 
}

BOOL fadeOut(void) 
{   
    // variable declarations 
    static BOOL isThisFirstCall = TRUE; 

    if(isThisFirstCall) 
    {
        fadeDensity = 0.0f; 
        isFadingOut = TRUE; 

        isThisFirstCall = FALSE; 
    } 

    if(isFadingOut) 
    {
        glEnable(GL_BLEND); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        glColor4f(0.0f, 0.0f, 0.0f, fadeDensity); 
        glPushMatrix(); 
        glTranslatef(cameraX, cameraY, cameraZ); 
        gluSphere(fadeQuadric, 0.1, 64, 64); 
        glPopMatrix();  
        glDisable(GL_BLEND); 
        
        return (TRUE);  // if fading still going on 
    } 

    isThisFirstCall = TRUE; 
    return (FALSE); // if fading is completed  
}

void updateFade(void) 
{
    if(isFadingIn) 
    {
        // fprintf(gpFile, "fade density = %lf\n", fadeDensity); 
        // fclose(gpFile); 
        // gpFile = fopen("log.txt", "a"); 
        fadeDensity -= updateFadeDensityStep; 
        if(fadeDensity <= 0.0f) 
        {
            fadeDensity = 0.0f; 
            isFadingIn = FALSE; 
        }
    }

    if(isFadingOut) 
    {
        fadeDensity += updateFadeDensityStep; 
        if(fadeDensity >= 1.0f) 
        {
            fadeDensity = 1.0f; 
            isFadingOut = FALSE; 
        }
    }
}

void uninitializeFade(void) 
{
    // variable declarations  
    if(fadeQuadric) 
    {
        gluDeleteQuadric(fadeQuadric); 
        fadeQuadric = NULL; 
    }
} 
