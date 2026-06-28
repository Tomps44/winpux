#include "Winpux/library.h"
#include <iostream>

namespace wpx::WinpuxLib
{
    bool Init()
    {
        using namespace wpxInternal;

        globalLib = wpxLib{};
        globalLib.platform = new wpxPlatform;

        if (!selectPlatform(globalLib.platform))
            return false;

        if (!globalLib.platform->init())
            return false;

        return true;
    }

    void Terminate()
    {
        using namespace wpxInternal;

        delete globalLib.platform;
    }

    wpxWindow* InitWindow()
    {
        wpxWindow* window = new wpxWindow;

        window->SetWindowImpl(wpx::wpxInternal::globalLib.platform->initWindow());

        return window;
    }

    void DestroyWindow(wpxWindow* window)
    {
        window->DeleteWindowImpl();
    }
    


} // namespace wpx
