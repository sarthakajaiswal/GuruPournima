#ifndef _CUBEMAP_H 
#define _CUBEMAP_H 

#include <Windows.h> 
#include <stdio.h> 
#include <gl/glew.h>
#include <gl/GL.h> 

#include "../../Common/stb_image.h" 

unsigned int loadCubeMap(const char* faces[]); 
void displayCubemap(GLuint texture, float cubeScaleX, float cubeScaleY, float cubeScaleZ);  

#endif /* _CUBEMAP_H */
