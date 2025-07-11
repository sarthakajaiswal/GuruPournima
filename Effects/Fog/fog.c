// header files 
#include "fog.h" 

GLfloat fogColor[4] = {0.2f, 0.2f, 0.21f, 0.5f}; 
GLfloat fogDensity = 0.015f; 
GLfloat fogMode = GL_EXP2; 
GLfloat fogStart = 0.2f; 
GLfloat fogEnd = 2000.0f; 

static BOOL bFogEnabled; 

// initialize fog 
void initFog(void) 
{
    glFogfv(GL_FOG_COLOR, fogColor); 

    // fog mode (GL_EXP, GL_EXP2, or GL_LINEAR)
    glFogi(GL_FOG_MODE, fogMode); 
    glFogf(GL_FOG_DENSITY, fogDensity); 

    glFogf(GL_FOG_START, fogStart); 
    glFogf(GL_FOG_END, fogEnd); 

    glHint(GL_FOG_HINT, GL_NICEST); 
}

void disableFog() 
{
    bFogEnabled = FALSE; 
    glDisable(GL_FOG); 
}

void enableFog() 
{
    bFogEnabled = TRUE; 
    glEnable(GL_FOG); 
}

// updating fog 
void updateFog(void) 
{
    if(bFogEnabled) 
    {
        glFogfv(GL_FOG_COLOR, fogColor); 
        glFogi(GL_FOG_MODE, fogMode); 
        glFogf(GL_FOG_DENSITY, fogDensity); 
        glFogf(GL_FOG_START, fogStart); 
        glFogf(GL_FOG_END, fogEnd); 
    } 
}


