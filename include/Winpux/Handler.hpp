#pragma once

#include <cstdint>
#include "Window.hpp"
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

namespace Winpux
{
    class wpxHandler
    {
    private:
        HINSTANCE hInstance {};

        WNDCLASS wc {};
        const char* WINDOW_CLASS_NAME = "Window Class Name";
         
        
    public:
        /**
         * For now, it directly creates the window !
         */
        bool Init();
        wpxWindow* InstantiateWindow(uint32_t width, uint32_t height, const char* title);
        bool DestroyWindow(wpxWindow* window);
        void Terminate();
        
    };

} // namespace Winpux