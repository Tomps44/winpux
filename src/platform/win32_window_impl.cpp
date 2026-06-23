#include "Winpux/internal/global_lib_internal.h"

extern wpx::wpxInternal::wpxLib globalLib;

namespace wpx::wpxInternal
{
    wpxWindowImpl* initWindow_Win32()
    {
        wpxWindowImpl window;
        
        window.win32.atom = RegisterClassExW(&globalLib.win32.wc);

        window.win32.handle = CreateWindowExW(
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

        if (!window.win32.handle)
            return nullptr;

        ShowWindow(window.win32.handle, SW_SHOW);

        return &window;
    }



    void destroyWindow_Win32(wpxWindowImpl* windowImpl)
    {
        DestroyWindow(windowImpl->win32.handle);
        delete windowImpl->win32.title;    
    }




    void pollEvents_Win32(wpxWindowImpl* window)
    {
        MSG msg{};

        while (GetMessage(&msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }




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


} // namespace wpx::wpxInternal
