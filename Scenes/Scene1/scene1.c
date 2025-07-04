#include "scene1.h" 

void initScene1(void) 
{

}

void displayScene1(void) 
{
    struct Quad quad = {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}; 
    cubeFromQuad(&quad, 1.0f);  
} 

void updateScene1(void) 
{

} 
