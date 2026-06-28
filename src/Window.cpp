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
        delete impl;
    }

    void wpxWindow::PollEvents()
    {
        wpxInternal::globalLib.platform->pollEvents(impl);
    }
    
} // namespace wpx
