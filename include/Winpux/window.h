#pragma once

#include "internal/global_lib_internal.h"

namespace wpx
{
    class wpxWindow
    {
    private:
        wpxInternal::wpxWindowImpl* impl;

    public:
        static wpxWindow* FromWindowImpl(wpxInternal::wpxWindowImpl* windowImpl);

        const char* GetTitle() const;
        void SetTitle(const char* newTitle);

        bool ShouldClose() const;
        void PollEvents();
    };

} // namespace wpx
