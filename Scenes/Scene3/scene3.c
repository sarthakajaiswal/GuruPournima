#include "scene3.h" 

extern FILE* gpFile; 
extern float tx, ty, tz, sx, sy, sz; 
extern float cameraX, cameraY, cameraZ; 
extern float cameraCenterX, cameraCenterY, cameraCenterZ; 
extern short shotNumber; 

static GLuint textures_tree_bark[5]; 
static GLuint textures_tree_leaves[2]; 
static GLuint texture_ground; 
static GLuint texture_water; 
static GLuint texture_shore; 
static GLuint texture_bush1; 
static GLuint texture_bush2; 
static GLuint texture_bush3; 
static GLuint texture_bush4; 
static GLuint texture_bamboo_tree; 
static GLuint texture_deer; 

static GLUquadric* scene3Quadric; 

static const char* cubemapImages[6] = {
    "Resources/Cubemap/Day/right.png",
    "Resources/Cubemap/Day/left.png",
    "Resources/Cubemap/Day/top.png",
    "Resources/Cubemap/Day/bottom.png",
    "Resources/Cubemap/Day/front.png",
    "Resources/Cubemap/Day/back.png" 
}; 
static GLuint texture_cubemap; 

// butterfly related 
double butterflyCurveT = 0.0f; 

// water related 
float meltOffset = 0.0f;

// peackock related variables 
float peackockX = -17.10f;  
float peackockRotateAngleY = 0.0f;

int initScene3(void) 
{
    // code 
    assert(loadGLPngTexture(&textures_tree_bark[0], "Resources/bark1.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[1], "Resources/bark2.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[2], "Resources/bark3.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[3], "Resources/bark4.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[4], "Resources/bark5.png")); 
    assert(loadGLPngTexture(&textures_tree_leaves[0], "Resources/tree1.png")); 
    assert(loadGLPngTexture(&textures_tree_leaves[1], "Resources/tree2.png"));  
    assert(loadGLPngTexture(&texture_ground, "Resources/grass1.png")); 
    assert(loadGLPngTexture(&texture_water, "Resources/water.png")); 
    assert(loadGLPngTexture(&texture_shore, "Resources/shore.png")); 
    assert(loadGLPngTexture(&texture_bush1, "Resources/bush1.png")); 
    assert(loadGLPngTexture(&texture_bush2, "Resources/bush2.png")); 
    assert(loadGLPngTexture(&texture_bush3, "Resources/bush3.png")); 
    assert(loadGLPngTexture(&texture_bush4, "Resources/bush4.png")); 
    assert(loadGLPngTexture(&texture_bamboo_tree, "Resources/bamboo_bark.png")); 
    assert(loadGLPngTexture(&texture_deer, "Resources/deers.png")); 

    texture_cubemap = loadCubeMap(cubemapImages, STBI_rgb_alpha); 
    
    scene3Quadric = gluNewQuadric(); 
    if(scene3Quadric == NULL) 
    {
        fprintf(gpFile, "Failed to get new quadric for scene 2\n"); 
        return (-3); 
    }
    gluQuadricTexture(scene3Quadric, GL_TRUE);
    
    // enableFog();  
    initFog(); 
    initGrass(0.2, 0.6, 20.0f, 10000);  
    initPeackock(); 
    initButterfly("Resources/wing_left.png", "Resources/wing_right.png"); 
    initializeBoy(); 
    initHut("Resources/hut_base.png", "Resources/hut_top.png"); 
    
    return (0); 
} 


void displayScene3(void) 
{
    // variable declarations 
    static float isThisFirstCall = TRUE; 
    Point verticesForBazierCurve[] = {{-3.65, 2.15, 17.05}, {-3.65, 4.25, 14.80}, {1.00, 5.55, 9.80}, {-3.95, 3.50, 11.20}, {1.30, 3.25, 20.20}}; 
    size_t size = 5; 

    static BOOL isFadedIn = FALSE; 

    // code 
    if(isThisFirstCall) 
    {
        cameraX = 0.0f; 
        cameraY = 3.80f; 
        cameraZ = 22.20; 
        cameraCenterX = -0.40f; 
        cameraCenterY = 0.20f; 
        cameraCenterZ = -20.0f; 

        glDisable(GL_FOG); 

        isThisFirstCall = FALSE; 
    }

    // hut 
    glPushMatrix(); 
    {
        glTranslatef(-1.50, 1.25, -14.05); 
        glScalef(1.35, 1.35, 0.75); 
        displayHut(); 
    } 
    glPopMatrix(); 

    // cubemap 
    glPushMatrix(); 
    displayCubemap(texture_cubemap, 75.0f, 75.0f, 75.0f);  
    glPopMatrix(); 

    // ground 
    glBindTexture(GL_TEXTURE_2D, texture_ground); 
    glPushMatrix(); 
    {
        glTranslatef(-30.0f, 0.0f, -8.20f); 
        glScalef(35.0, 0.0, 100); 
        glNormal3f(0.0f, 1.0f, 0.0f); 
        glBegin(GL_QUADS); 
        glTexCoord2f(50.0f, 50.0f); 
        glVertex3f(1.0f, 0.0f, -1.0f); 	// right top 

        glTexCoord2f(0.0f, 50.0f); 
        glVertex3f(-1.0f, 0.0f, -1.0f);	// left top 

        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, 0.0f, 1.0f);	// left bottom 

        glTexCoord2f(50.0f, 0.0f); 
        glVertex3f(1.0f, 0.0f, 1.0f);   // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0);
    } 
    glPopMatrix(); 
    glBindTexture(GL_TEXTURE_2D, 0); 

    // shore 
    glBindTexture(GL_TEXTURE_2D, texture_shore); 
    glPushMatrix(); 
    {
        glTranslatef(5.80, -0.35, 0.0); 
        glScalef(0.95, 0.90, 100); 
        glRotatef(-20.0f, 0, 0, 1); 
        glNormal3f(0.0f, 1.0f, 0.0f); 
        glBegin(GL_QUADS); 
        glTexCoord2f(1.0f, 50.0f); 
        glVertex3f(1.0f, 0.0f, -1.0f); 	// right top 

        glTexCoord2f(0.0f, 50.0f); 
        glVertex3f(-1.0f, 0.0f, -1.0f);	// left top 

        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, 0.0f, 1.0f);	// left bottom 

        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, 0.0f, 1.0f);   // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0);
    } 
    glPopMatrix(); 
    glBindTexture(GL_TEXTURE_2D, 0); 

    // water 
    glPushMatrix(); 
    {
        glTranslatef(23.40, -0.70, -22.95);
        // glTranslatef(tx, ty, tz); 
        glScalef(11.65, 2.15, 26.0);  
        glBindTexture(GL_TEXTURE_2D, texture_water);
        drawWaterSurface(meltOffset, 3.0f, 3.0f, 50.0f); 
        glBindTexture(GL_TEXTURE_2D, 0); 
    } 
    glPopMatrix(); 

    // grass 
    glPushMatrix(); 
    {
        glTranslatef(-20.70, -0.00, -17.45);
        glScalef(0.55, 1.70, 2.30);  
        displayGrass(); 
    } 
    glPopMatrix(); 

    // deer 
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    billboard(-12.70, 1.35, -24.10, 2.65, 2.65, 1.00, texture_deer);  
    glDisable(GL_BLEND); 

    // peackock 
    extern BOOL showingFeathers;  
    glPushMatrix(); 
    glTranslatef(peackockX, 1.45, -0.25);
    glScalef(0.40, 0.35, 0.50);  
    glRotatef(peackockRotateAngleY, 0.0f, 1.0f, 0.0f); 
    displayPeackock();  
    glPopMatrix(); 

    if(peackockX >= -2.40f)
        showingFeathers = TRUE; 

    // bamboo tree 
    glPushMatrix(); 
    glTranslatef(3.95, 7.20, 16.75); 
    glScalef(1.75, 1.00, 1.00); 
    glRotatef(90, 1, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f);  
    glBindTexture(GL_TEXTURE_2D, texture_bamboo_tree); 
    gluCylinder(scene3Quadric, 0.5, 0.5, 6.00, 12, 8);  
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix(); 

    // bushes 
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    billboard(-11.35, 2.15, 4.60, 2.35, 2.85, 4.95, texture_bush1); 
    billboard(4.90, 0.80, 0.00, 1.00, 1.00, 1.00, texture_bush2);  
    billboard(-4.65, 1.00, 14.80, 1.50, 1.30, 1.85, texture_bush3);  
    billboard(3.30, 1.00, 17.20, 0.70, 1.75, 1.35, texture_bush4);  
    billboard(3.30, 1.00, 17.20, 0.70, 1.75, 1.35, texture_bush4);  
    billboard(-8.45, 0.95, -8.30, 0.95, 1.00, 1.00, texture_bush4);      
    glDisable(GL_BLEND); 
    
    // butterfly 
    Point butterflyPosition; 
    if(butterflyCurveT <= 1.0f)
        butterflyPosition = getPointOnBazierCurve(verticesForBazierCurve, 5, butterflyCurveT); 

    glPushMatrix();
    glTranslatef(butterflyPosition.x, butterflyPosition.y, butterflyPosition.z); 
    glScalef(0.20, 0.85, 0.25);  
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);  
    displayButterfly(); 
    glPopMatrix(); 

    if(isFadedIn == FALSE) 
    {
        if(fadeIn() == FALSE)
            isFadedIn = TRUE; // fadeIn() return FALSE when fadein is completed     
    }
}  

void updateScene3(void) 
{
    // variable declarations 
    extern float peackockXupdateStep; 
    extern float peackockRotateAngleYUpdateStep; 
    extern int butterflyWaitTimer; 
    extern int scene3WaitTimer; 

    // code 
    updateGrass(); 

    // water update 
    meltOffset += 0.02f;
    if (meltOffset > 1000)
    {
        meltOffset = 0.0f;
    }

    // peackock 
    if(peackockX <= -2.40f)
        peackockX += peackockXupdateStep; 
    
    if(peackockX > -2.40f && peackockRotateAngleY > -90.0f) 
        peackockRotateAngleY -= peackockRotateAngleYUpdateStep; 

    updatePeackock(); 

    if(butterflyWaitTimer <= 0) 
    {
        if(butterflyCurveT < 1.0f) 
        {
            butterflyCurveT = butterflyCurveT + 0.001f; 
            if(butterflyCurveT > 1.0f) 
                butterflyCurveT = 1.0f; 
        } 
        updateButterfly(); 
    } 
    else 
    {
        butterflyWaitTimer -= 1; 
    }

    updateFade(); 

    if(scene3WaitTimer > 0) 
    {
        // scene3WaitTimer -= 1; 
        if(scene3WaitTimer <= 0) 
            shotNumber++; 
    }
} 

void uninitializeScene3(void) 
{
    uninitializeGrass(); 
    uninitializePeackock(); 
    uninitializeButterfly(); 
    uninitializeHut(); 
}
