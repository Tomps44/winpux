#include "Winpux/internal/global-lib.h"
#include <iostream>

namespace wpx::wpxInternal
{
    wpxWindowImpl* initWindow_Win32()
    {
        wpxWindowImpl* windowImpl = new wpxWindowImpl;

        HWND hwnd = CreateWindowExW(
            WS_EX_OVERLAPPEDWINDOW,
            // globalLib.win32.WND_CLASS_NAME,
            L"Winpux-Window",
            L"Stupid API",
            WS_OVERLAPPEDWINDOW,

            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL, 
            NULL,
            globalLib.win32.hInstance,
            NULL
        );

        if (hwnd == NULL)
            return nullptr;

        // if (!windowImpl)
        //     std::cout << "J'en ai marre\n"; 

        // std::cout << "wpxWindowImpl* adr: [" << &windowImpl << "]\n";

        windowImpl->win32.handle = hwnd;

        ShowWindow(windowImpl->win32.handle, SW_SHOW);

        

        MSG msg{};
        while (GetMessage(&msg, windowImpl->win32.handle, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // while (PeekMessage(&msg, windowImpl->win32.handle, 0, 0, PM_NOREMOVE))
        // {
        //     TranslateMessage(&msg);
        //     DispatchMessage(&msg);
        // }

        return windowImpl;
    }


    void pollEvents_Win32(wpxWindowImpl* windowImpl)
    {
        MSG msg{};

        while (!PeekMessage(&msg, windowImpl->win32.handle, 0, 0, PM_NOREMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

} // wpx::wpxInternal

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
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

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
