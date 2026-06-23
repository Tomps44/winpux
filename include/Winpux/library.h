#pragma once

#include "internal/platform.h"
#include "internal/global_lib_internal.h"
#include "window.h"

namespace wpx::WinpuxLib
{
    bool Init();
    void Terminate();


    wpxWindow* InitWindow();
    inline void DestroyWindow(wpxWindow* window);

    



} // namespace wpx