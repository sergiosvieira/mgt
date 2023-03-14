#ifndef WINDOW_H
#define WINDOW_H

#include <functional>
#include "raylib.h"
#include "draw.h"

namespace Mgt {

    using Loop = std::function<void()>;

    int FPS = 60;
    Color BackgroundColod = BLACK;

    void show(int screenWidth,
              int screenHeight,
              Loop update = nullptr,
              Loop render = nullptr) {
        InitWindow(screenWidth, screenHeight, "");
        SetTargetFPS(FPS);
        while (!WindowShouldClose()) {
            if (update) update();
            BeginDrawing();
            ClearBackground(BackgroundColod);
            if (render) render();
            EndDrawing();
        }
        CloseWindow();
    }

}

#endif // WINDOW_H
