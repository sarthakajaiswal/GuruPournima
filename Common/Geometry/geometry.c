#include "geometry.h"

void drawTexturedCube(
        float x, float y, float z, 
        float sx, float sy, float sz, 
        float r, float g, float b, 
        FaceType faces_to_be_textured, 
        GLuint texture_front, 
        GLuint texture_right, 
        GLuint texture_back, 
        GLuint texture_left, 
        GLuint texture_top, 
        GLuint texture_bottom
    ) 
{
    // code 
    glPushMatrix(); 
    {
        glTranslatef(x, y, z);  
        glScalef(sx, sy, sz); 
        glColor3f(r, g, b); 

        // front face  
        glNormal3f(0.0f, 0.0f, 1.0f); 
        glBindTexture(GL_TEXTURE_2D, texture_front); 
        glBegin(GL_QUADS); 
        if(faces_to_be_textured & FACE_FRONT)
            glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(1.0f, 1.0f, 1.0f); 

        if(faces_to_be_textured & FACE_FRONT) 
            glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(-1.0f, 1.0f, 1.0f);	 
        
        if(faces_to_be_textured & FACE_FRONT)
            glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, 1.0f);  
        
        if(faces_to_be_textured & FACE_FRONT)
            glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, 1.0f); 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0); 
        
        // right face 
        glNormal3f(1.0f, 0.0f, 0.0f); 
        glBindTexture(GL_TEXTURE_2D, texture_right); 
        glBegin(GL_QUADS); 
        if(faces_to_be_textured & FACE_RIGHT) 
            glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(1.0f, 1.0f, -1.0f); 	// right top 

        if(faces_to_be_textured & FACE_RIGHT)
            glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(1.0f, 1.0f, 1.0f);	// left top 

        if(faces_to_be_textured & FACE_RIGHT)
            glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, 1.0f);	// left bottom 

        if(faces_to_be_textured & FACE_RIGHT)
            glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, -1.0f); // right bottom  
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0); 
        
        // back face 
        glNormal3f(0.0f, 0.0f, -1.0f);
        glBindTexture(GL_TEXTURE_2D, texture_back); 
        glBegin(GL_QUADS); 
        if(faces_to_be_textured & FACE_BACK)
            glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(-1.0f, 1.0f, -1.0f);	 // right top 

        if(faces_to_be_textured & FACE_BACK)
            glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(1.0f, 1.0f, -1.0f);	 // left top 

        if(faces_to_be_textured & FACE_BACK)
            glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(1.0, -1.0, -1.0f); 	 // left bottom 

        if(faces_to_be_textured & FACE_BACK)
            glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, -1.0f); // right bottom  
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0); 
        
        // left face 
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glBindTexture(GL_TEXTURE_2D, texture_left); 
        glBegin(GL_QUADS); 
        if(faces_to_be_textured & FACE_LEFT)
            glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(-1.0f, 1.0f, 1.0f);	// right top 

        if(faces_to_be_textured & FACE_LEFT)
            glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(-1.0f, 1.0f, -1.0f);// left top 

        if(faces_to_be_textured & FACE_LEFT)
            glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, -1.0f); // left bottom 

        if(faces_to_be_textured & FACE_LEFT)
            glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, 1.0f); // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0); 

        // top face 
        glNormal3f(0.0f, 1.0f, 0.0f); 
        glBindTexture(GL_TEXTURE_2D, texture_top); 
        glBegin(GL_QUADS); 
        if(faces_to_be_textured & FACE_TOP)
            glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(1.0f, 1.0f, -1.0f); 	// right top 

        if(faces_to_be_textured & FACE_TOP)
            glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(-1.0f, 1.0f, -1.0f);	// left top 

        if(faces_to_be_textured & FACE_TOP)
            glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, 1.0f, 1.0f);	// left bottom 

        if(faces_to_be_textured & FACE_TOP)
            glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, 1.0f, 1.0f);   // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0); 
        
        // bottom face 
        glNormal3f(0.0f, -1.0f, 0.0f);
        glBindTexture(GL_TEXTURE_2D, texture_bottom); 
        glBegin(GL_QUADS); 
        if(faces_to_be_textured & FACE_BOTTOM)
            glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(1.0f, -1.0f, 1.0f);	// right top 

        if(faces_to_be_textured & FACE_BOTTOM)
            glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(-1.0f, -1.0f, 1.0f); // left top 

        if(faces_to_be_textured & FACE_BOTTOM)
            glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, -1.0f);	// left bottom 

        if(faces_to_be_textured & FACE_BOTTOM)
            glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, -1.0f); 	// right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0); 
    } 
    glPopMatrix(); 
}

void drawPyramid(
    float x, float y, float z, 
    float sx, float sy, float sz, 
    float r, float g, float b, float a, 
    GLuint texture 
)
{
    glPushMatrix(); 
        glTranslatef(x, y, z);  
        glScalef(sx, sy, sz); 
        glColor4f(r, g, b, a); 

        glBindTexture(GL_TEXTURE_2D, texture); 
        glBegin(GL_TRIANGLES);
        // front face 
        glNormal3f(0.0f, 0.447214f, 0.894428f); 
        glTexCoord2f(0.5f, 1.0f); 
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, 1.0f);	
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, 1.0f); 
        
        // right face 
        glNormal3f(0.894428f, 0.447214f, 0.0f); 
        glTexCoord2f(0.5f, 1.0f); 
        glVertex3f(0.0f, 1.0f, 0.0f); 
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, 1.0f); 
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, -1.0f); 
        
        // back face 
        glNormal3f(0.0f, 0.447214f, -0.894428f); 
        glTexCoord2f(0.5f, 1.0f); 
        glVertex3f(0.0f, 1.0f, 0.0f); 
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, -1.0f, -1.0f); 
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, -1.0f); 
        
        // left face 
        glNormal3f(-0.894428, 0.447214f, 0.0f);
        glTexCoord2f(0.5f, 1.0f); 
        glVertex3f(0.0f, 1.0f, 0.0f); 
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, -1.0f);  
        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(-1.0f, -1.0f, 1.0f); 
        glEnd();

        glBindTexture(GL_TEXTURE_2D, 0); 
    glPopMatrix(); 
}

void drawCylinder(float base, float top, float height, float tx, float ty, float tz,float sx, float sy, float sz,float rox, float roy, float roz, GLuint textureID)
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);  // Use texture color directly
	glEnable(GL_BLEND);
	GLUquadric* quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	glPushMatrix();
	{
		glTranslatef(tx, ty, tz);
		glScalef(sx, sy, sz);
		glRotatef(rox, 1.0f, 0.0f, 0.0f);
		glRotatef(roy, 0.0f, 1.0f, 0.0f);
		glRotatef(roz, 0.0f, 0.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, textureID);
		gluCylinder(quad, base, top, height, 30, 30);
	}
	glPopMatrix();
	glDisable(GL_BLEND);

    gluDeleteQuadric(quad); 
    quad = NULL; 
}

void drawCone(float base, float height, float tx, float ty, float tz, float sx, float sy, float sz, float rox, float roy, float roz, GLuint textureID)
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);  // Use texture color directly
	glEnable(GL_BLEND);
	GLUquadric* quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	glPushMatrix();
	{
		glTranslatef(tx, ty, tz);
		glScalef(sx, sy, sz);
		glRotatef(rox, 1.0f, 0.0f, 0.0f);
		glRotatef(roy, 0.0f, 1.0f, 0.0f);
		glRotatef(roz, 0.0f, 0.0f, 1.0f);
		
		glBindTexture(GL_TEXTURE_2D,textureID);
		gluCylinder(quad, base, 0.0, height, 30, 30);  //base,top,height,slices,stacks
        glBindTexture(GL_TEXTURE_2D, 0); 
	}
	glPopMatrix();
	glDisable(GL_BLEND);

    gluDeleteQuadric(quad); 
    quad = NULL; 
}


