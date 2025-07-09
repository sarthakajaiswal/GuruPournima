#include "scene2.h" 

#include <time.h> 
#include <assert.h> 

extern FILE* gpFile; 
extern float tx, ty, tz, sx, sy, sz; 
extern float cameraX, cameraY, cameraZ; 

static GLuint texture_dry_leaves; 
static GLuint texture_grass; 
static GLuint textures_tree_bark[5]; 
static GLuint textures_tree_leaves[2]; 
static GLuint texture_ground; 

static GLUquadric* scene2Quadric; 

static GLfloat boyPosition = 21.25f; 

static const char* cubemapImages[6] = {
    "Resources/Cubemap/Night/right.png",
    "Resources/Cubemap/Night/left.png",
    "Resources/Cubemap/Night/top.png",
    "Resources/Cubemap/Night/bottom.png",
    "Resources/Cubemap/Night/front.png",
    "Resources/Cubemap/Night/back.png" 
}; 
static GLuint texture_cubemap; 

int initScene2(void) 
{
    if(loadGLPngTexture(&texture_dry_leaves, "Resources/dried_leaves.png") == FALSE)
    {
        fprintf(gpFile, "Failed to load leaves texture for road\n"); 
        return (-1); 
    }
    if(loadGLPngTexture(&texture_ground, "Resources/dry_leaves.png") == FALSE)
    {
        fprintf(gpFile, "Failed to load leaves texture for ground\n"); 
        return (-2); 
    }

    assert(loadGLPngTexture(&textures_tree_bark[0], "Resources/bark1.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[1], "Resources/bark2.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[2], "Resources/bark3.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[3], "Resources/bark4.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[4], "Resources/bark5.png")); 

    assert(loadGLPngTexture(&textures_tree_leaves[0], "Resources/tree1.png")); 
    assert(loadGLPngTexture(&textures_tree_leaves[1], "Resources/tree2.png")); 
    
    texture_cubemap = loadCubeMap(cubemapImages, STBI_rgb); 
    initializeBoy(); 

    scene2Quadric = gluNewQuadric(); 
    if(scene2Quadric == NULL) 
    {
        fprintf(gpFile, "Failed to get new quadric for scene 2\n"); 
        return (-3); 
    }
    gluQuadricTexture(scene2Quadric, GL_TRUE);

    initFog(); 
    enableFog(); 

    return (TRUE); 
} 

void displayScene2(void) 
{
    // code 
    glPushMatrix(); 
    glRotatef(180.0f, 0, 1, 0); // to adjust moon position | moon is in back in cubemap images, bringing it to front 
    displayCubemap(texture_cubemap, 100.0f, 50.0f, 250.0f);  
    glPopMatrix(); 

    // ground 
    glBindTexture(GL_TEXTURE_2D, texture_ground); 
    glPushMatrix(); 
    {
        glScalef(50, 0, 100); 
        glNormal3f(0.0f, 1.0f, 0.0f); 
        glBegin(GL_QUADS); 
        glTexCoord2f(100.0f, 100.0f); 
        glVertex3f(1.0f, 0.0f, -1.0f); 	// right top 

        glTexCoord2f(0.0f, 100.0f); 
        glVertex3f(-1.0f, 0.0f, -1.0f);	// left top 

        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, 0.0f, 1.0f);	// left bottom 

        glTexCoord2f(100.0f, 0.0f); 
        glVertex3f(1.0f, 0.0f, 1.0f);   // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0);
    } 
    glPopMatrix(); 
    glBindTexture(GL_TEXTURE_2D, 0); 

    // road 
    glPushMatrix(); 
    {
        glTranslatef(0.45, 0.05, 0.0); 
        glScalef(1.0, 1.0, 100); 
        glNormal3f(0.0f, 1.0f, 0.0f); 
        glBindTexture(GL_TEXTURE_2D, texture_dry_leaves); 
        glBegin(GL_QUADS); 
        glTexCoord2f(1.0f, 60.0f); 
        glVertex3f(1.0f, 0.0f, -1.0f); 	// right top 

        glTexCoord2f(0.0f, 60.0f); 
        glVertex3f(-1.0f, 0.0f, -1.0f);	// left top 

        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, 0.0f, 1.0f);	// left bottom 

        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, 0.0f, 1.0f);   // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0);
    } 
    glPopMatrix(); 

    // trees 
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    // glEnable(GL_LIGHTING); 
    // glEnable(GL_LIGHT3); 
    // trees 
    float x, z; 
    x = -15.0f; 
    while(x < 13.0f) 
    {
        z = -40.0f; 
        while(z < 20.0f) 
        {
            glPushMatrix(); 
            // bark 
            glTranslatef(x, 5.00, z);  
            glRotatef(90.0, 1, 0, 0); 
            glBindTexture(GL_TEXTURE_2D, textures_tree_bark[(abs(x)*abs(z))%5]); 
            gluCylinder(scene2Quadric, 0.3, 0.25, 5.0, 16, 32);  
            glBindTexture(GL_TEXTURE_2D, 0); 

            // billboard for leaves
            glRotatef(90.0f, 1, 0, 0); // to make billboard vertical  
            billboard(
                0.0f, -1.70, 0.0f, 
                3.05, 2.25, 3.50, 
                textures_tree_leaves[(abs(x)*abs(z))%2]
            ); 
            glPopMatrix();

            z = z + 4.0f; 
        }
        x = x + 4.5f; 
    }

    glPushMatrix(); 
        glTranslatef(0.50, 0.70, boyPosition); 
        glScalef(0.15, 0.10, 0.10); 
        displayBoy(); 
    glPopMatrix(); 

    glPushMatrix(); 
        glTranslatef(cameraX, cameraY, cameraZ+4.35); 
        glEnable(GL_BLEND); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        glColor4f(0.0f, 0.0f, 0.0f, 0.6f); 
        gluSphere(scene2Quadric, 0.5f, 12, 12); 
        glDisable(GL_BLEND); 
    glPopMatrix(); 
}  

void updateScene2(void) 
{
    boyPosition -= 0.02f; 
    updateBoy(); 
} 

void uninitializeScene2(void) 
{
    disableFog(); 
    if(texture_dry_leaves) 
    {
        glDeleteTextures(1, &texture_dry_leaves); 
        texture_dry_leaves = 0; 
    } 
    uninitializeBoy(); 

    if(scene2Quadric) 
    {
        gluDeleteQuadric(scene2Quadric); 
        scene2Quadric = NULL; 
    }
}
