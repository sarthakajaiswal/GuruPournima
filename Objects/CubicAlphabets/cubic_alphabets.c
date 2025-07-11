#include "cubic_alphabets.h" 
#include "../../Common/common.h" 

extern float DEPTH_OF_ALPHABETS; 

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

void point(void) 
{
    struct Quad quads[] = {
        // p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, {r, g, b, a}
        {1.0f, -0.8f, 0.8f, -0.8f, 0.8f, -1.0, 1.0f, -1.0, {1.0f, 1.0f, 1.0f, 1.0f}}, 
    }; 

    for(size_t i = 0; i < sizeof(quads)/sizeof(quads[0]); ++i) 
        cubeFromQuad(quads+i, DEPTH_OF_ALPHABETS);   
} 
