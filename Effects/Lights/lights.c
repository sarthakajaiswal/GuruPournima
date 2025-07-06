#include "lights.h" 

// global variables  
GLfloat lightAmbient0[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat lightDiffuse0[] = {255.0/255.0, 0.0f, 0.0/255.0, 1.0f}; 
GLfloat lightSpecular0[] = {255.0/255.0, 0.0f, 0.0/255.0}; 
GLfloat lightPosition0[] = {-20.0f, -20.0f, 20.0f, 1.0f}; 

GLfloat lightAmbient1[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat lightDiffuse1[] = {0.0/255.0, 255.0f/255.0, 0.0/255.0, 1.0}; 
GLfloat lightSpecular1[] = {0.0/255.0, 255.0f/255.0, 0.0/255.0};  
GLfloat lightPosition1[] = {20.0f, -20.0f, 20.0f, 1.0f}; 

GLfloat lightAmbient2[] = {0.0f, 0.0f, 0.0f, 1.0f}; 
GLfloat lightDiffuse2[] = {72.0/255.0, 157.0/255.0, 158.0/255.0, 1.0f}; 
GLfloat lightSpecular2[] = {72.0/255.0, 157.0/255.0, 158.0/255.0};  
GLfloat lightPosition2[] = {0.0f, 0.0f, 20.0f, 1.0f}; 

GLfloat materialAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f}; 
GLfloat materialDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat materialSpecular[] = {0.7f, 0.7f, 0.7f, 1.0f}; 
GLfloat materialShininess[] = {128.0f}; 

void initLights(void) 
{
    // light and material configuration 
    // light0
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient0); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse0); 
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular0); 
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0); 
    glEnable(GL_LIGHT0); 

    // light1 
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient1); 
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse1); 
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular1); 
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1); 
    glEnable(GL_LIGHT1);
    
    // light2 
    glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbient2); 
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffuse2); 
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpecular2); 
    glLightfv(GL_LIGHT2, GL_POSITION, lightPosition2); 
    glEnable(GL_LIGHT2);

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular); 
    glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess); 
} 
