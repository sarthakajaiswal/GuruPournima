#ifndef _GRASS_H 
#define _GRASS_H 

#include <Windows.h> 
#include <stdio.h> 

#include <gl/glew.h> 
#include <gl/GL.h> 
#include <gl/GLU.h> 

static float randomNumber(void); 

void initGrass(float blade_width, float blade_height, int area_size, int num_blades); 
void drawGrassBlade(void); 
void displayGrass(void); 
void updateGrass(void); 

#endif /* _GRASS_H */ 
