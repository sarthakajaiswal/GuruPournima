#include "cubemap.h" 

extern FILE* gpFile; 

unsigned int loadCubeMap(const char* faces[], int desiredChannels) 
{
    // variable declarations 
    unsigned int textureID; 
    int width, height, nr_channels; 

    // code 
    glGenTextures(1, &textureID); 
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID); 

    for(int i = 0; i < 6; ++i) 
    {
        unsigned char* data = stbi_load(faces[i], &width, &height, &nr_channels, desiredChannels); 
        if(data) 
        {
            if(nr_channels == 3) 
            {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); 
            }
            else if(nr_channels == 4) 
            {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); 
            }

            stbi_image_free(data); 
            fprintf(gpFile, "loaded - %s\n", faces[i]); 
        }
        else 
        {
            printf("Cubemap texture failed to load at paht : %s\n", faces[i]); 
            stbi_image_free(data); 
        }
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); 
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); 
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); 

    return (textureID); 
}

// cubemap related functions 
void displayCubemap(GLuint texture, float cubeScaleX, float cubeScaleY, float cubeScaleZ)
{
	// code  
	glPushMatrix();
	{
		// glScalef(1 + 3.100 , 1 + 2.770 , 1 + 3.600);
		// glScalef((1 + 3.100 + 11.650) * 2.5, (1 + 2.770) * 2.5, (1 + 3.600 + 9.7) * 2.5);
		// glScalef(1.0f, 1.0f, 1.0f); 
		glScalef(cubeScaleX, cubeScaleY, cubeScaleZ); 
		glColor3f(1.0f, 1.0f, 1.0f);

		glEnable(GL_TEXTURE_CUBE_MAP);
		glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

		// Render Front face
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, -1.0);
		glTexCoord3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glEnd();

		// Render Back face
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glEnd();

		// Render Left face
		glBegin(GL_QUADS);
		glNormal3f(1.0, 0.0, 0.0);
		glTexCoord3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glEnd();

		// Render Right face
		glBegin(GL_QUADS);
		glNormal3f(-1.0, 0.0, 0.0);
		glTexCoord3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glEnd();

		//// Render Top face
		glNormal3f(0.0, -1.0, 0.0);
		glBegin(GL_QUADS);
		glTexCoord3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glEnd();

		//// Render Bottom face
		glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();

		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
		glDisable(GL_TEXTURE_CUBE_MAP);
	}
	glPopMatrix();
}

