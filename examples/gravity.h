#ifndef GRAVITY_H
#define GRAVITY_H

#include <vector>
#include "../include/entity.h"
#include "../include/random.h"

using Entities = std::vector<Entity>;

Entities create(size_t size) {
    Entities r(size);
    for (size_t i = 0; i < size; ++i) {
        Entity e(Point{Mgt::random(0, 1024), 768});
        e.setVelocity({0.f, -13.f * Mgt::random()});
        e.setAcceleration({0.f, -0.15f * Mgt::random()});
        e.setUseAcceleration(true);
        e.setGravity({0.f, -0.01f * Mgt::random()});
        e.setUseGravity(true);
        e.setColor(random_color());
        r.push_back(e);
    }
    return r;
}

void reset(Entity& e) {
    e.setPosition(Point{Mgt::random(0, 1024), 768});
    e.setVelocity({0.f, -13.f * Mgt::random()});
    e.setAcceleration({0.f, -0.15f * Mgt::random()});
    e.setColor(random_color());
    e.setRadius(50.f * Mgt::random());
}

int gravity() {
    const int larguraTela = 1024;
    const int alturaTela = 768;
    Entities es = create(1000);
    show(larguraTela, alturaTela, BLACK, [&] {
        for (auto& e: es) {
            e.draw();
            e.move();
            if (e.getY() > alturaTela) {
                reset(e);
            }
        }
    });
    return 0;
}

#endif // GRAVITY_H
