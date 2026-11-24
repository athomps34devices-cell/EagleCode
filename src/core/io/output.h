#pragma once

#include "../types/string.h"

namespace EagleIO
{
    void initialize();

    void print(const char* text);
    void print(const String& text);

    void println(const char* text);
    void println(const String& text);

    void newLine();
}