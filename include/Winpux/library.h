#pragma once

#include "internal/global-lib.h"
#include "window.h"

namespace wpx::WinpuxLib
{
    bool Init();
    void Terminate();


    wpxWindow* InitWindow();
    void DestroyWindow(wpxWindow* window);

    



} // namespace wpx