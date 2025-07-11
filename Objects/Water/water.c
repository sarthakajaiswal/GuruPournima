#include "water.h" 

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
