#ifndef _MAIN_H 
#define _MAIN_H 

// win32 headers 
#include <Windows.h> 
#include <stdio.h> 
#include <stdlib.h> 

// OpenGL related header files 
#include <gl/GL.h> 
#include <gl/GLU.h> 

// scene header files 
#include "Scenes/Scene1/scene1.h" 

// OpenGL libraries 
#pragma comment(lib, "opengl32.lib") 
#pragma comment(lib, "glu32.lib") 

// macros 
#define WIN_WIDTH   800 
#define WIN_HEIGHT  600 

#define MYICON  101 

// global function declarations 
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

#endif /* _MAIN_H */

