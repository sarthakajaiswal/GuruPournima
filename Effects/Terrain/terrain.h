#ifndef _TERRAIN_H 
#define _TERRAIN_H 

#include <Windows.h> 
#include <stdio.h> 
#include <gl/GL.h> 
#include <gl/GLU.h> 

#include "../../Common/stb_image.h" 

int initTerrain(const char* heightMapBPImage, const char* texturePNGImage); 
void uninitializeTerrain(void); 
void displayTerrain(void); 

#endif /* _TERRAIN_H */
