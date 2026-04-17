#ifndef RECT_H
#define RECT_H
#include "Vec2.h"

class Rect {
    public:
        float x;
        float y;
        float w;
        float h;

        Rect(float x = 0, float y = 0, float w = 0, float h = 0);

        // ● Obter coordenadas do centro de um retângulo
        Vec2 center() const;

        // ● Distância entre o centro de dois Rects
        float distance(const Rect& other) const;

        // ● Saber se um ponto está dentro de um Rect
        bool contains(const Vec2& point) const;
};


#endif