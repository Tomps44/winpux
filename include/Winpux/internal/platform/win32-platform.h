#pragma once


#if !defined(NOMINMAX)
#   define NOMINMAX
#endif

#if !defined(WIN32_LEAN_AND_MEAN)
#   define WIN32_LEAN_AND_MEAN
#endif

#if !defined(VC_EXTRALEAN)
#   define VC_EXTRALEAN
#endif

#if !defined(UNICODE)
#   define UNICODE
#endif
#if !defined(_UNICODE)
#   define _UNICODE
#endif


#include "../setup.h"

#include <windows.h>


// Fwd declaration for the .cpp files that need it

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


namespace wpx::wpxInternal
{
    // Win32-related window stuff
    class wpxWindow_Win32
    {
    public:
        HWND handle{};
        HICON icon{};

        ATOM atom{};

        uint32_t width{}, height{};
        uint32_t xPos{}, yPos{};

        const char* title{};

        DWORD /* unsigned long */ style{};

        bool shouldClose{};




        // ..
    };

    

    //Win32-related global library stuff
    class wpxLibrary_Win32
    {
    public:
        HINSTANCE hInstance{};

        const wchar_t* WND_CLASS_NAME{};
        WNDCLASSEX wc{};

        // ...
    };

    //Win32-related global library stuff
    class wpxMonitor_Win32
    {
    public:
        HMONITOR handle{};

        // ...
    };

    //Win32-related global library stuff
    class wpxCursor_Win32
    {
    public:
        HCURSOR handle{};

        // ...
    };
}


#define WPX_WIN32_WINDOW_IMPL wpx::wpxInternal::wpxWindow_Win32 win32{}
#define WPX_WIN32_LIB_IMPL wpx::wpxInternal::wpxLibrary_Win32 win32{}
#define WPX_WIN32_MONITOR_IMPL wpx::wpxInternal::wpxMonitor_Win32 win32{}
#define WPX_WIN32_CURSOR_IMPL wpx::wpxInternal::wpxCursor_Win32 win32{}


/**
 * 
 * Need to change the architecture :
 * - platform-specific variables (HWND vs Display...) will be stored in a class 
 * 
 * - every single platform-specific function will be defined in the wpxInternal namespace,
 *   will take a pointer to a wpxWindow/wpxCursor/wpxMonitor... (forward-declared in setup.h),
 *   and will be defined in the right file (win32-.../wayland-.../x11-.../cocoa-...)
 * 
 * - function pointers (not platform-specific) will be defined for every single function, 
 *   and they will be set when calling the WinpuxLib::Init()
 * 
 * - wpxWindow, wpxCursor, wpxMonitor, WinpuxLib... will just be wrappers 
 *   that inline the call to the function pointers, and pass the arguments correctly ("this" if it expects a pointer to a wpxWindow/wpxCursor...,
 *   since the majority of the methods are member functions)
 */ 



namespace wpx::wpxInternal
{
    bool activatePlatform_Win32(wpxPlatform* platform);

    // For the Library namespace
    // They will be given to a function pointer
    // |
    // |
    // V


    bool init_Win32();
    void terminate_Win32();

    wpxWindowImpl* initWindow_Win32();
    void destroyWindow_Win32(wpxWindowImpl* window);

    // Member functions of the Window class
    // They will be given to a function pointer
    // |
    // |
    // V

    void setTitle_Win32(wpxWindowImpl* window, const char* title);
    const char* getTitle_Win32(wpxWindowImpl* window);

    bool shoudlClose_Win32(wpxWindowImpl* window);

    void setXPos_Win32(wpxWindowImpl* window, uint32_t xPos);
    void setYPos_Win32(wpxWindowImpl* window, uint32_t yPos);
    uint32_t getXPos_Win32(wpxWindowImpl* window);
    uint32_t getYPos_Win32(wpxWindowImpl* window);
    void getPos_Win32(wpxWindowImpl* window, uint32_t* xPosPtr, uint32_t* yPosPtr);

    void setWindowWidth_Win32(wpxWindowImpl* window, uint32_t width);
    void setWindowHeight_Win32(wpxWindowImpl* window, uint32_t width);
    uint32_t getWidth_Win32(wpxWindowImpl* window);
    uint32_t getHeight_Win32(wpxWindowImpl* window);
    void getSize_Win32(wpxWindowImpl* window, uint32_t* widthPtr, uint32_t* heightPtr);

    void pollEvents_Win32(wpxWindowImpl* windowImpl);
}

