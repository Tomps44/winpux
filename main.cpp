#include <iostream>

#define WPX_SET_PLATFORM_WIN32

#include "Winpux/window.h"
#include "Winpux/library.h"


using namespace wpx;


// This is the usage I'm aiming for

int main()
{

    wpxInternal::activateFunctions_Win32();

    if (!WinpuxLib::Init())
        std::terminate();

    wpxWindow* window = WinpuxLib::InitWindow();

    // while (!window->ShouldClose())
    // {
    //     window->PollEvents();

        


    // }

    // WinpuxLib::DestroyWindow(window);


    // WinpuxLib::Terminate();
   

    return 0;
}



