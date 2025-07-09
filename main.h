#ifndef _MAIN_H 
#define _MAIN_H 

// win32 headers 
#include <Windows.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// OpenGL related header files 
#include <gl/glew.h> 
#include <gl/GL.h> 
#include <gl/GLU.h> 

// scene header files 
#include "Scenes/Scene1/scene1.h" 

// Effects header files 
// #include "Effects/Lights/lights.h" 
#include "Effects/Fog/fog.h" 

// audio 
#include "Common/Audio/audio.h" 

// OpenGL libraries 
#pragma comment(lib, "opengl32.lib") 
#pragma comment(lib, "glu32.lib") 

// macros 
#define WIN_WIDTH   800 
#define WIN_HEIGHT  600 

#define MYICON  101 

// for using stb_image functionalities  
#define STB_IMAGE_IMPLEMENTATION 
#include "Common/stb_image.h" 

// global function declarations 
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

#endif /* _MAIN_H */

