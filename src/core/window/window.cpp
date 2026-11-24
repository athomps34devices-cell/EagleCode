#include "window.h"
#include "platform/window_platform.h"

namespace EagleWindow
{
    bool initialize()
    {
        return EaglePlatform::initializeWindowSystem();
    }

    bool create(
        const char* title,
        int width,
        int height
    )
    {
        return EaglePlatform::createWindow(
            title,
            width,
            height
        );
    }

    int run()
    {
        return EaglePlatform::runWindow();
    }

    void shutdown()
    {
        EaglePlatform::shutdownWindow();
    }
}