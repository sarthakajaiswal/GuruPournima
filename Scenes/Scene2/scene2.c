#include "scene2.h" 

extern FILE* gpFile; 
float tx, ty, tz, sx, sy, sz; 

GLuint texture_dry_leaves; 

const char* cubemapImages[6] = {
    "Resources/Cubemap/Day/right.png",
    "Resources/Cubemap/Day/left.png",
    "Resources/Cubemap/Day/top.png",
    "Resources/Cubemap/Day/bottom.png",
    "Resources/Cubemap/Day/front.png",
    "Resources/Cubemap/Day/back.png" 
}; 
GLuint texture_cubemap; 

BOOL initScene2(void) 
{
    if(loadGLPngTexture(&texture_dry_leaves, "Resources/dried_leaves.png") == FALSE)
    {
        fprintf(gpFile, "Failed to load leaves texture for ground\n"); 
        return (FALSE); 
    }

    texture_cubemap = loadCubeMap(cubemapImages); 
    initializeBoy(); 

    return (TRUE); 
} 

void displayScene2(void) 
{
    
    displayCubemap(texture_cubemap, 100.0f, 100.0f, 100.0f);  

    // ground 
    // glNormal3f(0.0f, 1.0f, 0.0f); 
    // glBindTexture(GL_TEXTURE_2D, texture_dry_leaves); 
    // glBegin(GL_QUADS); 
    // glTexCoord2f(1.0f, 1.0f); 
    // glVertex3f(1.0f, 0.0f, -1.0f); 	// right top 

    // glTexCoord2f(0.0f, 1.0f); 
    // glVertex3f(-1.0f, 0.0f, -1.0f);	// left top 

    // glTexCoord2f(0.0f, 0.0f); 
    // glVertex3f(-1.0f, 0.0f, 1.0f);	// left bottom 

    // glTexCoord2f(1.0f, 0.0f); 
    // glVertex3f(1.0f, 0.0f, 1.0f);   // right bottom 
    // glEnd(); 
    // glBindTexture(GL_TEXTURE_2D, 0);

    displayBoy(); 
}  

void updateScene2(void) 
{

} 

void uninitializeScene2(void) 
{
    if(texture_dry_leaves) 
    {
        glDeleteTextures(1, &texture_dry_leaves); 
        texture_dry_leaves = 0; 
    } 

    uninitializeBoy(); 
}
