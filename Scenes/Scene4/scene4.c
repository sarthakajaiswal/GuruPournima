#include "scene4.h" 

extern FILE* gpFile; 
extern float tx, ty, tz, sx, sy, sz; 
extern float cameraX, cameraY, cameraZ; 
extern  unsigned long long mainTimer; 
extern BOOL bDone; 

static GLUquadric* scene4Quadric = NULL;

static GLuint texture_slide1; 
static GLuint texture_slide2; 
static GLuint texture_slide3; 
static GLuint texture_slide4; 
static GLuint texture_slide5; 
static int slide_number = 1; 

int initScene4(void) 
{
    scene4Quadric = gluNewQuadric(); 
    if(scene4Quadric == NULL) 
    {
        fprintf(gpFile, "Failed to get new quadric for scene 2\n"); 
        return (-1); 
    }

    assert(loadGLPngTexture(&texture_slide1, "Resources/slide1.png")); 
    assert(loadGLPngTexture(&texture_slide2, "Resources/slide2.png")); 
    assert(loadGLPngTexture(&texture_slide3, "Resources/slide3.png")); 
    assert(loadGLPngTexture(&texture_slide4, "Resources/slide4.png")); 
    assert(loadGLPngTexture(&texture_slide5, "Resources/slide5.png")); 

    return (0);
} 

void displayScene4(void) 
{
    // variable declarations 
    static BOOL isThisFirstCall = TRUE; 
    static BOOL isFadedIn = FALSE; 

    // code 
    if(isThisFirstCall) 
    {
        cameraX = 0.0f; 
        cameraY = 0.0f; 
        cameraZ = 5.0f; 

        isThisFirstCall = FALSE; 
    }

    // setting texture of slide to be displayed 
    switch(slide_number) 
    {
    case 1: 
        glBindTexture(GL_TEXTURE_2D, texture_slide1); 
        break; 
    case 2: 
        glBindTexture(GL_TEXTURE_2D, texture_slide2);  
        break; 
    case 3: 
        glBindTexture(GL_TEXTURE_2D, texture_slide3);  
        break; 
    case 4: 
        glBindTexture(GL_TEXTURE_2D, texture_slide4);  
        break; 
    case 5: 
        extern unsigned int slide5WaitTimer; 
        if(slide5WaitTimer < 800)
            displayFrustum6();      
        glBindTexture(GL_TEXTURE_2D, texture_slide5); 
        break; 
    
    default: 
        break; 
    } 

    glPushMatrix(); 
    { 
        glScalef(2.95, 1.65, 1.00); 
        glColor3f(1.0f, 1.0f, 1.0f); 
        glBegin(GL_QUADS); 
        glTexCoord2f(1.0f, 1.0f);   glVertex3f(1.0f, 1.0f, 1.0f); 
        glTexCoord2f(0.0f, 1.0f);   glVertex3f(-1.0f, 1.0f, 1.0f);	 
        glTexCoord2f(0.0f, 0.0f);   glVertex3f(-1.0f, -1.0f, 1.0f);  
        glTexCoord2f(1.0f, 0.0f);   glVertex3f(1.0f, -1.0f, 1.0f); 
        glEnd(); 
    }
    glPopMatrix(); 
    glBindTexture(GL_TEXTURE_2D, 0); 

    if(isFadedIn == FALSE) 
    {
        if(fadeIn() == FALSE)
            isFadedIn = TRUE; // fadeIn() return FALSE when fadein is completed     
    }

    if(slide_number == 6) 
    { 
            bDone = TRUE; 
    }
} 

void updateScene4(void) 
{
    extern unsigned int slide1WaitTimer, slide2WaitTimer, slide3WaitTimer, slide4WaitTimer, slide5WaitTimer, slide6WaitTimer; 

    switch(slide_number) 
    {
    case 1: 
        fprintf(gpFile, "waittimer = %d ", slide1WaitTimer); 
        slide1WaitTimer -= 1; 
        if(slide1WaitTimer == 0) 
            slide_number++; 
        break; 
    case 2: 
        slide2WaitTimer -= 1; 
        if(slide2WaitTimer == 0) 
            slide_number++; 
        break; 
    case 3: 
        slide3WaitTimer -= 1; 
        if(slide3WaitTimer == 0) 
            slide_number++; 
        break; 
    case 4: 
        slide4WaitTimer -= 1; 
        if(slide4WaitTimer == 0) 
            slide_number++; 
        break; 
    case 5: 
        slide5WaitTimer -= 1; 
        if(slide5WaitTimer < 800)
            updateLights(); 
        if(slide5WaitTimer == 0) 
            slide_number++; 
        break; 

    default: 
        break; 
    } 

    updateFade(); 
} 

void displayFrustum6(void) 
{
    // variable declarations 
    static BOOL isThisFirstCall = TRUE; 

    // code 
    if(isThisFirstCall) 
    {
        initLights(); 
        glEnable(GL_LIGHTING); 
        glEnable(GL_LIGHT0); 
        glEnable(GL_LIGHT1); 

        isThisFirstCall = FALSE; 
    }

    void (*arrayOfPointersToFunction[])(void) = {f, r, u, s, t, u, m, six, point, o}; 
    float translate = -2.0f; 

    for(int i = 0; i < 8; ++i) 
    {
        glPushMatrix(); 
        glTranslatef(translate, 0.0f, 0.0f); 
        glScalef(0.10, 0.20, 1.15); 
        arrayOfPointersToFunction[i](); 
        glPopMatrix(); 

        translate += 0.5f; 
    }

    glPushMatrix(); 
    glTranslatef(translate-0.3f, 0.0f, 0.0f); 
    glScalef(0.10, 0.20, 1.15); 
    arrayOfPointersToFunction[8](); 
    glPopMatrix(); 
    
    glPushMatrix(); 
    glTranslatef(translate, 0.0f, 0.0f); 
    glScalef(0.10, 0.20, 1.15); 
    arrayOfPointersToFunction[9](); 
    glPopMatrix(); 
}

void uninitializeScene4(void) 
{
    if(texture_slide5) 
    {
        glDeleteTextures(1, &texture_slide5); 
        texture_slide5 = 0; 
    }
    if(texture_slide4) 
    {
        glDeleteTextures(1, &texture_slide4); 
        texture_slide4 = 0; 
    }
    if(texture_slide3) 
    {
        glDeleteTextures(1, &texture_slide3); 
        texture_slide3 = 0; 
    }
    if(texture_slide2) 
    {
        glDeleteTextures(1, &texture_slide2); 
        texture_slide2 = 0; 
    }
    if(texture_slide1) 
    {
        glDeleteTextures(1, &texture_slide1); 
        texture_slide1 = 0; 
    }

    if(scene4Quadric) 
    {
        gluDeleteQuadric(scene4Quadric); 
        scene4Quadric = NULL; 
    }
} 

