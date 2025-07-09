#include "grass.h" 
#include <math.h>  

static int NUM_BLADES; 
static float BLADE_WIDTH; 
static float BLADE_HEIGHT; 
static float AREA_SIZE; 

static float rotateAngle; 

extern FILE* gpFile; 

void initGrass(float blade_width, float blade_height, int area_size, int num_blades)
{
	NUM_BLADES = num_blades; 
	BLADE_WIDTH = blade_width; 
	BLADE_HEIGHT = blade_height; 
	AREA_SIZE = area_size; 
} 

void displayGrass(void)  
{
	srand((unsigned int)1234);
	for (int idx = 0; idx < NUM_BLADES; idx++)
	{
		float x = randomNumber(); 
		x = (x * 2) - AREA_SIZE;
		float z = randomNumber(); 
		z = (z * 2) - AREA_SIZE;
		
		glPushMatrix();
		{
			glTranslatef(x, 0, z);
			glRotatef(rotateAngle, 0, 0, 1); 
			drawGrassBlade(); 
		}
		glPopMatrix();
	}
} 

float randomNumber() 
{
    return ((float)rand()/(float)(RAND_MAX)) * AREA_SIZE; 
}

void drawGrassBlade() 
{
	glBegin(GL_TRIANGLES); 
	{
		glColor3f(0.113, 0.387, 0.047); 
		glVertex3f(-BLADE_WIDTH/2, 0.0f, 0.0f);   
		glVertex3f(BLADE_WIDTH/2, 0.0f, 0.0f);   
		
		glColor3f(0.492f, 0.891, 0.359); 
		glVertex3f(0.0f, BLADE_HEIGHT, 0.0f); 
	}
	glEnd(); 
}

void updateGrass() 
{
	static BOOL increaseAngle = TRUE; 
	if(increaseAngle == TRUE) 
	{
		rotateAngle = rotateAngle + 0.2; 
		if(rotateAngle >= 20.0f) 
			increaseAngle = FALSE; 
	} 
	else 
	{
		rotateAngle = rotateAngle - 0.2; 
		if(rotateAngle <= 0.0f) 
			increaseAngle = TRUE; 
	}
} 

void uninitializeGrass(void) 
{
	NUM_BLADES = 0.0f;  
	BLADE_WIDTH = 0.0f;  
	BLADE_HEIGHT = 0.0f;  
	AREA_SIZE = 0.0f;  
}
