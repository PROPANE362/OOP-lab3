#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

struct Point {
    double x, y;

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    bool operator==(const Point& o) const {
        return std::abs(x - o.x) < 1e-9 && std::abs(y - o.y) < 1e-9;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

inline std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

#endif
