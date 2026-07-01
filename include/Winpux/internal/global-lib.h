#pragma once

#include "platform.h"
#include "window-impl.h"

namespace wpx::wpxInternal
{
    /**
     * A class used to store all the platform-independent stuff.
     * 
     * 
     */
    class wpxPlatform
    {
    public:
        int platformID{};

        bool (*init)();
        void (*terminate)();

        wpxWindowImpl* (*initWindow)();
        void (*destroyWindow)(wpxWindowImpl* windowImpl);

        void (*pollEvents)(wpxWindowImpl* windowImpl);
        bool (*shouldClose)(wpxWindowImpl* windowImpl);


    };

    /**
     *  A class used to store all the variables common to all the files of the library.
     *
     * For design purposes, all the fields in this class are public, so `/!\ DO NOT MODIFY ANYTHING /!\` 
     * if you are not working on this library. 
     */ 
    class wpxLib
    {
    public:
        wpxPlatform* platform;
        WPX_LIB_IMPL;

        bool initialized{};

    };

    bool selectPlatform(wpxPlatform* platform);



    // This is the global object storing all the data required to run the library.
    extern wpxLib globalLib;

    
} // namespace wpx::wpxInternal
