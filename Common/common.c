#include "common.h" 

#include "stb_image.h" 

extern FILE* gpFile; 

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

BOOL loadGLPngTexture(GLuint* texture, char* file) 
{
    // variable declarations 
    int w, h, comp; 
    unsigned char* image = stbi_load(file, &w, &h, &comp, 4); 

    // code 
    if(image == NULL) 
    {
        fprintf(gpFile, "failed to load image : %s\n", file);
        return (FALSE); 
    }

    glGenTextures(1, texture); 
    glBindTexture(GL_TEXTURE_2D, *texture); 
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image); 

    glBindTexture(GL_TEXTURE_2D, 0); 
    stbi_image_free(image); 

    fprintf(gpFile, "Image loaded succesfully: %s (%dX%d)\n", file, w, h); 
    return (TRUE); 
} 
