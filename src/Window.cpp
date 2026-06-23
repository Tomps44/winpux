#include "Winpux/window.h"

extern wpx::wpxInternal::wpxLib globalLib;

namespace wpx
{
    wpxWindow* wpxWindow::FromWindowImpl(wpxInternal::wpxWindowImpl* windowImpl)
    {
        wpxWindow window;

        window.impl = windowImpl;

        return &window;
    }

    const char* wpxWindow::GetTitle() const
    {
        return "Not implemented !!";
    }

    
} // namespace wpx
