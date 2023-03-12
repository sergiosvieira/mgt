#ifndef ENTITY_H
#define ENTITY_H

#include "point.h"
#include "vector.h"
#include "raylib.h"

namespace Mgt {

class Entity {
    Point position = {};
    Vector<2> acceleration = {0.f, 0.1f};
    Vector<2> velocity = {0.f, 10.f};
    Vector<2> gravity = {0.f, 1.56f};
    Color color = RED;
    bool use_acceleration = true;
    bool use_gravity = true;
public:
    Entity(){}
    Entity(const Point& position) {
        this->position = position;
    }
    Entity(const Color color) {
        this->color = color;
    }
    Type getX() const {
        return position.first;
    }
    Type getY() const {
        return position.second;
    }
    Color getColor() const {
        return color;
    }
    void setColor(Color color) {
        this->color = color;
    }
    virtual void draw() {
        DrawCircle(getX(), getY(), 10.f, color);
    }
    virtual void move() {
        if (use_acceleration) {
            this->velocity += this->acceleration;
        }
        if (use_gravity) {
            this->acceleration -= this->gravity;
        }
        this->position += this->velocity;
    }
};

}

#endif // ENTITY_H
