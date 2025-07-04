#include "scene1.h" 

#define DEPTH_OF_ALPHABETS  1.0f 
// #define WIDTH_OF_ALPHABETS  0.3f 

extern FILE* gpFile; 

float angle=0.0f; 

void a(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {0.15f, 1.0f, -0.15f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {0.15f, 1.0f, -0.15f, 1.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void t(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {0.15f, 1.0f, -0.15f, 1.0f, -0.15f, -1.0f, 0.15f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void m(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {0.15f, 1.0f, -0.15f, 1.0f, -0.15f, -1.0f, 0.15f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, 0.7f, 1.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}  
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void e(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {0.0f, 0.15f, -1.0f, 0.15f, -1.0f, -0.15f, 0.0f, -0.15f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void i(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {0.15f, 1.0f, -0.15f, 1.0f, -0.15f, -1.0f, 0.15f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void p(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, 0.7f, 1.0f, 0.7f, 0.0f, 1.0f, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 0.15f, -1.0f, 0.15f, -1.0f, -0.15f, 1.0f, -0.15f, {1.0f, 1.0f, 1.0f, 1.0f}} 
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void r(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, 0.7f, 1.0f, 0.7f, 0.0f, 1.0f, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 0.15f, -1.0f, 0.15f, -1.0f, -0.15f, 1.0f, -0.15f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {0.5f, 0.0f, 0.2f, 0.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}  
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void o(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, 0.7f, 1.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}  
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void s(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, 0.0f, -0.7f, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 0.15f, -1.0f, 0.15f, -1.0f, -0.15f, 1.0f, -0.15f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 0.0f, 0.7f, 0.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);     
} 

void d(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {-0.4f, 1.0f, -0.7f, 1.0f, -0.7f, -1.0f, -0.4f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, 0.7f, 1.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}  
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void c(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}} 
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void f(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {0.0f, 0.15f, -1.0f, 0.15f, -1.0f, -0.15f, 0.0f, -0.15f, {1.0f, 1.0f, 1.0f, 1.0f}} 
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void u(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, 0.7f, 1.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}  
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
} 

void n(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {-0.7f, 1.0f, -1.0f, 1.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 1.0f, 0.7f, 1.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}  
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);  
}

void six(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 0.7f, 1.0f, 0.7f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {-0.7f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -0.7f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 0.15f, -1.0f, 0.15f, -1.0f, -0.15f, 1.0f, -0.15f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, 0.0f, 0.7f, 0.0f, 0.7f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}, 
        {1.0f, -0.7f, -1.0f, -0.7f, -1.0f, -1.0f, 1.0f, -1.0f, {1.0f, 1.0f, 1.0f, 1.0f}}
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);    
}

void (*scene1AlphabetFunctionsOfAstromedicomp[13])(void) = {a, s, t, r, o, m, e, d, i, c, o, m, p}; 
void (*scene1AlphabetFunctionsOfFrustum[17])(void) = {f, r, u, s, t, u, m};

GLUquadric* scene1quadric = NULL; 
void initScene1(void) 
{
    // code 
    scene1quadric = gluNewQuadric(); 
    if(scene1quadric == NULL) 
    {
        fprintf(gpFile, "failed to create quadric for scene1\n"); 
        uninitialize(); 
        exit(EXIT_FAILURE); 
    }
}

float translate; 
void displayScene1(void) 
{
    // function declarations 
    // code 

    // draw atromedicomp 
    translate = -19.5f; 
    for(size_t i = 0; i < 13; ++i) 
    {
        glPushMatrix(); 
        glTranslatef(translate, 4.0f, 0.0f); 
        scene1AlphabetFunctionsOfAstromedicomp[i](); 
        glPopMatrix(); 

        translate += 3.0f; 
    } 

    // draw frustum  
    translate = -13.5f; 
    for(size_t i = 0; i < 7; ++i) 
    {
        glPushMatrix(); 
        glTranslatef(translate, 0.0f, 0.0f); 
        scene1AlphabetFunctionsOfFrustum[i](); 
        glPopMatrix(); 

        translate += 3.0f; 
    } 

    // draw 6.0 
    glPushMatrix(); 
    glTranslatef(translate + 2.0f, 0.0f, 0.0f); 
    six(); 
    glPopMatrix(); 

    glPushMatrix(); 
    glTranslatef(translate + 3.5f, -0.8f, 0.0f); 
    // gluSphere(scene1quadric, 1.0f, 1.0f, 1.0f); 
    glPopMatrix(); 

    // glPushMatrix(); 
    // glTranslatef(translate + 5.0f, 0.0f, 0.0f); 
    // o(); 
    // glPopMatrix(); 

} 

void updateScene1(void) 
{
    if(scene1quadric) 
    {
        gluDeleteQuadric(scene1quadric); 
        scene1quadric = NULL; 
    } 
} 

