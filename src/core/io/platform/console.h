#ifndef EAGLE_CONSOLE_H
#define EAGLE_CONSOLE_H

namespace EaglePlatform
{
    void initializeConsole();

    void writeConsole(const char* text);
    void readConsole(char* buffer, unsigned long long capacity);
}

#endif