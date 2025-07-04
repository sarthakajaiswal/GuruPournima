#include "lights.h" 

// global variables 
GLfloat lightAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f}; 
GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f}; 
GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f}; 
GLfloat lightPosition[] = {10.0f, 0.0f, 10.0f, 1.0f}; 

GLfloat materialAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f}; 
// GLfloat materialDiffuse[] = {0.5f ,0.2f, 0.7f, 1.0f}; 
GLfloat materialDiffuse[] = {1.0f, 0.0f, 0.0f, 1.0f}; 
GLfloat materialSpecular[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat materialShininess[] = {128.0f}; 

GLfloat lightAmbient2[] = {0.0f, 0.0f, 0.0f, 1.0f}; 
GLfloat lightDiffuse2[] = {1.0f, 1.0f, 1.0f, 1.0f}; 
GLfloat lightSpecular2[] = {1.0f, 1.0f, 1.0f}; 
GLfloat lightPosition2[] = {-10.0f, 0.0f, 10.0f, 1.0f}; 

GLfloat materialAmbient2[] = {0.0f, 0.0f, 0.0f, 1.0f}; 
GLfloat materialDiffuse2[] = {0.0f ,1.0f, 0.0f, 1.0f}; 
GLfloat materialSpecular2[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat materialShininess2[] = {128.0f}; 

void initLights(void) 
{
    // light and material configuration 

    // light1 
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse); 
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular); 
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition); 
    glEnable(GL_LIGHT0); 

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular); 
    glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess); 

    // light2 
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient2); 
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse2); 
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular2); 
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2); 
    glEnable(GL_LIGHT1); 

    // glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient2); 
    // glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse2); 
    // glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular2); 
    // glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess2); 
} 
