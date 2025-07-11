// This file contains the controlling variables(parameters, flags,..) for all the scens, objects and effects 

// ==================================== SHOT 4 (EMPTY SCENE DURING SIRS VOICE) =================== 
unsigned int shot3WaitTimer = 10000; 

// ==================================== SCENE 1 ============================
unsigned int beat01time = 2000;  
unsigned int beat02time = 2200;  
unsigned int beat03time = 2400;  
unsigned int beat04time = 2600;  
unsigned int beat05time = 2800;  
unsigned int beat06time = 3000;  
unsigned int beat07time = 3200;  
unsigned int beat08time = 3400;  
unsigned int beat09time = 3600;  
unsigned int beat10time = 3800;  
unsigned int beat11time = 4000;  
unsigned int beat12time = 4200;  
unsigned int beat13time = 4400; 
unsigned int beat14time = 4500; // start light movement 
unsigned int beat15time = 5000; // start fading out 

// scene 1 lights 
float lightTranslationSpeed = 0.07f; 

// ==================================== SCENE 2 ============================

float cameraMovementSpeedInverseConstant1 = 200.0f; 
float cameraMovementSpeedInverseConstant2 = 200.0f;  

// boy 
float legUpdateSpeed = 0.06f; 
float boyTranslateSpeed = 0.02f; 

// ==================================== SCENE 3 ============================
float scene3cameraSpeedInverseConstant = 200.0f; 

// for peackock 
float peackockXupdateStep = 0.01f; 
float peackockRotateAngleYUpdateStep = 2.0f; 

// for butterfly 
int butterflyWaitTimer = 200; 
int scene3WaitTimer = 1000;

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

