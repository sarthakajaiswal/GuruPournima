// This file contains the controlling variables(parameters, flags,..) for all the scens, objects and effects 

// ==================================== SHOT 4 (EMPTY SCENE DURING SIRS VOICE) =================== 
unsigned int shot3WaitTimer = 1050; 

// ==================================== SCENE 1 ============================
unsigned int beat01time = 500;  
unsigned int beat02time = 650;  
unsigned int beat03time = 800;  
unsigned int beat04time = 950;  
unsigned int beat05time = 1100;  
unsigned int beat06time = 1350;  
unsigned int beat07time = 1500;  
unsigned int beat08time = 1650;  
unsigned int beat09time = 1800;  
unsigned int beat10time = 1950;  
unsigned int beat11time = 2100;  
unsigned int beat12time = 2350;  
unsigned int beat13time = 2500; 
unsigned int beat14time = 2650; // start light movement 
unsigned int beat15time = 3500; // change scene  

// scene 1 lights 
float lightTranslationSpeed = 0.07f; 

// ==================================== SCENE 2 ============================
unsigned int scene2WaitTimer = 1200; 

float cameraMovementSpeedInverseConstant1 = 380.0f; 
float cameraMovementSpeedInverseConstant2 = 355.0f;  

// boy 
float legUpdateSpeed = 0.06f; 
float boyTranslateSpeed = 0.02f; 

// ==================================== SCENE 3 ============================
// for butterfly 
int butterflyWaitTimer = 50; 
float butterflyBazierTUpdateStep = 0.004; 
int scene3WaitTimer = 600; 

// ==================================== SCENE 4 ============================
unsigned int slide1WaitTimer = 500;  // slide 1 will appear upto this time 
unsigned int slide2WaitTimer = 500; // slide 2 will appear upto this time 
unsigned int slide3WaitTimer = 500; 
unsigned int slide4WaitTimer = 500; 
unsigned int slide5WaitTimer = 1000; 

// ----------- CUBIC ALPHABETS ----------- 
float DEPTH_OF_ALPHABETS = 2.0f;


// ------------- FADING ----------------- 
float updateFadeDensityStep = 0.001f; 

// ------ PEACKOCK ---------- 

