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
        DrawLine(sx, sy, static_cast<int>(endX), static_cast<int>(endY), color);
        DrawLine(static_cast<int>(endX), static_cast<int>(endY), static_cast<int>(endX - 20*cos(angle - PI/6)), static_cast<int>(endY - 20*sin(angle - PI/6)), color);
        DrawLine(static_cast<int>(endX), static_cast<int>(endY), static_cast<int>(endX - 20*cos(angle + PI/6)), static_cast<int>(endY - 20*sin(angle + PI/6)), color);
    }

}

#endif // DRAW_H
