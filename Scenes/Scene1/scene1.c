#include "scene1.h" 

#define DEPTH_OF_ALPHABETS  2.0f 
// #define WIDTH_OF_ALPHABETS  0.3f 

extern FILE* gpFile; 
extern unsigned long long mainTimer; 

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
void (*scene1AlphabetFunctionsOfFrustum[7])(void) = {f, r, u, s, t, u, m};
void (*scene1AlphabetFunctionsOfPresents[8])(void) = {p, r, e, s, e, n, t, s};

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
size_t current_index = 0; 
void displayScene1(void) 
{
    // function declarations 
    float translate = -19.5f; 

    // code 
    // draw atromedicomp 
    if(mainTimer > 5000)
    {
        glPushMatrix(); 
        glTranslatef(-19.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[0](); 
        a(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 20000)
    {
        glPushMatrix(); 
        glTranslatef(-16.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[1](); 
        s(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(-13.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[2](); 
        t(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(-10.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        r(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(-7.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        o(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(-4.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        m(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(-1.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        e(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(1.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        d(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(4.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        i(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(7.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        c(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(11.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        o(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(14.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        m(); 
        glPopMatrix(); 
    } 
    if(mainTimer > 25000)
    {
        glPushMatrix(); 
        glTranslatef(17.5f, 4.0f, 0.0f); 
        // scene1AlphabetFunctionsOfAstromedicomp[i](); 
        p(); 
        glPopMatrix(); 
    } 


    // draw frustum  
    // translate = -13.5f; 
    // for(size_t i = 0; i < 7; ++i) 
    // {
    //     glPushMatrix(); 
    //     glTranslatef(translate, 0.0f, 0.0f); 
    //     scene1AlphabetFunctionsOfFrustum[i](); 
    //     glPopMatrix(); 

    //     translate += 3.0f; 
    // } 

    // // draw 6.0 
    // glPushMatrix(); 
    // glTranslatef(translate + 2.0f, 0.0f, 0.0f); 
    // six(); 
    // glPopMatrix(); 

    // glPushMatrix(); 
    // glTranslatef(translate + 4.0f, -0.8f, 0.0f); 
    // gluSphere(scene1quadric, 0.3f, 8, 8); 
    // glPopMatrix(); 

    // glPushMatrix(); 
    // glTranslatef(translate + 5.5f, 0.0f, 0.0f); 
    // o(); 
    // glPopMatrix(); 

    // translate = -16.5f;
    // for(size_t i = 0; 
    //     i < sizeof(scene1AlphabetFunctionsOfPresents)/sizeof(scene1AlphabetFunctionsOfPresents[0]); 
    //     ++i
    // ) {
    //     glPushMatrix(); 
    //     glTranslatef(translate, -5.0f, 0.0f); 
    //     scene1AlphabetFunctionsOfPresents[i](); 
    //     glPopMatrix(); 

    //     translate += 3.0f; 
    // } 
} 

void updateScene1(void) 
{
} 

void uninitializeScene1(void) 
{
    if(scene1quadric) 
    {
        gluDeleteQuadric(scene1quadric); 
        scene1quadric = NULL; 
    } 
}

