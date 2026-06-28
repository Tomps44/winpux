#pragma once

#include "setup.h"



#if WPX_PLATFORM & WPX_PLATFORM_WIN32_BIT
#   include "platform/win32-platform.h"
#else
#   define WPX_WIN32_WINDOW_IMPL 
#   define WPX_WIN32_LIB_IMPL 
#   define WPX_WIN32_MONITOR_IMPL 
#   define WPX_WIN32_CURSOR_IMPL 
#endif



#if WPX_PLATFORM & WPX_PLATFORM_X11_BIT
#   include "platform/x11-platform.h"
#else
#   define WPX_X11_WINDOW_IMPL 
#   define WPX_X11_LIB_IMPL 
#   define WPX_X11_MONITOR_IMPL 
#   define WPX_X11_CURSOR_IMPL 
#endif



#if WPX_PLATFORM & WPX_PLATFORM_WAYLAND_BIT
#   include "platform/wayland-platform.h"
#else
#   define WPX_WAYLAND_WINDOW_IMPL 
#   define WPX_WAYLAND_LIB_IMPL 
#   define WPX_WAYLAND_MONITOR_IMPL 
#   define WPX_WAYLAND_CURSOR_IMPL 
#endif



#if WPX_PLATFORM & WPX_PLATFORM_COCOA_BIT
#   include "platform/cocoa-platform.h"
#else
#   define WPX_COCOA_WINDOW_IMPL 
#   define WPX_COCOA_LIB_IMPL 
#   define WPX_COCOA_MONITOR_IMPL 
#   define WPX_COCOA_CURSOR_IMPL 
#endif



#define WPX_WINDOW_IMPL \
    WPX_WIN32_WINDOW_IMPL \
    WPX_X11_WINDOW_IMPL \
    WPX_WAYLAND_WINDOW_IMPL \
    WPX_COCOA_WINDOW_IMPL 


#define WPX_MONITOR_IMPL \
    WPX_WIN32_MONITOR_IMPL \
    WPX_X11_MONITOR_IMPL \
    WPX_WAYLAND_MONITOR_IMPL \
    WPX_COCOA_MONITOR_IMPL 


#define WPX_LIB_IMPL \
    WPX_WIN32_LIB_IMPL \
    WPX_X11_LIB_IMPL \
    WPX_WAYLAND_LIB_IMPL \
    WPX_COCOA_LIB_IMPL 

    
#define WPX_CURSOR_IMPL \
    WPX_WIN32_CURSOR_IMPL \
    WPX_X11_CURSOR_IMPL \
    WPX_WAYLAND_CURSOR_IMPL \
    WPX_COCOA_CURSOR_IMPL 



