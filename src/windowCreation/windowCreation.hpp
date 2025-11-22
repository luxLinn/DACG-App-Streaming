#pragma once
#include <Windows.h>

namespace windowCreation {
    inline HWND hWnd; // window handle
    inline WNDCLASSEX wc; // window class
    inline MSG msg;
    inline bool running = true;
    void init(HINSTANCE hInstance, int nCmdShow);
    void mainLoop();
    LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
}