#include "input.h"
#include "platform/console.h"

namespace EagleIO
{
    String readLine()
    {
        unsigned long long capacity = 4096;

        char* buffer = new char[capacity];

        EaglePlatform::readConsole(buffer, capacity);

        String result(buffer);

        delete[] buffer;

        return result;
    }
}