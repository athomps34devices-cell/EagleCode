#ifndef EAGLE_WINDOW_PLATFORM_H
#define EAGLE_WINDOW_PLATFORM_H

namespace EaglePlatform
{
    bool initializeWindowSystem();

    bool createWindow(
        const char* title,
        int width,
        int height
    );

    int runWindow();

    void shutdownWindow();
}

#endif