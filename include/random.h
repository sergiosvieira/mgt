#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include "raylib.h"

namespace Mgt {
    int random(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
    double random() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        return dis(gen);
    }
    Color random_color() {
        return {
            255 * random(),
            255 * random(),
            255 * random(),
            255 * random(),
        };
    }
}

#endif // RANDOM_H
