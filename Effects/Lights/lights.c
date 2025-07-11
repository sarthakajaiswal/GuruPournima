#include "lights.h" 

extern float lightTranslationSpeed; 

// global variables  
// red 
GLfloat lightAmbient0[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat lightDiffuse0[] = {1.0f, 0.0f, 0.0f, 1.0f}; 
GLfloat lightSpecular0[] = {1.0f, 0.0f, 0.0f}; 
GLfloat lightPosition0[] = {-20.0f, 0.0f, 20.0f, 1.0f}; 

// green 
GLfloat lightAmbient1[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
GLfloat lightDiffuse1[] = {0.0f, 1.0f, 0.0f, 1.0}; 
GLfloat lightSpecular1[] = {0.0f, 1.0f, 0.0f};  
GLfloat lightPosition1[] = {20.0f, 0.0f, 20.0f, 1.0f}; 

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

    // light1 
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient1); 
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse1); 
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular1); 
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1); 
    
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

void updateLights() 
{
    static BOOL light0flag = TRUE; 
    static BOOL light1flag = TRUE; 

    // light0 
    if(light0flag) 
    {
        lightPosition0[0] += lightTranslationSpeed; 
        if(lightPosition0[0] > 20.0f) 
            light0flag = FALSE; 
    } 
    else 
    {
        lightPosition0[0] -= lightTranslationSpeed; 
        if(lightPosition0[0] < -20.0f) 
            light0flag = TRUE; 
    }

    // light1 
    if(light1flag) 
    {
        lightPosition1[0] -= lightTranslationSpeed; 
        if(lightPosition1[0] < -20.0f) 
            light1flag = FALSE; 
    } 
    else 
    {
        lightPosition1[0] += lightTranslationSpeed; 
        if(lightPosition1[0] > 20.0f) 
            light1flag = TRUE; 
    }

    // update light positions 
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0); 
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1); 
}

