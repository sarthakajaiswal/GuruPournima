#include "main.h" 

// global variable declarations 
HWND ghwnd; 
HDC ghdc; 
HGLRC ghrc; 

// fullscreen toggle related variables 
BOOL gbFullScreen = FALSE; 
WINDOWPLACEMENT wpPrev; 
DWORD dwStyle; 

// gameloop related variables 
BOOL gbActiveWindow = FALSE; 
BOOL gbEscapeKeyIsPressed = FALSE; 

// fileIO related variables 
FILE* gpFile = NULL; 
TCHAR gszgpFileName[] = TEXT("log.txt"); 

// camera related variables 
float cameraX = 0.0, cameraY, cameraZ = 15.0; 
float cameraUpX = 0.0f, cameraUpY = 1.0f, cameraUpZ = 0.0f; 
float cameraCenterX = 0.0f, cameraCenterY = 0.0f, cameraCenterZ = -10.0f; 

// translation related variables 
float tx, ty = 0.0f, tz, sx = 1.0f, sy = 1.0f, sz= 1.0f, rx, ry, rz; 
const float translation_step = 0.05f; 
const float scale_step = 0.05f;  

// lights related variables 
BOOL bLight = FALSE; 

int gTimer = 0; // global timer 

// entry-point function 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nShowCmd) 
{
    // function declarations 
    int initialize(void); 
    void resize(int, int); 
    void display(void); 
    void update(void); 
    void uninitialize(void); 

    // variable declarations 
    WNDCLASSEX wndClass; 
    HWND hwnd; 
    MSG msg; 
    TCHAR szAppName[] = TEXT("Guru Pournima Demo"); 
    TCHAR szClassName[] = TEXT("RTR6"); 
    BOOL bDone = FALSE; 

    // code 
    // create a log file 
    gpFile = fopen(gszgpFileName, "w"); 
    if(gpFile == NULL) 
    {
        MessageBox(NULL, TEXT("Failed to create log file"), TEXT("FileIO error."), MB_OK); 
        exit(0); 
    }
    else 
    {
        fprintf(
            gpFile, 
            "Program started successfully\n"
        ); 
    }

    // window class initialization 
    wndClass.cbSize = sizeof(WNDCLASSEX); 
    wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; 
    wndClass.cbClsExtra = 0; 
    wndClass.cbWndExtra = 0; 
    wndClass.lpfnWndProc = WndProc; 
    wndClass.hInstance = hInstance; 
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON)); 
    wndClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON)); 
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW); 
    wndClass.lpszClassName = szClassName; 
    wndClass.lpszMenuName = NULL; 

    // window class registration 
    RegisterClassEx(&wndClass); 

    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW, 
        szClassName, 
        szAppName, 
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        WIN_WIDTH, 
        WIN_HEIGHT, 
        NULL, 
        NULL, 
        hInstance, 
        NULL
    ); 
    ghwnd = hwnd; 

    // show window 
    ShowWindow(hwnd, nShowCmd); 

    // update window 
    UpdateWindow(hwnd); 

    // initialize 
    int iResult = initialize(); 
    if(iResult != 0) 
    {
        fprintf(gpFile, "initialize() failed\n");
        uninitialize(); 
        return (0);  
    }
    else 
    {
        fprintf(gpFile, "initialize() completed successfully\n"); 
    }

    // set this window as foreground and active window 
    SetForegroundWindow(hwnd); 
    SetFocus(hwnd); 

    // GameLoop 
    while(bDone == FALSE) 
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
        {
            if(msg.message == WM_QUIT) 
            {
                bDone = TRUE; 
            }
            else 
            {
                TranslateMessage(&msg); 
                DispatchMessage(&msg); 
            }
        }
        else 
        {
            if(gbActiveWindow == TRUE) 
            {
                if(gbEscapeKeyIsPressed == TRUE) 
                { 
                    bDone = TRUE; 
                }

                // render 
                display(); 

                // update 
                update(); 
            }
        }
    }

    // uninitialize 
    uninitialize(); 

    return ((int)msg.wParam); 
} 

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    // function declarations 
    void toggleFullScreen(void); 

    // code 
    switch(uMsg) 
    {
        case WM_CREATE: 
            ZeroMemory((void*)&wpPrev, sizeof(WINDOWPLACEMENT)); 
            wpPrev.length = sizeof(WINDOWPLACEMENT); 
            break; 

        case WM_SETFOCUS: 
            gbActiveWindow = TRUE; 
            break; 

        case WM_KILLFOCUS: 
            gbActiveWindow = FALSE; 
            break; 

        case WM_ERASEBKGND: 
            return (0); 

        case WM_SIZE: 
            resize(LOWORD(lParam), HIWORD(lParam)); 
            break; 

        case WM_KEYDOWN: 
            switch(wParam) 
            {
                case VK_ESCAPE: 
                    gbEscapeKeyIsPressed = TRUE; 
                    break; 

                default: 
                    break; 
            }
            break; 

        case WM_CHAR: 
            switch(wParam) 
            {
                case 'F': 
                case 'f': 
                    if(gbFullScreen == FALSE) 
                    {
                        toggleFullScreen(); 
                        gbFullScreen = TRUE; 
                    }
                    else 
                    {
                        toggleFullScreen(); 
                        gbFullScreen = FALSE; 
                    }
                    break; 

                case 'L': 
                case 'l': 
                    if(bLight == FALSE) 
                    {
                        bLight = TRUE; 
                        glEnable(GL_LIGHTING); 
                    }
                    else 
                    {
                        bLight = FALSE; 
                        glDisable(GL_LIGHTING); 
                    }
                    break; 

                case '4': 
                    cameraX -= 0.2f; 
                    break; 

                case '6': 
                    cameraX += 0.2f; 
                    break; 

                case '2': 
                    cameraY -= 0.2f; 
                    break; 

                case '8': 
                    cameraY += 0.2f; 
                    break; 

                case '5': 
                    cameraZ -= 0.2f; 
                    break; 

                case '0': 
                    cameraZ += 0.2f; 
                    break; 

                case '[':  
                    cameraCenterX -= 0.2f; 
                    break; 
                case ']':
                    cameraCenterX += 0.2f; 
                    break;
                case ';':  
                    cameraCenterY -= 0.2f; 
                    break;
                case '\'':  
                    cameraCenterY += 0.2f; 
                    break; 
                case '.': 
                    cameraCenterZ -= 0.2f; 
                    break;
                case '/':  
                    cameraCenterZ += 0.2f; 
                    break;  

                // translation 
                case 'z': 
                    tx -= translation_step; 
                    break; 
                case 'Z': 
                    tx += translation_step; 
                    break; 

                case 'x': 
                    ty -= translation_step; 
                    break; 
                case 'X': 
                    ty += translation_step; 
                    break; 

                case 'c': 
                    tz -= translation_step; 
                    break; 
                case 'C': 
                    tz += translation_step; 
                    break; 

                // scaling 
                case 'v': 
                    sx -= scale_step; 
                    break; 
                case 'V': 
                    sx += scale_step; 
                    break;
                    
                case 'b': 
                    sy -= scale_step; 
                    break; 
                case 'B': 
                    sy += scale_step; 
                    break;

                case 'n': 
                    sz -= scale_step; 
                    break; 
                case 'N': 
                    sz += scale_step; 
                    break;

                // rotation 
                case 'q': 
                    rx -= 0.5f; 
                    break; 

                case 'Q': 
                    rx += 0.5f; 
                    break; 

                case 'w': 
                    ry -= 0.5f; 
                    break; 

                case 'W': 
                    ry += 0.5f; 
                    break; 

                case 'e': 
                    rz -= 0.5f; 
                    break; 

                case 'E': 
                    rz += 0.5f; 
                    break; 
                    

                // printing camera values 
                case 'm': 
                    fprintf(gpFile, "\n%.2f %.2f %.2f\n%.2f %.2f %.2f\n%.2f %.2f %.2f\n", cameraX, cameraY, cameraZ, cameraCenterX, cameraCenterY, cameraCenterZ, cameraUpX, cameraUpY, cameraUpZ); 
                    fclose(gpFile); 
                    gpFile = fopen(gszgpFileName, "a");  
                    break; 

                case 'p': 
                    fprintf(gpFile, "\n%.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n%.2f %.2f %.2f\n", tx, ty, tz, sx, sy, sz, rx, ry, rz); 
                    fclose(gpFile); 
                    gpFile = fopen(gszgpFileName, "a"); 
                    break; 


                default: 
                    break; 
            }
            break; 

        case WM_CLOSE: 
            uninitialize(); 
            break; 

        case WM_DESTROY: 
            PostQuitMessage(0); 
            break; 

        default: 
            break; 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
} 

int initialize(void) 
{
    // function declarations 
    void resize(int, int); 

    // variable declarations 
    PIXELFORMATDESCRIPTOR pfd; 
    int iPixelFormatIndex = 0; 

    // code 
    ZeroMemory((void*)&pfd, sizeof(PIXELFORMATDESCRIPTOR)); 
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR); 
    pfd.nVersion = 1; 
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.iPixelType = PFD_TYPE_RGBA; 
    pfd.cColorBits = 32; 
    pfd.cRedBits = 8; 
    pfd.cGreenBits = 8; 
    pfd.cBlueBits = 8; 
    pfd.cAlphaBits = 8; 
    pfd.cDepthBits = 32; 

    // get DC
    ghdc = GetDC(ghwnd);
    if(ghdc == NULL) 
    {
        fprintf(gpFile, "GetDC() failed\n"); 
        return (-1); 
    } 

    // get matching pixel format index using ghdc and pfd 
    iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd); 
    if(iPixelFormatIndex == 0) 
    {
        fprintf(gpFile, "ChoosePixelFormat() failed\n"); 
        return (-2); 
    }

    // select pixel format of found index 
    if(SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE) 
    {
        fprintf(gpFile, "SetPixelFormat() failed\n"); 
        return (-3); 
    }

    // create rendering context using hdc and iPixelFormatIndex 
    ghrc = wglCreateContext(ghdc); 
    if(ghrc == NULL) 
    {
        fprintf(gpFile, "wglCreateContext() failed\n"); 
        return (-4); 
    }

    // make this as rendering context 
    if(wglMakeCurrent(ghdc, ghrc) == FALSE) 
    {
        fprintf(gpFile, "wglMakeCurrent() failed\n"); 
        return (-5); 
    }

    // OpenGL code start here 
    // depth related code 
    glShadeModel(GL_SMOOTH); 
    glClearDepth(1.0f); 
    glEnable(GL_DEPTH_TEST); 
    glDepthFunc(GL_LEQUAL); 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

    // for lighting 
    glEnable(GL_NORMALIZE);  

    // for texturing 
    glEnable(GL_TEXTURE_2D); 

    // instruct OpenGL to choose color to clear the screen 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 

    // initialize scenes 
    // initScene1(); 
    // initLights(); 
    initScene2(); 

    // warm up resize 
    resize(WIN_WIDTH, WIN_HEIGHT); 

    return (0); 
}

void resize(int width, int height) 
{
    // code 
    if(height <= 0) 
        height = 1; 

    // set viewport 
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); 

    // set matrix project mode 
    glMatrixMode(GL_PROJECTION); 

    // set to identity matrix 
    glLoadIdentity(); 

    // perspective 
    gluPerspective(
        45.0f, 
        (GLfloat)width/(GLfloat)height, 
        0.1f, 
        10000.0f 
    ); 
}

void display(void) 
{
    // code 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    // set matrix to model view mode 
    glMatrixMode(GL_MODELVIEW); 

    // set to identity matrix 
    glLoadIdentity(); 
    glTranslatef(0.0f, 0.0f, -5.0f); 

    gluLookAt(
		cameraX, cameraY, cameraZ, 
		cameraCenterX, cameraCenterY, cameraCenterZ, 
		cameraUpX, cameraUpY, cameraUpZ
	); 

    // displayScene1(); 
    displayScene2(); 

    // swap buffers 
    SwapBuffers(ghdc); 
}

void update(void) 
{
    // code 
    // updateScene1(); 

    gTimer = gTimer + 1; 
} 

void toggleFullScreen(void) 
{
    // variable declarations 
    MONITORINFO mi; 

    // code 
    if(gbFullScreen == FALSE) 
    {
        dwStyle = GetWindowLong(ghwnd, GWL_STYLE); 
        if(dwStyle & WS_OVERLAPPEDWINDOW) 
        {
            ZeroMemory((void*)&mi, sizeof(MONITORINFO)); 
            mi.cbSize = sizeof(MONITORINFO); 

            if(GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi)) 
            {
                SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW); 
                SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right-mi.rcMonitor.left, mi.rcMonitor.bottom-mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED); 
            }
        }

        ShowCursor(FALSE);
    }
    else 
    {
        SetWindowPlacement(ghwnd, &wpPrev); 
        SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPED); 
        SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_FRAMECHANGED); 

        ShowCursor(TRUE); 
    }
} 

void uninitialize(void) 
{
    // function declarations 
    void toggleFullScreen(void); 

    // code 
    if(gbFullScreen) 
    {
        toggleFullScreen(); 
        gbFullScreen = FALSE; 
    }
    
    if(wglGetCurrentContext() == ghrc) 
    {
        wglMakeCurrent(NULL, NULL); 
    }

    if(ghrc) 
    {
        wglDeleteContext(ghrc); 
        ghrc = NULL; 
    }

    if(ghdc) 
    {
        ReleaseDC(ghwnd, ghdc); 
        ghdc = NULL; 
    }

    // destroy window 
    if(ghwnd) 
    {
        DestroyWindow(ghwnd); 
        ghwnd = NULL; 
    }

    if(gpFile) 
    {
        fprintf(gpFile, "Programme terminated successfully"); 
        fclose(gpFile); 
        gpFile = NULL; 
    }
} 

