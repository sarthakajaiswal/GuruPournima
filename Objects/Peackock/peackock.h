#pragma once 

#include <Windows.h> 
#include <stdio.h> 
#include <gl/glew.h> 
#include <gl/GL.h> 
#include <gl/GLU.h> 

#include "../../Common/common.h"
#include "../../Common/Geometry/geometry.h"

static void drawFeather(void); 
static void drawLeg(float thighAngle, float calfAngle); 
static void setStandingPosition(void); 

void initPeackock(void); 
void uninitializePeackock(void); 
void displayPeackock(void); 
void updatePeackock(void); 
