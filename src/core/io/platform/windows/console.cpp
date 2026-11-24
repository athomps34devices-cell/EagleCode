#include "../console.h"

#ifdef _WIN32

using HANDLE = void*;
using DWORD = unsigned long;
using BOOL = int;

extern "C"
{
    __declspec(dllimport) HANDLE __stdcall GetStdHandle(DWORD handle);

    __declspec(dllimport) BOOL __stdcall WriteConsoleA(
        HANDLE output,
        const void* buffer,
        DWORD characters,
        DWORD* written,
        void* reserved
    );

    __declspec(dllimport) BOOL __stdcall ReadConsoleA(
        HANDLE input,
        void* buffer,
        DWORD characters,
        DWORD* received,
        void* reserved
    );
}

namespace EaglePlatform
{
    static HANDLE inputHandle = nullptr;
    static HANDLE outputHandle = nullptr;

    void initializeConsole()
    {
        inputHandle = GetStdHandle(static_cast<DWORD>(-10));
        outputHandle = GetStdHandle(static_cast<DWORD>(-11));
    }

    void writeConsole(const char* text)
    {
        if (text == nullptr || outputHandle == nullptr)
        {
            return;
        }

        DWORD length = 0;

        while (text[length] != '\0')
        {
            length++;
        }

        DWORD written = 0;

        WriteConsoleA(
            outputHandle,
            text,
            length,
            &written,
            nullptr
        );
    }

    void readConsole(char* buffer, unsigned long long capacity)
    {
        if (buffer == nullptr || capacity == 0 || inputHandle == nullptr)
        {
            return;
        }

        unsigned long long size = 0;

        while (size + 1 < capacity)
        {
            char character;
            DWORD received = 0;

            if (!ReadConsoleA(
                inputHandle,
                &character,
                1,
                &received,
                nullptr
            ) || received == 0)
            {
                break;
            }

            if (character == '\r' || character == '\n')
            {
                break;
            }

            buffer[size++] = character;
        }

        buffer[size] = '\0';
    }
}

#endif