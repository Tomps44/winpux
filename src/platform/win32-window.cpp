#include "Winpux/internal/global-lib.h"
#include <iostream>

namespace wpx::wpxInternal
{
    wpxWindowImpl* initWindow_Win32()
    {
        wpxWindowImpl* windowImpl = new wpxWindowImpl;

        windowImpl->win32.shouldClose = false;

        HWND hwnd = CreateWindowExW(
            0,
            globalLib.win32.WND_CLASS_NAME,
            L"Test Window",
            WS_OVERLAPPEDWINDOW,

            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL, 
            NULL,
            globalLib.win32.hInstance,
            NULL
        );

        if (hwnd == NULL)
            return nullptr;

        SetProp(hwnd, globalLib.win32.PROP_STRING_NAME, windowImpl);

        windowImpl->win32.handle = hwnd;

        ShowWindow(windowImpl->win32.handle, SW_SHOW);


        return windowImpl;
    }


    void pollEvents_Win32(wpxWindowImpl* windowImpl)
    {
        MSG msg{};

        while (!PeekMessage(&msg, windowImpl->win32.handle, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    bool shoudlClose_Win32(wpxWindowImpl* windowImpl)
    {
        return windowImpl->win32.shouldClose;
    }

} // wpx::wpxInternal

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    using namespace wpx::wpxInternal;

    wpxWindowImpl* impl = (wpxWindowImpl*)GetProp(hwnd, globalLib.win32.PROP_STRING_NAME);

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    case WM_CLOSE:
        impl->win32.shouldClose = true;
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
