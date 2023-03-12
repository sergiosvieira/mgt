#ifndef POINT_H
#define POINT_H

#include "default.h"
#include "vector.h"
#include <utility>
#include <cmath>

namespace Mgt {
    using Point = std::pair<Type, Type>;

    std::ostream& operator<<(std::ostream& out,
                             const Point& p) {
        out << "("
            << p.first
            << ", "
            << p.second
            << ")";
        return out;
    }

    Vector<2> operator-(const Point& p1,
                        const Point& p2) {
        auto [x1, y1] = p1;
        auto [x2, y2] = p2;
        Vector<2> result = {x1 - x2, y1 - y2};
        return result;
    }

    Point& operator+=(Point& p,
                      const Vector<2>& v) {
        auto& [x, y] = p;
        x += v[0];
        y += v[1];
        return p;
    }

    Type distance(const Point& p1,
                  const Point&p2) {
        auto [x1, y1] = p1;
        auto [x2, y2] = p2;
        return std::hypot(x2 - x1, y2 - y1);
    }
}

#endif // POINT_H
