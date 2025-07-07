#ifndef _BOY_H 
#define _BOY_H 

#include <Windows.h> 
#include <stdio.h> 
#include <gl/GLU.h> 
#include <gl/GL.h> 

#include "../../Common/common.h"
#include "../../Common/Geometry/geometry.h" 

int initializeBoy(void);  
void displayBoy(void); 
void updateBoy(void); 
void uninitializeBoy(void); 

#endif /* _BOY_H */
