#include "Winpux/internal/global-lib.h"
#include <iostream>
#include <cstring>

namespace wpx::wpxInternal
{
    bool activatePlatform_Win32(wpxPlatform* platform)
    {
        const wpxPlatform activatedWin32 =
        {
            .platformID = WPX_WIN32_ID,
            .init = init_Win32,
            // .terminate = terminate_Win32,
            .initWindow = initWindow_Win32,
            // .destroyWindow = destroyWindow_Win32
            .pollEvents = pollEvents_Win32
        };

        *platform = activatedWin32;

        return true;
    }

    bool init_Win32()
    {
        WNDCLASSEX wcEx{};
        HINSTANCE hModule{};

        hModule = GetModuleHandle(NULL);

        wcEx.cbSize = sizeof(WNDCLASSEX);
        wcEx.lpfnWndProc = WindowProc;
        wcEx.hInstance = hModule;
        wcEx.lpszClassName = L"Winpux-Window";

        globalLib.win32 = wpxLibrary_Win32{};
        globalLib.initialized = false;
        globalLib.win32.hInstance = hModule;
        globalLib.win32.wc = wcEx;
        globalLib.win32.WND_CLASS_NAME = L"Winpux-Window";


        if (!RegisterClassEx(&(globalLib.win32.wc)))
            return false;

        return true;
    }

    


} // namespace wpx::wpxInternal
