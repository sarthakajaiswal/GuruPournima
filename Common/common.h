#ifndef _COMMON_H 
#define _COMMON_H 

#include <Windows.h> 
#include <stdio.h> 
#include <gl/GL.h> 
#include <gl/GLU.h>

struct Color 
{
    float r, g, b, a; 
}; 

struct Quad 
{
    // co-ordinates of vertices of quad 
    // starting from right-top to right-bottom in anticlockwise direction 
    float p1x, p1y; 
    float p2x, p2y; 
    float p3x, p3y; 
    float p4x, p4y; 

    struct Color color; 
}; 

void cubeFromQuad(struct Quad* quad, float depth); 

BOOL loadGLPngTexture(GLuint* texture, char* file); 

#endif /* _COMMON_H */
