#include "terrain.h" 

#define TERRAIN_MAP_X  257  
#define TERRAIN_MAP_Z  257
#define MAP_SCALE 40.0f 
#define MAX_HEIGHT 80.0f 

extern FILE* gpFile; 

float terrainHeightMap[TERRAIN_MAP_X][TERRAIN_MAP_Z][3]; 
unsigned char* image_data = NULL; 
GLuint texture_terrain; 

int initTerrain(const char* heightMapBPImage, const char* texturePNGImage) 
{
    if(loadHeightMapData(heightMapBPImage) == FALSE) 
    {
        fprintf(gpFile, "Failed to load terrain heightmap image : %s\n", heightMapBPImage); 
        return (-1); 
    }
    else 
    {
        fprintf(gpFile, "Terrain heightmap image loaded successfully\n"); 
    }

    for(int z = 0; z < TERRAIN_MAP_Z; z++) 
    {
        for(int x = 0; x < TERRAIN_MAP_X; ++x) 
        {
            terrainHeightMap[x][z][0] = (float)x * MAP_SCALE; 
            terrainHeightMap[x][z][1] = image_data[(x+z*TERRAIN_MAP_Z) * 3] * 3; 
            terrainHeightMap[x][z][2] = -(float)z * MAP_SCALE; 
        }
    }

    // if(loadGLPngTexture(&texture_terrain, texturePNGImage) == FALSE) 
    // {
    //     fprintf(gpFile, "failed to load texture for terrain\n"); 
    //     return (-2); 
    // }

    return (0); 
} 

BOOL loadHeightMapData(char* filename) 
{
    int imageWidth, imageHeight, imageChannel; 

    image_data = stbi_load(filename, &imageWidth, &imageHeight, &imageChannel, 0); 
    if(image_data == NULL) 
    {
        fprintf(gpFile, "Error in loading image heightmap data\n"); 
        return (FALSE); 
    }

    return (TRUE); 
}

void uninitializeTerrain() 
{
    if(texture_terrain) 
    {
        glDeleteTextures(1, &texture_terrain); 
        texture_terrain = 0; 
    }

    if(image_data) 
    {
        stbi_image_free(image_data); 
        image_data = 0; 
    } 
} 

void displayTerrain() 
{
    glPushMatrix(); 
    {
        glTranslatef(0.0f, -500.0f, -5.0f); 
        
        glBindTexture(GL_TEXTURE_2D, texture_terrain); 
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 

        for(int z = 0; z < TERRAIN_MAP_Z - 1; z++) 
        {
            glBegin(GL_TRIANGLE_STRIP); 
            for(int x = 0; x < TERRAIN_MAP_X - 1; x++) 
            {
                float scaledHeight = terrainHeightMap[x][z][1] / MAP_SCALE; 
                float nextScaledHeight = terrainHeightMap[x][z+1][1] / MAP_SCALE; 
                float color = 0.5f + 0.5f * scaledHeight / MAX_HEIGHT; 
                float nextColor = 0.5f + 0.5f * nextScaledHeight / MAX_HEIGHT; 

                glColor3f(color, color, color); 
                glTexCoord2f(0.0f, 0.0f); 
                glVertex3f(terrainHeightMap[x][z][0], terrainHeightMap[x][z][1], terrainHeightMap[x][z][2]);
                
                color = 0.5f + 0.5f + terrainHeightMap[x + 1][z][1] / (40.0f); 
                glColor3f(color, color, color); 
                glTexCoord2f(1.0f, 0.0f); 
                glVertex3f(terrainHeightMap[x+1][z][0], terrainHeightMap[x+1][z][1], terrainHeightMap[x+1][z][2]);
                
                color = 0.5f + 0.5f + terrainHeightMap[x][z+1][1] / (40.0f); 
                glColor3f(color, color, color); 
                glTexCoord2f(0.0f, 1.0f); 
                glVertex3f(terrainHeightMap[x][z+1][0], terrainHeightMap[x][z+1][1], terrainHeightMap[x][z+1][2]);
                
                color = 0.5f + 0.5f + terrainHeightMap[x+1][z+1][1] / (40.0f); 
                glColor3f(color, color, color); 
                glTexCoord2f(1.0f, 1.0f); 
                glVertex3f(terrainHeightMap[x+1][z+1][0], terrainHeightMap[x+1][z+1][1], terrainHeightMap[x+1][z+1][2]);
                
            }
            glEnd(); 
        }
        glBindTexture(GL_TEXTURE_2D, 0); 
    }
    glPopMatrix(); 
} 

