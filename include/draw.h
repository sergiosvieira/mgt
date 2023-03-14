#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"
#include "linear.h"
#include "point.h"

namespace Mgt {

    void DrawVector(const Vector<2>& vector,
                    Color color,
                    const Point& start_point = {0.f, 0.f}) {
        float dx = vector[0];
        float dy = vector[1];
        auto [sx, sy] = start_point;
        float angle = atan2(dy, dx);
        float endX = sx + dx;
        float endY = sy + dy;
        DrawLineEx({sx, sy}, {static_cast<int>(endX), static_cast<int>(endY)}, 2.f, color);
        DrawLineEx({static_cast<int>(endX), static_cast<int>(endY)}, {static_cast<int>(endX - 20*cos(angle - PI/6)), static_cast<int>(endY - 20*sin(angle - PI/6))}, 2.f, color);
        DrawLineEx({static_cast<int>(endX), static_cast<int>(endY)}, {static_cast<int>(endX - 20*cos(angle + PI/6)), static_cast<int>(endY - 20*sin(angle + PI/6))}, 2.f, color);
    }

    void DrawGrid(size_t rows,
                  size_t cols,
                  size_t width,
                  size_t height,
                  size_t cellSize,
                  Color color= { 200, 200, 200, 100 }) {
        size_t s = 0;
        for (size_t i = 0; i < rows; ++i) {
            s = i * cellSize;
            DrawLine(0, s, width, s, color);
        }
        for (size_t i = 0; i < cols; ++i) {
            s = i * cellSize;
            DrawLine(s, 0, s, height, color);
        }
    }

}

#endif // DRAW_H
