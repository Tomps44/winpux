#pragma once

#include "platform.h"

namespace wpx::wpxInternal
{
    class wpxWindowImpl
    {
    public:
        uint32_t minWidth, minHeight;    
        uint32_t maxWidth, maxHeight;
        
        WPX_WINDOW_IMPL;

        // ...

    };

} // namespace wpx::wpxInternal