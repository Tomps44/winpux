#pragma once

#include <cstdint>

namespace Winpux
{
    class wpxWindow
    {
    private:
        bool shouldClose;
        uint32_t width, height;
         
        
    public:
        bool ShouldClose();
        void PollEvents();
        
    };

} // namespace Winpux
