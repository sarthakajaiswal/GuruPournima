#include "boy.h" 

GLUquadric* boyQuadric; 

extern FILE* gpFile; 
extern float tx, ty, tz, sx, sy, sz, rx, ry, rz; 

static GLfloat legAngle; 
static GLfloat flameHeightForAnimation; 

static GLuint texture_face; 
static GLuint texture_jeans; 
static GLuint texture_tshirt; 
static GLuint texture_wood; 

extern float legUpdateSpeed;  

int initializeBoy(void) 
{
    // code 
    boyQuadric = gluNewQuadric(); 
    if(boyQuadric == NULL) 
    {
        fprintf(gpFile, "failed to get new quadric for boy\n"); 
        return (-1); 
    }

    if(!loadGLPngTexture(&texture_face, "Resources/human_face.png"))
    {
        fprintf(gpFile, "Failed to load face texture for boy model\n");
        return (-2);  
    }

    if(!loadGLPngTexture(&texture_jeans, "Resources/jeans.png"))
    {
        fprintf(gpFile, "Failed to load jeans texture for boy model\n");
        return (-3);  
    }

    if(!loadGLPngTexture(&texture_tshirt, "Resources/tshirt.png"))
    {
        fprintf(gpFile, "Failed to load tshirt texture for boy model\n");
        return (-4);  
    }

    if(!loadGLPngTexture(&texture_wood, "Resources/wood.png"))
    {
        fprintf(gpFile, "Failed to load face texture for lamp\n");
        return (-5);  
    }

    return (0); 
} 

void displayBoy(void) 
{
    // code 
    drawTexturedCube(0.0, 0.00, 0.00, 1.15, 2.05, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt);  // body 
    
    glTranslatef(0.0f, -1.025f, 0.0f); // to take matrix at the position where leg starts (for proper rotation to walk)
    glPushMatrix(); 
    {
        glRotatef(legAngle, 1, 0, 0); 
        // left leg 
        drawTexturedCube(-0.55, -3.0, 0.00, 0.35, 2.20, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans);  // leg 
        drawTexturedCube(-0.55, -5.40, -0.25, 0.35, 0.25, 0.70, 1.0f, 0.0f, 0.0f, FACE_ALL, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans);  // shoes 
    }
    glPopMatrix(); 

    glPushMatrix(); 
    {
        glRotatef(legAngle, -1, 0, 0); 
        // right leg 
        drawTexturedCube(0.55, -3.0, 0.00, 0.35, 2.20, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans);  // leg 
        drawTexturedCube(0.55, -5.40, -0.25, 0.35, 0.25, 0.70, 1.0f, 0.0f, 0.0f, FACE_ALL, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans, texture_jeans);  // shoes 
    } 
    glPopMatrix();  

    glTranslatef(0.0f, 2.05,0.0f); // to take matrix at neck position 
    glPushMatrix(); 
    {
        glTranslatef(0.00, 1.90, 0.00); 
        glScalef(1.00, 1.15, 0.95);  

        glEnable(GL_TEXTURE_2D); 
        glBindTexture(GL_TEXTURE_2D, texture_face); 
        gluSphere(boyQuadric, 0.70, 16, 16); 
        glBindTexture(GL_TEXTURE_2D, 0); 
    } 
    glPopMatrix(); 

    // left hand 
    glTranslatef(-1.45, -1.35, 0.00); // to take matrix at left shoulder (shoulder and hand joint)
    glPushMatrix();     // push matrix so that rotation will be applied to left hand only  
    {
        glRotatef(legAngle, -1, 0, 0);    // to rotate hand similar to right leg 
        drawTexturedCube(0.0f, 0.0f, 0.0f, 0.20, 2.35, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt);  // hand 
    } 
    glPopMatrix(); 

    // lamp 
    glTranslatef(2.90, 0.0, 0.00); // to take matrix at right shoulder 
    glPushMatrix(); 
    {
        glRotatef(3.15, 0, 0, 1); 
        drawTexturedCube(0.0f, 0.0f, 0.0f, 0.20, 2.35, 0.40, 1.0f, 1.0f, 1.0f, FACE_ALL, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt, texture_tshirt);  // right hand 

        glRotatef(-3.15, 0, 0, 1); // to restore the angle to 0 that was incresed for drawing hand little crossed 
        glPushMatrix(); 
        {
            // base for flame 
            drawPyramid(0.15, -3.60, -0.00, 0.35, 0.30, 0.35, 0.0f, 1.0f, 0.0f, 1.0f, 0);   

            // top cover 
            glBindTexture(GL_TEXTURE_2D, texture_wood); 
            drawPyramid(0.15, -2.50, -0.00, 0.40, 0.30, 0.35, 0.0f, 1.0f, 1.0f, 1.0f, 1.0);   
            glBindTexture(GL_TEXTURE_2D, 0); 

            // flame 
            glPushMatrix(); 
            {
                glTranslatef(0.15, -3.06-flameHeightForAnimation, 0.00); 
                glRotatef(90, 1, 0, 0); 
                glColor3f(1, 1, 0); 
                gluCylinder(boyQuadric, 0.00, 0.15, 0.40+flameHeightForAnimation, 8, 8);  
            }
            glPopMatrix(); 

            // outer cover 
            glEnable(GL_BLEND); 
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
            glPushMatrix(); 
            glTranslatef(0.15, -2.80, 0.00); 
            glRotatef(90, 1, 0, 0); 
            glColor4f(0.0f, 0.0f, 1.0f, 0.2f); 
            gluCylinder(boyQuadric, 0.50, 0.50, 1.10, 8, 8);  
            glPopMatrix(); 
            glDisable(GL_BLEND); 
        } 
        glPopMatrix(); 
    } 
    glPopMatrix(); 

    // drawTexturedCube(tx, ty, tz, sx, sy, sz, 1.0f, 1.0f, 1.0f, FACE_ALL, 0, 0, 0, 0, 0, 0);  // hand   
} 

void updateBoy(void) 
{
    // code 
    static BOOL legAngleFlag = TRUE;  
    static BOOL flameHeightFlag = TRUE; 
    float flameHeightStep = 0.0005f; 

    // leg and hand animation 
    if(legAngleFlag) 
    {
        legAngle -= legUpdateSpeed; 

        if(legAngle < -16.0f)
            legAngleFlag = FALSE; 

    }
    else 
    {
        legAngle += legUpdateSpeed; 

        if(legAngle > 16.0f)
            legAngleFlag = TRUE; 
    }

    // flame animation 
    if(flameHeightFlag) 
    {
        flameHeightForAnimation -= flameHeightStep; 

        if(flameHeightForAnimation < -0.05f)
            flameHeightFlag = FALSE; 

    }
    else 
    {
        flameHeightForAnimation += flameHeightStep; 

        if(flameHeightForAnimation > 0.05f)
            flameHeightFlag = TRUE; 
    }
} 

void uninitializeBoy(void) 
{
    // code 
    if(texture_wood) 
    {
        glDeleteTextures(1, &texture_wood); 
        texture_wood = 0; 
    } 
    if(texture_tshirt) 
    {
        glDeleteTextures(1, &texture_tshirt); 
        texture_tshirt = 0; 
    } 
    if(texture_jeans) 
    {
        glDeleteTextures(1, &texture_jeans); 
        texture_jeans = 0; 
    } 
    if(texture_face) 
    {
        glDeleteTextures(1, &texture_face); 
        texture_face = 0; 
    } 

    if(boyQuadric)
    {
        gluDeleteQuadric(boyQuadric); 
        boyQuadric = NULL; 
    }
} 
