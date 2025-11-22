#include <Windows.h>
#include <chrono>
#include <thread>
#include "windowCreation/windowCreation.hpp"

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    const int fps = 60;
    windowCreation::init(hInstance, nCmdShow);

    while (windowCreation::running) {
        std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::high_resolution_clock::now();
        const auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(time);

        // mainloop
        windowCreation::mainLoop();

        // buffer for how much time we didn't use
        std::chrono::time_point<std::chrono::steady_clock> laterTime = std::chrono::high_resolution_clock::now();
        const long long timeToBuffer = (1000 / fps) - std::chrono::duration_cast<std::chrono::milliseconds>(laterTime - time).count();
        if (timeToBuffer > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToBuffer));
        }
    }

    return windowCreation::msg.wParam;
}