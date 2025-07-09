#ifndef _SCENE_H 
#define _SCENE_H 

#include <gl/glew.h> 
#include <Windows.h> 
#include <stdio.h> 
#include <gl/GL.h> 

#include "../../Common/common.h" 
#include "../../Effects/Cubemap/cubemap.h" 
#include "../../Effects/Fog/fog.h" 
#include "../../Objects/Boy/boy.h" 

int initScene2(void); 
void displayScene2(void); 
void updateScene2(void); 

#endif /* _SCENE_H */
