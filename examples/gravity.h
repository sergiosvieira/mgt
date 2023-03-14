#ifndef GRAVITY_H
#define GRAVITY_H

#include <vector>
#include "../include/entity.h"
#include "../include/random.h"
#include "../include/draw.h"

using Entities = std::vector<Entity>;

int gravity() {
    const int larguraTela = 40 * 25;
    const int alturaTela = 30 * 25;
    Mgt::FPS = 1;
    Entity e({
        {larguraTela/2, alturaTela/2},
        {0.0f, -25.f},
        {12.f, -12.f},
        {-10.f, 10.f},
        RAYWHITE,
        10.f
    });
    e.setUseAcceleration(true);
    e.setUseGravity(true);
    show(larguraTela, alturaTela, [&]{
        e.move();
    }, [&] {
        Mgt::DrawGrid(40,
                      40,
                      larguraTela,
                      alturaTela,
                      25);
        e.draw();
    });
    return 0;
}

#endif // GRAVITY_H
