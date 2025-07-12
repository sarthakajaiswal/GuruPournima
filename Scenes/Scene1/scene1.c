#include "scene1.h" 

extern FILE* gpFile; 
extern unsigned long long mainTimer; 
extern float DEPTH_OF_ALPHABETS; 
extern float cameraX, cameraY, cameraZ, cameraCenterX, cameraCenterY, cameraCenterZ; 
extern float tx, ty, tz; 
extern short shotNumber; 

extern unsigned int beat01time, beat02time, beat03time, beat04time, beat05time, beat06time, beat07time, beat08time, beat09time, beat10time, beat11time, beat12time, beat13time, beat14time, beat15time; 

void initScene1(void) 
{
    // code 
}

void displayScene1(void) 
{
    // function declarations 
    static BOOL isThisFirstCall = TRUE; 
    static float astromedicompPositionY = 0.80f; 
    static BOOL readyToFadeOut = FALSE; // when true fade-out starts 

    // code 
    if(isThisFirstCall)
    {
        cameraX = -1.80; 
        cameraY = 1.80; 
        cameraZ = 28.00;
        
        cameraCenterX = -1.40; 
        cameraCenterY = -0.20f; 
        cameraCenterZ = -10.0f; 
        
        glEnable(GL_LIGHTING); 
        glEnable(GL_LIGHT0); 
        glEnable(GL_LIGHT1); 

        isThisFirstCall = FALSE; 
    }

    fprintf(gpFile, "In scene1::display()\n"); 

    // draw atromedicomp 
    if(mainTimer > beat01time)
    {
        glPushMatrix(); 
        glTranslatef(-19.5f, astromedicompPositionY, 0.0f); 
        a(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat02time)
    {
        glPushMatrix(); 
        glTranslatef(-16.5f, astromedicompPositionY, 0.0f); 
        s(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat03time)
    {
        glPushMatrix(); 
        glTranslatef(-13.5f, astromedicompPositionY, 0.0f); 
        t(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat04time)
    {
        glPushMatrix(); 
        glTranslatef(-10.5f, astromedicompPositionY, 0.0f); 
        r(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat05time)
    {
        glPushMatrix(); 
        glTranslatef(-7.5f, astromedicompPositionY, 0.0f); 
        o(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat06time)
    {
        glPushMatrix(); 
        glTranslatef(-4.5f, astromedicompPositionY, 0.0f); 
        m(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat07time)
    {
        glPushMatrix(); 
        glTranslatef(-1.5f, astromedicompPositionY, 0.0f); 
        e(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat08time)
    {
        glPushMatrix(); 
        glTranslatef(1.5f, astromedicompPositionY, 0.0f); 
        d(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat09time)
    {
        glPushMatrix(); 
        glTranslatef(4.5f, astromedicompPositionY, 0.0f); 
        i(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat10time)
    {
        glPushMatrix(); 
        glTranslatef(7.5f, astromedicompPositionY, 0.0f); 
        c(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat11time)
    {
        glPushMatrix(); 
        glTranslatef(10.5f, astromedicompPositionY, 0.0f); 
        o(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat12time)
    {
        glPushMatrix(); 
        glTranslatef(13.5f, astromedicompPositionY, 0.0f); 
        m(); 
        glPopMatrix(); 
    } 
    if(mainTimer > beat13time)
    {
        glPushMatrix(); 
        glTranslatef(16.5f, astromedicompPositionY, 0.0f); 
        p(); 
        glPopMatrix(); 
    } 
} 

void updateScene1(void) 
{
    // code 
    fprintf(gpFile, "In scene1::update() : timer = \n", mainTimer); 
    if(mainTimer > beat14time) 
        updateLights(); 

    if(mainTimer > beat15time) 
        shotNumber++; 
} 

void uninitializeScene1(void) 
{
    // code 
} 

