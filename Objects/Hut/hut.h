#ifndef _HUT_H 
#define _HUT_H 

#include <Windows.h> 
#include <stdio.h> 

#include <gl/GL.h> 
#include <gl/GLU.h> 

#include "../../Common/Geometry/geometry.h" 

int initHut(const char* base_texture_image, const char* top_texture_image); 
void displayHut(void); 
void uninitializeHut(void); 

#endif /* _HUT_H */
