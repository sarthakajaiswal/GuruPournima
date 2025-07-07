#ifndef _GEOMETRY_H 
#define _GEOMETRY_H 

#include <Windows.h> 
#include <stdio.h> 

#include <gl/GL.h> 

typedef enum FaceType{
    FACE_NONE =     0x000000, 
    FACE_FRONT =    0x000001, 
    FACE_BACK =     0x000010, 
    FACE_LEFT =     0x000100, 
    FACE_RIGHT =    0x001000, 
    FACE_TOP =      0x010000, 
    FACE_BOTTOM =   0x100000, 
    FACE_ALL =      0x111111 
}FaceType;  

void drawTexturedCube(
        float x, float y, float z, float sx, float sy, float sz, float r, float g, float b, 
        FaceType faces_to_be_textured, 
        GLuint texture_front, GLuint texture_right, GLuint texture_back, 
        GLuint texture_left, GLuint texture_top, GLuint texture_bottom 
); 

#endif /* _GEOMETRY_H */
