#ifndef _AUDIO_H
#define _AUDIO_H 

#define ID_MUSIC 103 

#include <Windows.h> 
#include <stdio.h> 

#include <AL/al.h> 
#include <AL/alc.h> 

#pragma comment(lib, "OpenAL32.lib") 

BOOL initializeAudio(void); 
BOOL playAudio(void); 
void uninitializeAudio(void); 

#endif /* _AUDIO_H */
