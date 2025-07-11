#include "butterfly.h" 

static float wingAngle = 0.0f; 

static GLuint texture_lwing, texture_rwing;  

void initButterfly(const char* lwing_texture_image, const char* rwing_texture_image) 
{
    assert(loadGLPngTexture(&texture_lwing, lwing_texture_image)); 
    assert(loadGLPngTexture(&texture_rwing, rwing_texture_image)); 
}

void displayButterfly(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glColor3f(1.0f, 1.0f, 1.0f);  // no tint

	// Left Wing
	glPushMatrix();
	{
		glTranslatef(-0.0005f, 0.0f, 0.0f);  // Slight shift for flapping center
		glRotatef(wingAngle, 0.0f, 1.0f, 0.0f);  // flap outward

		glBindTexture(GL_TEXTURE_2D, texture_lwing);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();

	// Right Wing
	glPushMatrix();
	{
		glTranslatef(0.0005f, 0.0f, 0.0f);  // Shift right for pivot
		glRotatef(-wingAngle, 0.0f, 1.0f, 0.0f);  // flap outward

		glBindTexture(GL_TEXTURE_2D, texture_rwing);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();

	glDisable(GL_BLEND);
} 

void updateButterfly(void) 
{
    // variable declarations 
    static BOOL butterflyWingFlag = TRUE; 

    // code 
    if(butterflyWingFlag) 
    {
        wingAngle += 1.2f; 
        if(wingAngle >= 10.0f) 
            butterflyWingFlag = FALSE; 
    } 
    else 
    {
        wingAngle -= 1.2f; 
        if(wingAngle <= -20.0f) 
            butterflyWingFlag = TRUE; 
    }
}

void uninitializeButterfly(void) 
{
    if(texture_lwing) 
    {
        glDeleteTextures(1, &texture_lwing); 
        texture_lwing = 0; 
    }
    if(texture_rwing) 
    {
        glDeleteTextures(1, &texture_rwing); 
        texture_rwing = 0; 
    }
}
