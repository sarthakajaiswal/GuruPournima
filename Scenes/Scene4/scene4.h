#ifndef _SCENE4_H 
#define _SCENE4_H 

#include <Windows.h> 
#include <stdio.h> 
#include <assert.h> 

#include <gl/GL.h> 
#include <gl/GLU.h> 

#include "../../Effects/Fade/fade.h"
#include "../../Objects/CubicAlphabets/cubic_alphabets.h"

int initScene4(void); 
void displayScene4(void); 
void updateScene4(void); 
void uninitializeScene4(void); 

// helper function 
void displayFrustum6(void); 

#endif /* _SCENE4_H */
