#ifndef _SCENE3_H 
#define _SCENE3_H 

#include <Windows.h> 
#include <stdio.h> 
#include <assert.h> 

#include <gl/glew.h> 
#include <gl/GL.h> 
#include <gl/GLU.h> 

#include "../../common/stb_image.h" 
#include "../../common/Geometry/geometry.h" 
#include "../../common/common.h" 
#include "../../Effects/Cubemap/cubemap.h" 
#include "../../Objects\Grass\grass.h" 
#include "../../Objects\Peackock\peackock.h" 
#include "../../Common/BazierCurve/bazier.h"

int initScene3(void); 
void displayScene3(void); 
void updateScene3(void); 
void uninitializeScene3(void);  

#endif /* _SCENE3_H */
