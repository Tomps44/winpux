#include "Winpux/internal/global_lib_internal.h"

extern wpx::wpxInternal::wpxLib globalLib;

namespace wpx::wpxInternal
{
    bool init_Win32()
    {
        globalLib.win32.hInstance = GetModuleHandle(NULL);

        globalLib.win32.wc.lpfnWndProc = WindowProc;
        globalLib.win32.wc.hInstance = globalLib.win32.hInstance;
        globalLib.win32.wc.lpszClassName = globalLib.win32.WND_CLASS_NAME;
    }

    void activateFunctions_Win32()
    {
        initWindow = initWindow_Win32;
        init = init_Win32;
        destroyWindow = destroyWindow_Win32;

    }


} // namespace wpx::wpxInternal
