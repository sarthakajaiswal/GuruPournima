#include "peackock.h"

extern FILE* gpFile; 
extern float tx, ty, tz, sx, sy, sz, rx, ry, rz;  

GLUquadric* peackockQuadric; 
GLuint texture_feathers; 
GLuint texture_grass; 
GLuint texture_saturn; 

float translation_speed; 
float positionX; 

// feather animation related variables 
static float featherX, featherY, featherZ; 
static float featherSx, featherSy, featherSz; 
static float featherRx, featherRy, featherRz; 

// leg animation related variables 
static float leftLegThighRy, leftLegCalfRy; 
static float rightLegThighRy, rightLegCalfRy; 
static BOOL isLeftLegAnimating, isRightLegAnimating; 
static BOOL showingFeathers = FALSE; 


void initPeackock(void) 
{
    peackockQuadric = gluNewQuadric(); 
    if(peackockQuadric == NULL) 
    {
        fprintf(gpFile, "Failed to create peackock quadric"); 
        uninitialize(); 
        exit(EXIT_FAILURE); 
    }

    if(loadGLPngTexture(&texture_feathers, "Resources/peackock_feathers3.png") == FALSE) 
    {
        fprintf(gpFile, "failed to load peackock feathers texture"); 
        exit(EXIT_FAILURE); 
    }
    if(loadGLPngTexture(&texture_grass, "Resources/peackock_feathers3.png") == FALSE) 
    {
        fprintf(gpFile, "failed to load peackock feathers texture"); 
        exit(EXIT_FAILURE); 
    }

    gluQuadricDrawStyle(peackockQuadric, GLU_FILL); 
    gluQuadricTexture(peackockQuadric, TRUE);
    gluQuadricNormals(peackockQuadric, GLU_SMOOTH);

    // shepti 
    featherX = -0.55; featherY = 6.45; featherZ = 0.30; 
    featherSx = 1.30; featherSy = 6.35; featherSz = 6.30;  
    featherRx = 0.0; featherRy = 0.0; featherRz = 102.50;

    // // pisara 
    // featherX = -2.25; featherY = 5.80; featherZ = 5.20; 
    // featherSx = 1.0; featherSy = 8.40; featherSz = 5.30;  
    // featherRx = 0.0; featherRy = 90.0; featherRz = 0.0;

    positionX = 0.0f; 
    translation_speed = 1.0f; 

    setStandingPosition(); 
} 

void uninitializePeackock(void) 
{
    if(peackockQuadric) 
    {
        gluDeleteQuadric(peackockQuadric); 
        peackockQuadric = NULL; 
    } 
} 

void displayPeackock(void) 
{
    if(isLeftLegAnimating || isRightLegAnimating)
    {
        glPushMatrix(); 
        glTranslatef(positionX, 0.0f, 0.0f); 

        // stomach 
        glBindTexture(GL_TEXTURE_2D, texture_grass); 
        glColor3f(1.0f, 1.0f, 1.0f); 
        glPushMatrix(); 
        {
            glRotatef(11.50f, 0, 0, 1); 
            glScalef(1.88f, 1.0f, 1.0f); 
            gluSphere(peackockQuadric, 2.0f, 16, 16); 
        } 
        glPopMatrix(); 
        glBindTexture(GL_TEXTURE_2D, 0); 

        // neck and head 
        glColor3f(0.0f, 1.0f, 0.0f);
        glPushMatrix(); 
        {
            // cylinder 1 
            glTranslatef(1.95, 0.0, 0.0); 
            glRotatef(-90, 1, 0, 0); 
            glRotatef(50.0f, 0, 1, 0); 
            gluCylinder(peackockQuadric, 1.2, 0.25, 4.0, 10, 10);  

            // cylinder 2 
            glTranslatef(0.0f, 0.0f, 3.8f); 
            glPushMatrix();   
            {
                glRotatef(-25.0, 0, 1, 0); 
                gluCylinder(peackockQuadric, 0.27, 0.3, 0.8, 10, 10);  

                // head 
                glTranslatef(0.0f, 0.0f, 0.75f); 
                glPushMatrix();   
                {      
                    glTranslatef(0.20, 0.0, -0.05); 
                    glRotatef(-27.0, 1, 0, 0); 
                    glScalef(1.55, 0.80, 0.85); 
                    glColor3f(1.0f, 0.0f, 1.0f);  
                    gluSphere(peackockQuadric, 0.5, 10, 10); 

                    // beak 
                    glTranslatef(0.25f, 0.0f, 0.0f); 
                    glPushMatrix();         
                    {
                        glRotatef(-90, 0, 0, 1);
                        drawPyramid(0.0, 0.35, 0.0, 0.30, 0.25, 0.15, 1.0f, 1.0f, 1.0f, 1.0f, 0); 
                    } 
                    glPopMatrix(); 
                }
                glPopMatrix(); 
            }
            glPopMatrix(); 
        } 
        glPopMatrix(); 


        // feathers 
        glEnable(GL_BLEND); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        drawFeather(); 
        glDisable(GL_BLEND); 

        // legs 
        drawLeg(leftLegThighRy, leftLegCalfRy); 
        glPushMatrix(); 
            glTranslatef(0.0f, 0.0f, 0.5f); 
            drawLeg(rightLegThighRy, rightLegCalfRy); 
        glPopMatrix(); 

        glPopMatrix(); 
    }  
} 

/*
Pisara : 
-2.25, 5.80, 7.30  
1.0, 8.40, 5.30 
0.0, 90.0, 0.0 

Shepti : 

-0.55, 6.45, 0.30  
1.30, 6.35, 6.30 
0.0, 0.0, 102.50 

*/

void drawFeather(void) 
{ 
    glPushMatrix(); 
    {
        glRotatef(featherRz, 0, 0, 1);   
        glPushMatrix(); 
        {
            glTranslatef(featherX, featherY, featherZ);  
            glScalef(featherSx, featherSy, featherSz);
            glRotatef(featherRy, 0, 1, 0);  
            
            glBindTexture(GL_TEXTURE_2D, texture_feathers); 
            glColor3f(1.0f, 1.0f, 1.0f); 
            glBegin(GL_QUADS);
            glTexCoord2f(0.5f, 1.0f); 
            glVertex3f(1.0f, 1.0f, 0.0f);  // right-top 
            glTexCoord2f(0.0f, 1.0f); 
            glVertex3f(-1.0f, 1.0f, 0.0f); // left-top 
            glTexCoord2f(0.0f, 0.0f); 
            glVertex3f(-1.0f, -1.0f, 0.0f);	// left-bottom 
            glTexCoord2f(0.5f, 0.0f); 
            glVertex3f(1.0f, -1.0f, 0.0f);	// right-bottom 
            glEnd(); 
            glBindTexture(GL_TEXTURE_2D, 0); 
        }
        glPopMatrix();  
    }
    glPopMatrix(); 

    glPushMatrix(); 
    {
        glRotatef(featherRz, 0, 0, 1);   
        glScalef(1.0f, 1.0f, -1.0f); 
        glPushMatrix(); 
        {
            glTranslatef(featherX, featherY, featherZ);
            glScalef(featherSx, featherSy, featherSz);
            glRotatef(featherRy, 0, 1, 0);  

            glBindTexture(GL_TEXTURE_2D, texture_feathers); 
            glColor3f(1.0f, 1.0f, 1.0f); 
            glBegin(GL_QUADS);
            glTexCoord2f(0.5f, 1.0f); 
            glVertex3f(1.0f, 1.0f, 0.0f);  // right-top 
            glTexCoord2f(0.0f, 1.0f); 
            glVertex3f(-1.0f, 1.0f, 0.0f); // left-top 
            glTexCoord2f(0.0f, 0.0f); 
            glVertex3f(-1.0f, -1.0f, 0.0f);	// left-bottom 
            glTexCoord2f(0.5f, 0.0f); 
            glVertex3f(1.0f, -1.0f, 0.0f);	// right-bottom 
            glEnd(); 
            glBindTexture(GL_TEXTURE_2D, 0); 
        }
        glPopMatrix();  
    } 
    glPopMatrix(); 
}

void drawLeg(float thighAngle, float calfAngle) 
{
    glPushMatrix();         
        glTranslatef(0.30, -1.80, -0.5); 
        glRotatef(90.0, 1, 0, 0); 
        glRotatef(thighAngle, 0, 1, 0); 
        glColor3f(1.0f, 0.0f, 1.0f);  
        gluCylinder(peackockQuadric, 0.2, 0.2, 1.6, 8, 8); 

        glTranslatef(0.0f, 0.0f, 1.45f);
        glPushMatrix(); 
        glRotatef(calfAngle, 0, 1, 0); 
        glColor3f(1.0f, 0.0f, 1.0f);  
        gluCylinder(peackockQuadric, 0.2, 0.1, 2.0, 8, 8); 
        glPopMatrix(); 
    glPopMatrix(); 
}

void updatePeackock(void) 
{
    // variable declarations 
    const float inverse_speed_constant_for_feathers = 1000.0; 

    // code 
    // feathers animation 
    if(showingFeathers == TRUE && featherX > -2.25) 
    {
        featherX -= (-0.55-(-2.25))/inverse_speed_constant_for_feathers; 
        featherY -= (6.45-5.80)/inverse_speed_constant_for_feathers; 
        featherZ += (7.30-0.30)/inverse_speed_constant_for_feathers; 
        
        featherSx -= (1.30-1.0)/inverse_speed_constant_for_feathers; 
        featherSy += (8.40-6.35)/inverse_speed_constant_for_feathers; 
        featherSz += (6.30-5.30)/inverse_speed_constant_for_feathers;  
        
        featherRy += (90.0-0.0)/inverse_speed_constant_for_feathers; 
        featherRz -= (102.50-0.0)/inverse_speed_constant_for_feathers;
    }

    // leftLeg animation 
    isLeftLegAnimating = TRUE;      // either left or right animates at a time 
    isRightLegAnimating = FALSE;    // either left or right animates at a time 
    static BOOL leftLegFlag = FALSE; 
    
    if(isLeftLegAnimating) 
    {
        if(leftLegThighRy > -42.0 && leftLegFlag == FALSE) 
        {
            leftLegThighRy -= 0.02; 
            leftLegCalfRy += 0.05; 

            if(leftLegThighRy <= -42.0) 
                leftLegFlag = TRUE; 
        }
        else 
        {
            leftLegThighRy += 0.02; 
            leftLegCalfRy -= 0.05;
            if(leftLegThighRy >= -20.0f) 
            {
                leftLegFlag = FALSE; 
                isLeftLegAnimating = FALSE; 
                isRightLegAnimating = TRUE; 
            } 
        }

        positionX += translation_speed * 0.001; 
    } 

    // rightLeg animation 
    static BOOL rightLegFlag = TRUE; 
    if(isRightLegAnimating) 
    {
        if(rightLegThighRy > -42.0 && rightLegFlag == FALSE) 
        {
            rightLegThighRy -= 0.02; 
            rightLegCalfRy += 0.05; 

            if(rightLegThighRy <= -42.0) 
                rightLegFlag = TRUE; 
        }
        else 
        {
            rightLegThighRy += 0.02; 
            rightLegCalfRy -= 0.05;
            if(rightLegThighRy >= -20.0f) 
            {
                rightLegFlag = FALSE; 
                isRightLegAnimating = FALSE; 
                isLeftLegAnimating = TRUE; 
            } 
        }

        positionX += translation_speed * 0.001; 
    } 
} 

void setStandingPosition() 
{
    // standing leg position 
    leftLegThighRy = -20.0;
    leftLegCalfRy = 63.50f; 
    
    rightLegThighRy = -20.0;
    rightLegCalfRy = 63.50f; 
}

