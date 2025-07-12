#include "hut.h" 

static GLuint texture_hut_base, texture_hut_top; 
extern FILE* gpFile; 

int initHut(const char* base_texture_image, const char* top_texture_image)
{
    if(!loadGLPngTexture(&texture_hut_base, base_texture_image)) 
    {
        fprintf(gpFile, "failed to load texture for base of hut\n"); 
        return (-1); 
    }
    if(!loadGLPngTexture(&texture_hut_top, top_texture_image)) 
    {
        fprintf(gpFile, "failed to load texture for top of hut\n"); 
        return (-2); 
    }

    return (0); 
} 

void displayHut(void) 
{
    // code 
    // Draw trunk (cylinder)
    drawCylinder(0.8f, 0.8f, 1.0f, 0.0, -1.0, 0.0, 2.0f, 2.0f, 2.0f, -90, 0, 0, texture_hut_base);

    // Draw (cone) above the trunk
    drawCone(1.0f, 1.0f, 0.0, 0.6f, 0.0, 2.0f, 2.0f, 2.0f, -90, 0, 0, texture_hut_top);
}

void uninitializeHut(void) 
{
    // code 
    if(texture_hut_base) 
    {
        glDeleteTextures(1, &texture_hut_base); 
        texture_hut_base = 0; 
    }
    if(texture_hut_top) 
    {
        glDeleteTextures(1, &texture_hut_top); 
        texture_hut_top = 0; 
    }
}
