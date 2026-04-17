#include <Rect.h>
#include <cmath>


Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}


Vec2 Rect::center() const {
    return Vec2(x + w / 2, y + h / 2);
}

float Rect::distance(const Rect& other) const {
    Vec2 c1 = center();
    Vec2 c2 = other.center();
    return c1.distance(c2);
}

bool Rect::contains(const Vec2& point) const {
    return (point.x >= x && point.x <= x + w && point.y >= y && point.y <= y + h);
}