#include "Winpux/Window.hpp"
#include "Winpux/Handler.hpp"

using namespace Winpux;

// This is the usage I'm aiming for

int main()
{
    Winpux::wpxWindow b;


    wpxHandler winHandler;

    if (!winHandler.Init())
        return -1;

    

    // wpxWindow* w = winHandler.InstantiateWindow(640, 360, "Test Window");

    // if (!w)
    //     return -1;

    // while (!w->ShouldClose())
    // {
    //     w->PollEvents();



    //     // ...
    // }

    // winHandler.DestroyWindow(w);


    // winHandler.Terminate();


    return 0;
}



