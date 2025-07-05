#include "scene2.h" 

void initScene2(void) 
{
    initTerrain("Resources/Terrain.bmp", "Resources/water_particle.png"); 
} 

void displayScene2(void) 
{
    displayTerrain(); 
} 

void updateScene2(void) 
{
    uninitializeTerrain(); 
} 
