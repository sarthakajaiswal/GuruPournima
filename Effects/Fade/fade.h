#ifndef _FADE_H 
#define _FADE_H 

// standard headers 
#include <Windows.h> 

// OpenGL related headers 
#include <gl/GL.h> 
#include <gl/glu.h> 

int initializeFade(void); 
BOOL fadeIn(void); 
BOOL fadeOut(void);  
void updateFade(void); 
void uninitializeFade(void); 

#endif 
