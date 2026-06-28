#pragma once


#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__))
#   define _WIN32
#endif


#define WPX_PLATFORM_WIN32_BIT 0x0001
#define WPX_PLATFORM_X11_BIT 0x0010
#define WPX_PLATFORM_WAYLAND_BIT 0x0100
#define WPX_PLATFORM_COCOA_BIT 0x1000

#define WPX_WIN32_ID 0x00 
#define WPX_X11_ID 0x01 
#define WPX_WAYLAND_ID 0x02 
#define WPX_COCOA_ID 0x03 

#if defined(WPX_SET_PLATFORM_WIN32) // if the user forces the use of Win32
#   define WPX_PLATFORM WPX_PLATFORM_WIN32_BIT
#   define WPX_ACTIVE_PLATFORM_ID WPX_WIN32_ID

#elif defined(WPX_SET_PLATFORM_X11) // if the user forces the use of X11
#   define WPX_PLATFORM WPX_PLATFORM_X11_BIT
#   define WPX_ACTIVE_PLATFORM_ID WPX_X11_ID

#elif defined(WPX_SET_PLATFORM_WAYLAND) // if the user forces the use of Wayland
#   define WPX_PLATFORM WPX_PLATFORM_WAYLAND_BIT
#   define WPX_ACTIVE_PLATFORM_ID WPX_WAYLAND_ID

#elif defined(WPX_SET_PLATFORM_COCOA) // if the user forces the use of Cocoa
#   define WPX_PLATFORM WPX_PLATFORM_COCOA_BIT
#   define WPX_ACTIVE_PLATFORM_ID WPX_COCOA_ID


#elif defined(_WIN32) // if a target platform is not set, check if Win32 is available
#   define WPX_PLATFORM WPX_PLATFORM_WIN32_BIT
#   define WPX_ACTIVE_PLATFORM_ID WPX_WIN32_ID

#elif defined(__linux__) // if a target platform is not set, check if Linux is available, and set Wayland as default
#   define WPX_PLATFORM WPX_PLATFORM_WAYLAND_BIT
#   define WPX_ACTIVE_PLATFORM_ID WPX_WAYLAND_ID

#elif defined(__APPLE__) // if a target platform is not set, check if Apple is available
#   define WPX_PLATFORM WPX_PLATFORM_COCOA_BIT
#   define WPX_ACTIVE_PLATFORM_ID WPX_COCOA_ID

#else
#   error "The platform you are using is not supported by this library !"

#endif


namespace wpx
{
    class wpxWindow;
    class wpxLibrary;
    class wpxMonitor;
    class wpxCursor;

    class wpxWindowSpecs;

    namespace wpxInternal
    {

        /** Internal class used to store all the variables specific to the window, 
         *  that the user shouldn't have access to 
         */
        class wpxWindowImpl;
        class wpxPlatform;

        // Internal struct for defining a few things
        struct wpxWindowConfig{};
    }
}


#include <cstdint>
#include <cstddef>