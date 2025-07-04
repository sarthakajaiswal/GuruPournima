#include "common.h" 

void cubeFromQuad(struct Quad* quad, float depth) 
{
    // variable declarations 
    float z = depth/2.0f; 

    // code 
    glBegin(GL_QUADS); 

    // front 
    glNormal3f(0.0f, 0.0f, 1.0f); 
    glTexCoord2f(1.0f, 1.0f); 
    glVertex3f(quad->p1x, quad->p1y, z); 
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(quad->p2x, quad->p2y, z); 
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(quad->p3x, quad->p3y, z); 
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(quad->p4x, quad->p4y, z); 

    // right 
    glNormal3f(1.0f, 0.0f, 0.0f); 
    glTexCoord2f(1.0f, 1.0f); 
    glVertex3f(quad->p1x, quad->p1y, -z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(quad->p1x, quad->p1y, z); 
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(quad->p4x, quad->p4y, z); 
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(quad->p4x, quad->p4y, -z); 

    // back 
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); 
    glVertex3f(quad->p2x, quad->p2y, -z); 
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(quad->p1x, quad->p1y, -z); 
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(quad->p4x, quad->p4y, -z); 
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(quad->p3x, quad->p3y, -z); 

    // left 
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); 
    glVertex3f(quad->p2x, quad->p2y, z); 
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(quad->p2x, quad->p2y, -z); 
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(quad->p3x, quad->p3y, -z); 
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(quad->p3x, quad->p3y, z); 

    // top 
    glNormal3f(0.0f, 1.0f, 0.0f); 
    glTexCoord2f(1.0f, 1.0f); 
    glVertex3f(quad->p1x, quad->p1y, -z); 
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(quad->p2x, quad->p2y, -z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(quad->p2x, quad->p2y, z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(quad->p1x, quad->p1y, z);
    
    // bottom 
    glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); 
    glVertex3f(quad->p3x, quad->p3y, z); 
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(quad->p4x, quad->p4y, z); 
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(quad->p3x, quad->p3y, -z); 
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(quad->p4x, quad->p4y, -z);
    
    glEnd(); 
} 
