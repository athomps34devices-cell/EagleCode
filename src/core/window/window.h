#ifndef EAGLE_WINDOW_H
#define EAGLE_WINDOW_H

namespace EagleWindow
{
    bool initialize();

    bool create(
        const char* title,
        int width,
        int height
    );

    int run();

    void shutdown();
}

#endif