#ifndef WINDOW_H
#define WINDOW_H

#include <functional>
#include "raylib.h"
#include "draw.h"

namespace Mgt {

using Loop = std::function<void()>;

    void show(int screenWidth,
              int screenHeight,
              Loop loop) {
        InitWindow(screenWidth, screenHeight, "Vetor em Raylib");
        SetTargetFPS(60);
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            loop();
            EndDrawing();
        }
        CloseWindow();
    }

}

#endif // WINDOW_H
