#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#define WPX_SET_PLATFORM_WIN32

#include "Winpux/window.h"
#include "Winpux/library.h"


using namespace wpx;


// This is the usage I'm aiming for

int main()
{
    if (!WinpuxLib::Init())
    {
        std::terminate();
    }

    wpxWindow* window = WinpuxLib::InitWindow();

    window->PollEvents();

    // while (!window->ShouldClose())
    // {



    // }

    WinpuxLib::DestroyWindow(window);

    WinpuxLib::Terminate();


    return 0;
}






