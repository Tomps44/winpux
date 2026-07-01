#include "Winpux/window.h"

#include <iostream>

namespace wpx
{
    void wpxWindow::SetWindowImpl(wpxInternal::wpxWindowImpl* windowImpl)
    {
        impl = windowImpl;
    }
    void wpxWindow::DeleteWindowImpl()
    {
        DestroyWindow(impl->win32.handle);
        DestroyIcon(impl->win32.icon);
        delete impl;
    }

    void wpxWindow::PollEvents()
    {
        if (!wpxInternal::globalLib.platform)
            std::cout << "globalLib.platform is null ??\n";
        wpxInternal::globalLib.platform->pollEvents(impl);
    }

    bool wpxWindow::ShouldClose() const
    {
        return wpxInternal::globalLib.platform->shouldClose(impl);
    }
    
} // namespace wpx
