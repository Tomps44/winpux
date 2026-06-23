#include "Winpux/library.h"

extern wpx::wpxInternal::wpxLib globalLib;

namespace wpx::WinpuxLib
{
    bool Init()
    {
        return ::wpx::wpxInternal::init();
    }
    void Terminate()
    {
        return ::wpx::wpxInternal::terminate();
    }



    wpxWindow* InitWindow()
    {
        ::wpx::wpxInternal::wpxWindowImpl* impl = ::wpx::wpxInternal::initWindow();

        return wpxWindow::FromWindowImpl(impl);
    }


} // namespace wpx
