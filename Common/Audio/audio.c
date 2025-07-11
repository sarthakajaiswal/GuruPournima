#include "audio.h" 

extern FILE* gpFile; 

ALuint audioBuffer, audioSource; 

BOOL initializeAudio(void) 
{
    // variable declarations 
    ALCdevice* audioDevice; 
    ALCcontext* alContext; 

    HRSRC hResource = NULL; 
    HANDLE hAudioBuffer = NULL; 

    LPVOID audioBufferData = NULL; 
    DWORD sizeofAudioDataInBytes = 0; 

    // code 
    // 1) Open default audio device 
    // NULL means default audio device is yet to be opened 
    audioDevice = alcOpenDevice(NULL); 
    if(alcGetError(audioDevice) != ALC_NO_ERROR) 
    {
        fprintf(gpFile, "InitializeAudio() : alcOpenDevice() failed\n"); 
        return (FALSE); 
    }

    // 2) create OpenAL context 
    alContext = alcCreateContext(audioDevice, NULL); 
    if(alcGetError(audioDevice) != ALC_NO_ERROR) 
    {
        fprintf(gpFile, "initializeAudio() : alcCreateContext() failed\n"); 
        return (FALSE); 
    }

    // 3) similar to wglMakeCurrent 
    alcMakeContextCurrent(alContext); 
    if(alcGetError(audioDevice) != ALC_NO_ERROR) 
    {
        fprintf(gpFile, "initializeAudio() : alcMakeCurrentContext() failed\n"); 
        return (FALSE); 
    }

    // 4) create audio buffer 
    alGenBuffers(1, &audioBuffer); 
    if(alGetError() != AL_NO_ERROR) 
    {
        fprintf(gpFile, "initializeAudio() : alGenBuffers() failed\n"); 
        return (FALSE); 
    }

    // 5) load wav resource data 
    // 5A: find resource and get handle 
    hResource = FindResource(NULL, MAKEINTRESOURCE(ID_MUSIC), TEXT("WAV")); 
    if(hResource == NULL) 
    {
        fprintf(gpFile, "%lu\n", GetLastError()); 
        // fprintf(gpFile, "initializeAudio(): FindResource() failed\n"); 
        return (FALSE); 
    }

    // 5B: use resource handle to load it in memory and return handle to it 
    hAudioBuffer = LoadResource(NULL, hResource); 
    if(hAudioBuffer == NULL) 
    {
        fprintf(gpFile, "initializeAudio() : loadResource() failed\n"); 
        return (FALSE); 
    }

    // 5C: get starting byte-offset of this data in memory 
    audioBufferData = LockResource(hAudioBuffer); 
    if(audioBufferData == NULL) 
    {
        fprintf(gpFile, "initializeAudio() : LockResource() failed\n"); 
        return (FALSE); 
    }

    // 5D: get the size of audio data 
    sizeofAudioDataInBytes = SizeofResource(NULL, hResource); 
    if(sizeofAudioDataInBytes == 0) 
    {
        fprintf(gpFile, "InitializeAudio() : LockResource() failed\n"); 
        return (FALSE); 
    }

    // 6) load WAV data into audio buffer 
    sizeofAudioDataInBytes = sizeofAudioDataInBytes - (sizeofAudioDataInBytes%4); 
    alBufferData(audioBuffer, AL_FORMAT_STEREO16, audioBufferData, sizeofAudioDataInBytes, 44100); 
    if(alGetError() != AL_NO_ERROR) 
    {
        fprintf(gpFile, "initializeAudio(): alBufferData() failed\n"); 
        return (FALSE); 
    }

    // 7) create audio source 
    alGenSources(1, &audioSource); 
    if(alGetError() != AL_NO_ERROR) 
    {
        fprintf(gpFile, "initializeAudio() : alGenSources() failed\n"); 
        return (FALSE); 
    }

    // 8) Give the audio buffer to audio source 
    alSourcei(audioSource, AL_BUFFER, audioBuffer); 
    if(alGetError() != AL_NO_ERROR) 
    {
        fprintf(gpFile, "initializeAudio() : alSourcei() failed\n"); 
        return (FALSE); 
    }

    // this 2 are not needed since win32 frees memory 
    // unload WAV resources 
    // UnlockResource(hResource); 
    // FreeResource(hAudioBuffer); 

    return (TRUE); 
}

BOOL playAudio(void) 
{
    alSourcePlay(audioSource); 
    if(alGetError() != AL_NO_ERROR) 
        return (TRUE); 

    return (FALSE); 
} 

void uninitializeAudio(void) 
{
    // variable declarations 
    ALCdevice *audioDevice; 
    ALCcontext *alContext; 

    ALint state; 

    // code 
    // 1) Get current status of audio source whether playing or stopped 
    alGetSourcei(audioSource, AL_SOURCE_STATE, &state); 
    if(state == AL_PLAYING) 
    {
        alSourceStop(audioSource); 
        if(alGetError() != AL_NO_ERROR) 
            fprintf(gpFile, "UninitializeAudio() : alSourceStop() failed\n"); 
    }

    // 2) Detach audio buffer from audio source 
    alSourcei(audioSource, AL_BUFFER, 0); 
    if(alGetError() != AL_NO_ERROR) 
        fprintf(gpFile, "uninitializeAudio() : alSourcei() failed to detach audio buffer from audio source\n"); 

    // 3) Delete audio source 
    alDeleteSources(1, &audioSource); 
    if(alGetError() != AL_NO_ERROR) 
        fprintf(gpFile, "uninitializeAudio() : alDeleteSources() failed to delete audio source\n"); 
    else 
        audioSource = 0; 

    // 5) Get the current OpenAL context 
    alContext = alcGetCurrentContext(); 
    if(alContext == NULL) 
        fprintf(gpFile, "uninitializeAudio() : alcGetCurrentContext() failed\n"); 
    else 
    {
        audioDevice = alcGetContextsDevice(alContext); 
        if(audioDevice == NULL) 
            fprintf(gpFile, "uninitializeAudio() : alcGetCurrentContextDevice() failed\n"); 
    }

    // 7) delete OpenAL context 
    if(alContext)
    {
        // 7A) Unset the OpenAL context as current context 
        alcMakeContextCurrent(NULL); 
        // 7B) destroy openAL context 
        alcDestroyContext(alContext); 
        alContext = NULL; 
    }

    // 8) close openal context 
    if(audioDevice) 
    {
        alcCloseDevice(audioDevice); 
        audioDevice = NULL; 
    }
} 