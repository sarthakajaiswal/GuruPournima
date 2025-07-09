#include "scene3.h" 

extern FILE* gpFile; 
extern float tx, ty, tz, sx, sy, sz; 
extern float cameraX, cameraY, cameraZ; 

static GLuint textures_tree_bark[5]; 
static GLuint textures_tree_leaves[2]; 
static GLuint texture_ground; 
static GLuint texture_water; 
static GLuint texture_shore; 
static GLuint texture_bush1; 
static GLuint texture_bush2; 
static GLuint texture_bush3; 
static GLuint texture_bush4; 
static GLuint texture_bamboo_tree; 
static GLuint texture_deer; 

static GLuint texture_lwing, texture_rwing; 

static GLUquadric* scene3Quadric; 

static const char* cubemapImages[6] = {
    "Resources/Cubemap/Day/right.png",
    "Resources/Cubemap/Day/left.png",
    "Resources/Cubemap/Day/top.png",
    "Resources/Cubemap/Day/bottom.png",
    "Resources/Cubemap/Day/front.png",
    "Resources/Cubemap/Day/back.png" 
}; 
static GLuint texture_cubemap; 

int initScene3(void) 
{
    assert(loadGLPngTexture(&textures_tree_bark[0], "Resources/bark1.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[1], "Resources/bark2.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[2], "Resources/bark3.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[3], "Resources/bark4.png")); 
    assert(loadGLPngTexture(&textures_tree_bark[4], "Resources/bark5.png")); 

    assert(loadGLPngTexture(&textures_tree_leaves[0], "Resources/tree1.png")); 
    assert(loadGLPngTexture(&textures_tree_leaves[1], "Resources/tree2.png"));  

    assert(loadGLPngTexture(&texture_ground, "Resources/grass1.png")); 
    assert(loadGLPngTexture(&texture_water, "Resources/water.png")); 
    
    assert(loadGLPngTexture(&texture_lwing, "Resources/wing_left.png")); 
    assert(loadGLPngTexture(&texture_rwing, "Resources/wing_right.png")); 
    assert(loadGLPngTexture(&texture_shore, "Resources/shore.png")); 
    assert(loadGLPngTexture(&texture_bush1, "Resources/bush1.png")); 
    assert(loadGLPngTexture(&texture_bush2, "Resources/bush2.png")); 
    assert(loadGLPngTexture(&texture_bush3, "Resources/bush3.png")); 
    assert(loadGLPngTexture(&texture_bush4, "Resources/bush4.png")); 
    assert(loadGLPngTexture(&texture_bamboo_tree, "Resources/bamboo_bark.png")); 
    assert(loadGLPngTexture(&texture_deer, "Resources/deers.png")); 


    texture_cubemap = loadCubeMap(cubemapImages, STBI_rgb_alpha); 
    // initializeBoy(); 

    scene3Quadric = gluNewQuadric(); 
    if(scene3Quadric == NULL) 
    {
        fprintf(gpFile, "Failed to get new quadric for scene 2\n"); 
        return (-3); 
    }
    gluQuadricTexture(scene3Quadric, GL_TRUE);

    // initFog(); 
    // enableFog(); 
    initGrass(0.2, 0.6, 20.0f, 10000);  
    initPeackock(); 
    
    return (0); 
} 

float meltOffset = 0.0f;

void drawWaterSurface(float offset, float width, float depth, int slices) {
	float halfwidth = width / 2.0f;
	float halfdepth = depth / 2.0f;
	float waveFrequency = 10.0f;
	float waveAmplitude = 0.05f;

	float dx = width / slices;
	float dz = depth / slices;
	
	for (int i = 0; i < slices; i++) 
	{
		float z = -halfdepth + i * dz;
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j <= slices; j++) {
			float x = -halfwidth + j * dx;

			float y1 = sin(waveFrequency * x + offset) * waveAmplitude
				+ cos(waveFrequency * z + offset) * waveAmplitude;
			float y2 = sin(waveFrequency * x + offset) * waveAmplitude
				+ cos(waveFrequency * (z + dz) + offset) * waveAmplitude;

			glTexCoord2f(j / (float)slices, i / (float)slices);
			glVertex3f(x, y1, z);

			glTexCoord2f(j / (float)slices, (i + 1) / (float)slices);
			glVertex3f(x, y2, z + dz);
		}
		glEnd();
	}
}

float rx, ry, rz; 


float wingAngle = 0.0f; 
void drawButterfly(GLuint texture_lwing, GLuint texture_rwing, float x, float y, float sx, float sy)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glColor3f(1.0f, 1.0f, 1.0f);  // no tint

	// Left Wing
	glPushMatrix();
	{
		glTranslatef(x, y, 0.0f);  // Position the butterfly
		glScalef(sx, sy, 1.0f);    // Scale it
		glTranslatef(-0.0005f, 0.0f, 0.0f);  // Slight shift for flapping center
		glRotatef(wingAngle, 0.0f, 1.0f, 0.0f);  // flap outward

		glBindTexture(GL_TEXTURE_2D, texture_lwing);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();

	// Right Wing
	glPushMatrix();
	{
		glTranslatef(x, y, 0.0f);  // Same position
		glScalef(sx, sy, 1.0f);
		glTranslatef(0.0005f, 0.0f, 0.0f);  // Shift right for pivot
		glRotatef(-wingAngle, 0.0f, 1.0f, 0.0f);  // flap outward

		glBindTexture(GL_TEXTURE_2D, texture_rwing);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();

	glDisable(GL_BLEND);
} 









extern float tx, ty, tz, sx, sy, sz, rx, ry, rz; 




void displayScene3(void) 
{
    // variable declarations 
    static float isThisFirstCall = TRUE; 

    Point verticesForBazierCurve[] = {{-3.65, 2.15, 17.05}, {-7.65, 10.25, -4.80}, {1.00, 5.55, 9.80}, {-3.95, 3.50, -1.20}, {1.30, 3.25, 20.20}}; 
    size_t size = 5; 

    // code 
    if(isThisFirstCall) 
    {
        cameraY = 3.20f; 
        cameraZ = 17.20; 
        isThisFirstCall = FALSE; 
    }

    glPushMatrix(); 
    displayCubemap(texture_cubemap, 75.0f, 75.0f, 75.0f);  
    glPopMatrix(); 

    // ground 
    glBindTexture(GL_TEXTURE_2D, texture_ground); 
    glPushMatrix(); 
    {
        glTranslatef(-30.0f, 0.0f, -8.20f); 
        glScalef(35.0, 0.0, 100); 
        glNormal3f(0.0f, 1.0f, 0.0f); 
        glBegin(GL_QUADS); 
        glTexCoord2f(50.0f, 50.0f); 
        glVertex3f(1.0f, 0.0f, -1.0f); 	// right top 

        glTexCoord2f(0.0f, 50.0f); 
        glVertex3f(-1.0f, 0.0f, -1.0f);	// left top 

        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, 0.0f, 1.0f);	// left bottom 

        glTexCoord2f(50.0f, 0.0f); 
        glVertex3f(1.0f, 0.0f, 1.0f);   // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0);
    } 
    glPopMatrix(); 
    glBindTexture(GL_TEXTURE_2D, 0); 

    // shore 
    glBindTexture(GL_TEXTURE_2D, texture_shore); 
    glPushMatrix(); 
    {
        glTranslatef(5.80, -0.35, 0.0); 
        glScalef(0.95, 0.90, 100); 
        glRotatef(-20.0f, 0, 0, 1); 
        glNormal3f(0.0f, 1.0f, 0.0f); 
        glBegin(GL_QUADS); 
        glTexCoord2f(1.0f, 50.0f); 
        glVertex3f(1.0f, 0.0f, -1.0f); 	// right top 

        glTexCoord2f(0.0f, 50.0f); 
        glVertex3f(-1.0f, 0.0f, -1.0f);	// left top 

        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-1.0f, 0.0f, 1.0f);	// left bottom 

        glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1.0f, 0.0f, 1.0f);   // right bottom 
        glEnd(); 
        glBindTexture(GL_TEXTURE_2D, 0);
    } 
    glPopMatrix(); 
    glBindTexture(GL_TEXTURE_2D, 0); 


    // mountains 
    // drawPyramid(tx, ty, tz, sx, sy, sz, 1.0f, 1.0f, 1.0f, 0);  

    // water 
    glPushMatrix(); 
    glTranslatef(23.40, -0.70, -22.95);
    glScalef(11.65, 2.15, 26.0);  
    glBindTexture(GL_TEXTURE_2D, texture_water);
	drawWaterSurface(meltOffset, 3.0f, 3.0f, 50.0f); 
    glPopMatrix(); 

    // grass 
    glPushMatrix(); 
    glTranslatef(-20.70, -0.00, -17.45);
    glScalef(0.55, 1.70, 2.30);  
    displayGrass(); 
    glPopMatrix(); 

    // peackock 
    glPushMatrix(); 
    glTranslatef(-17.10, 1.45, -0.25);
    glScalef(0.40, 0.35, 0.50);  
    displayPeackock();  
    glPopMatrix(); 
    glPushMatrix(); 
    glTranslatef(-19.10, 1.45, -0.25);
    glScalef(0.40, 0.35, 0.50);  
    displayPeackock();  
    glPopMatrix(); 

    // bamboo tree 
    glPushMatrix(); 
    glTranslatef(3.95, 7.20, 16.75); 
    glScalef(1.75, 1.00, 1.00); 
    glRotatef(90, 1, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f);  
    glBindTexture(GL_TEXTURE_2D, texture_bamboo_tree); 
    gluCylinder(scene3Quadric, 0.5, 0.5, 6.00, 12, 8);  
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix(); 

    // bushes 
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    billboard(-11.35, 2.15, 4.60, 2.35, 2.85, 4.95, texture_bush1); 
    billboard(4.90, 0.80, 0.00, 1.00, 1.00, 1.00, texture_bush2);  
    billboard(-4.65, 1.00, 14.80, 1.50, 1.30, 1.85, texture_bush3);  
    billboard(3.30, 1.00, 17.20, 0.70, 1.75, 1.35, texture_bush4);  
    billboard(3.30, 1.00, 17.20, 0.70, 1.75, 1.35, texture_bush4);  
    billboard(-8.45, 0.95, -8.30, 0.95, 1.00, 1.00, texture_bush4);  
    // billboard(tx, ty, tz, sx, sy, sz, texture_bush4);  
    
    // deer 
    billboard(-12.70, 1.35, -24.10, 2.65, 2.65, 1.00, texture_deer);  
    glDisable(GL_BLEND); 

    // butterfly 
    glPushMatrix();
    glTranslatef(-3.65, 2.15, 17.05); 
    glScalef(0.20, 0.85, 0.25);  
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);  
    drawButterfly(texture_lwing, texture_rwing, 0.0f, 0.0f, 1.0f, 1.0f); 
    glPopMatrix(); 

    displayBazierCurve(verticesForBazierCurve, size); 
}  

void updateScene3(void) 
{
    updateGrass(); 

    // water update 
    meltOffset += 0.02f;
    if (meltOffset > 1000)
    {
        meltOffset = 0.0f;
    }

    // butterfly update 
    static BOOL butterflyWingFlag = TRUE; 
    if(butterflyWingFlag) 
    {
        wingAngle += 1.2f; 
        if(wingAngle >= 10.0f) 
            butterflyWingFlag = FALSE; 
    } 
    else 
    {
        wingAngle -= 1.2f; 
        if(wingAngle <= -20.0f) 
            butterflyWingFlag = TRUE; 
    }

    updatePeackock(); 
} 

void uninitializeScene3(void) 
{
    uninitializeGrass(); 
    uninitializePeackock(); 
}
