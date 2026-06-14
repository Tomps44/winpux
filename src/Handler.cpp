#include "Winpux/Handler.hpp"
#include <iostream>

namespace Winpux
{
    

    bool wpxHandler::Init()
    {
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = WINDOW_CLASS_NAME;

        RegisterClass(&wc);

        HWND hwnd = CreateWindowExA(
            0,
            WINDOW_CLASS_NAME,
            "Test Window",
            WS_OVERLAPPEDWINDOW,
            
            CW_USEDEFAULT, CW_USEDEFAULT, 640, 360,
            
            NULL,
            NULL,
            hInstance,
            NULL
        );

        ShowWindow(hwnd, SW_SHOW);

        MSG msg{};
        while(GetMessage(&msg, NULL, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }


        return 0;
    }

} // namespace Winpux

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
