#include <Vec2.h>
#include <cmath>

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

float Vec2::magnitude() const {
    return sqrt(x * x + y * y);
}

Vec2 Vec2::normalized() const {
    float mag = magnitude();
    if (mag == 0) {
        return Vec2(0, 0); // Evita divisão por zero
    }
    return Vec2(x / mag, y / mag);
}

float Vec2::distance(const Vec2& other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

float Vec2::angle() const {
    return atan2(y, x);
}

float Vec2::angleTo(const Vec2& other) const {
    float dx = other.x - x;
    float dy = other.y - y;
    return atan2(dy, dx);
}

Vec2 Vec2::rotated(float angle) const {
    float cosA = cos(angle);
    float sinA = sin(angle);
    return Vec2(x * cosA - y * sinA, y * cosA + x * sinA);
}