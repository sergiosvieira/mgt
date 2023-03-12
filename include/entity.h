#ifndef ENTITY_H
#define ENTITY_H

#include "point.h"
#include "vector.h"
#include "draw.h"
#include "random.h"
#include "raylib.h"

namespace Mgt {

class Entity {
    Point position = {};
    Vector<2> acceleration = {0.f, 0.f};
    Vector<2> velocity = {0.f, 0.f};
    Vector<2> gravity = {0.f, 0.f};
    Color color = RAYWHITE;
    float radius = 15.f;
    bool use_acceleration = false;
    bool use_gravity = false;
    bool show_vector = false;
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
    void setUseAcceleration(bool value) {
        this->use_acceleration = value;
    }
    bool getUseAcceleration() const {
        return this->use_acceleration;
    }
    void setUseGravity(bool value) {
        this->use_gravity = value;
    }
    bool getUseGravity() const {
        return this->use_gravity;
    }
    void setVelocity(const Vector<2>& v) {
        this->velocity = v;
    }
    void setAcceleration(const Vector<2>& a) {
        this->acceleration = a;
    }
    void setGravity(const Vector<2>& g) {
        this->gravity = g;
    }
    void setPosition(const Point& p) {
        this->position = p;
    }
    void setRadius(float r) {
        this->radius = r;
    }
    virtual void draw() {
        DrawCircle(getX(), getY(), radius, color);
        if (use_acceleration
                && show_vector) {
            DrawVector(velocity + acceleration, GREEN, position);
        }
        if (use_gravity
                && show_vector) {
            DrawVector(gravity, RED, position);
        }
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
