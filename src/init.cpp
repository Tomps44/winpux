#include "Winpux/internal/global-lib.h"

namespace wpx::wpxInternal
{
    bool selectPlatform(wpxPlatform* platform)
    {
        static const struct
        {
            bool (*activatePlatform)(wpxPlatform* platform);
        }
        supportedPlatforms[] = 
        {
            activatePlatform_Win32,
        };

        if (WPX_ACTIVE_PLATFORM_ID > sizeof(supportedPlatforms) / sizeof(supportedPlatforms[0]))
            return false;
        

        return supportedPlatforms[WPX_ACTIVE_PLATFORM_ID].activatePlatform(platform);
    }
  


} // namespace wpx::wpxInternal
