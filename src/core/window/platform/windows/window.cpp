#include "../window_platform.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace EaglePlatform
{
    static HWND windowHandle = nullptr;
    static HINSTANCE applicationInstance = nullptr;

    static const char* windowClassName = "EagleCodeWindow";

    static LRESULT CALLBACK windowProcedure(
        HWND window,
        UINT message,
        WPARAM wParam,
        LPARAM lParam
    )
    {
        switch (message)
        {
            case WM_CLOSE:
                DestroyWindow(window);
                return 0;

            case WM_DESTROY:
                windowHandle = nullptr;
                PostQuitMessage(0);
                return 0;
        }

        return DefWindowProcA(
            window,
            message,
            wParam,
            lParam
        );
    }

    bool initializeWindowSystem()
    {
        applicationInstance = GetModuleHandleA(nullptr);

        WNDCLASSEXA windowClass = {};

        windowClass.cbSize = sizeof(WNDCLASSEXA);
        windowClass.lpfnWndProc = windowProcedure;
        windowClass.hInstance = applicationInstance;
        windowClass.lpszClassName = windowClassName;
        windowClass.hCursor = LoadCursorA(nullptr, IDC_ARROW);
        windowClass.hbrBackground = reinterpret_cast<HBRUSH>(
            COLOR_WINDOW + 1
        );

        if (!RegisterClassExA(&windowClass))
        {
            return false;
        }

        return true;
    }

    bool createWindow(
        const char* title,
        int width,
        int height
    )
    {
        windowHandle = CreateWindowExA(
            0,
            windowClassName,
            title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            width,
            height,
            nullptr,
            nullptr,
            applicationInstance,
            nullptr
        );

        if (windowHandle == nullptr)
        {
            return false;
        }

        ShowWindow(windowHandle, SW_SHOW);
        UpdateWindow(windowHandle);

        return true;
    }

    int runWindow()
    {
        MSG message = {};

        while (GetMessageA(&message, nullptr, 0, 0) > 0)
        {
            TranslateMessage(&message);
            DispatchMessageA(&message);
        }

        return static_cast<int>(message.wParam);
    }

    void shutdownWindow()
    {
        if (windowHandle != nullptr)
        {
            DestroyWindow(windowHandle);
            windowHandle = nullptr;
        }

        UnregisterClassA(
            windowClassName,
            applicationInstance
        );
    }
}