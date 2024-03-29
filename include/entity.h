#ifndef ENTITY_H
#define ENTITY_H

#include "point.h"
#include "vector.h"
#include "draw.h"
#include "random.h"
#include "raylib.h"
#include "linear.h"

namespace Mgt {

struct EntitySettings {
    Point position = {};
    Vector<2> velocity = {0.f, 0.f};
    Vector<2> acceleration = {0.f, 0.f};
    Vector<2> gravity = {0.f, 0.f};
    Color color = RAYWHITE;
    float radius = 5.f;
};

class Entity {
    Point position = {};
    Vector<2> velocity = {0.f, 0.f};
    Vector<2> acceleration = {0.f, 0.f};
    Vector<2> gravity = {0.f, 0.f};
    Color color = RAYWHITE;
    float radius = 5.f;
    bool use_acceleration = false;
    bool use_gravity = false;
    bool show_vector = true;
public:
    Entity(){}
    Entity(const Point& position) {
        this->position = position;
    }
    Entity(const Color color) {
        this->color = color;
    }
    Entity(const EntitySettings& settings):
        position(settings.position),
        velocity(settings.velocity),
        acceleration(settings.acceleration),
        gravity(settings.gravity),
        color(settings.color),
        radius(settings.radius){}
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
        static float m = 50.f;
        if (show_vector) {
            Vector<2> fixed = unit_length(velocity) * m;
            DrawVector(fixed, RED, position);
        }
        if (use_acceleration
                && show_vector) {
            Vector<2> fixed = unit_length(acceleration) * m;
            DrawVector(fixed, GREEN, position);
        }
        if (use_gravity
                && show_vector) {
            Vector<2> fixed = unit_length(gravity) * m;
            DrawVector(fixed, BLUE, position);
        }
        DrawCircle(getX(), getY(), radius, color);
    }
    virtual void move() {
        if (use_acceleration) {
            this->velocity += this->acceleration;
        }
        if (use_gravity) {
            this->velocity += this->gravity;
        }
        this->position += this->velocity;
    }
};

}

#endif // ENTITY_H
