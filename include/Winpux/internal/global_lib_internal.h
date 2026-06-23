#pragma once

#include "platform.h"
#include "window_impl.h"

namespace wpx::wpxInternal
{
    /**
     *  The class used to store all the variables common to all the files of the library.
     *
     * For design purposes, all the fields in this class are public, so `/!\ DO NOT MODIFY ANYTHING /!\` 
     * if you are not editing a file coming from :
     * `Winpux/include/Winpux/internal/ *.h` or `Winpux/src/internal`.
     * 
     */ 
    class wpxLib
    {
    public:
        WPX_LIB_IMPL;
    };

    // This is the global object storing all the data required to run the library.
    extern wpxLib globalLib;


    bool (*init)();
    void (*terminate)();

    wpxWindowImpl* (*initWindow)();
    void (*destroyWindow)(wpxWindowImpl*);






} // namespace wpx::wpxInternal
