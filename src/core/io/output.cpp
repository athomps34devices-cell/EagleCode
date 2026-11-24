#include "output.h"
#include "platform/console.h"

namespace EagleIO
{
    void initialize()
    {
        EaglePlatform::initializeConsole();
    }

    void print(const char* text)
    {
        EaglePlatform::writeConsole(text);
    }

    void print(const String& text)
    {
        print(text.c_str());
    }

    void println(const char* text)
    {
        print(text);
        newLine();
    }

    void println(const String& text)
    {
        print(text);
        newLine();
    }

    void newLine()
    {
        print("\r\n");
    }
}