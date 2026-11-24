#include "core/io/output.h"
#include "core/window/window.h"

int main()
{
    EagleIO::initialize();

    EagleIO::println("Starting EagleCode...");

    if (!EagleWindow::initialize())
    {
        EagleIO::println("Failed to initialize window system.");
        return 1;
    }

    if (!EagleWindow::create(
        "EagleCode",
        1280,
        800
    ))
    {
        EagleIO::println("Failed to create EagleCode window.");

        EagleWindow::shutdown();

        return 1;
    }

    EagleIO::println("EagleCode window created.");

    int result = EagleWindow::run();

    EagleWindow::shutdown();

    return result;
}