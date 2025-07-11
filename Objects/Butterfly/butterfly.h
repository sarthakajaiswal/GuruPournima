#ifndef _BUTTERFLY_H 
#define _BUTTERFLY_H 

#include <Windows.h> 
#include <stdio.h> 
#include <assert.h> 

#include <gl/GL.h> 

void initButterfly(const char* lwing_texture_image, const char* rwing_texture_image);  
void displayButterfly(void); 
void updateButterfly(void); 
void uninitializeButterfly(void); 

#endif 
