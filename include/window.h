#ifndef WINDOW_H
#define WINDOW_H

#include <functional>
#include "raylib.h"
#include "draw.h"

namespace Mgt {

using Loop = std::function<void()>;

    void show(int screenWidth,
              int screenHeight,
              Color color = BLACK,
              Loop loop = nullptr) {
        InitWindow(screenWidth, screenHeight, "");
        SetTargetFPS(60);
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(color);
            if (loop) loop();
            EndDrawing();
        }
        CloseWindow();
    }

}

#endif // WINDOW_H
