#pragma once

#include "internal/global-lib.h"

namespace wpx
{
    class wpxWindow
    {
    public:
        wpxInternal::wpxWindowImpl* impl;

    public:
        // static wpxWindow* FromWindowImpl(wpxInternal::wpxWindowImpl** windowImpl);
        void SetWindowImpl(wpxInternal::wpxWindowImpl* windowImpl);
        void DeleteWindowImpl();

        const char* GetTitle() const;
        void SetTitle(const char* newTitle);


        bool ShouldClose() const;
        void PollEvents();


        uint32_t GetXPos() const;
        uint32_t GetYPos() const;
        void GetPos(uint32_t* xPosAdr, uint32_t* yPosAdr) const;

        void SetXPos(uint32_t newXPos);
        void SetYPos(uint32_t newYPos);
        void SetPos(uint32_t newXPos, uint32_t newYPos);
    };

} // namespace wpx
