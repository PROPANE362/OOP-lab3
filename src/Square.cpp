#include "Square.h"

Square::Square() : _c(0, 0), _a(0) {
    calcVerts();
}

Square::Square(const Point& c, double side) : _c(c), _a(side) {
    if (side < 0) {
        throw std::invalid_argument("kys");
    }
    calcVerts();
}

Square::Square(const Square& o) : _c(o._c), _a(o._a) {
    calcVerts();
}

Square::Square(Square&& o) noexcept : _c(o._c), _a(o._a) {
    calcVerts();
    o._a = 0;
}

Square& Square::operator=(const Square& o) {
    if (this != &o) {
        _c = o._c;
        _a = o._a;
        calcVerts();
    }
    return *this;
}

Square& Square::operator=(Square&& o) noexcept {
    if (this != &o) {
        _c = o._c;
        _a = o._a;
        calcVerts();
        o._a = 0;
    }
    return *this;
}

bool Square::operator==(const Square& o) const {
    return _c == o._c && std::abs(_a - o._a) < 1e-9;
}

void Square::calcVerts() {
    double half = _a / 2.0;
    _v[0] = Point(_c.x - half, _c.y - half);
    _v[1] = Point(_c.x + half, _c.y - half);
    _v[2] = Point(_c.x + half, _c.y + half);
    _v[3] = Point(_c.x - half, _c.y + half);
}

Point Square::center() const {
    return _c;
}

Square::operator double() const {
    return _a * _a;
}

void Square::print(std::ostream& os) const {
    os << "Kvadrateke: ";
    for (int i = 0; i < 4; ++i) {
        os << _v[i];
        if (i < 3) os << " ";
    }
}

void Square::read(std::istream& is) {
    double cx, cy, side;
    is >> cx >> cy >> side;
    if (side < 0) {
        throw std::invalid_argument("ubeysya pj");
    }
    _c = Point(cx, cy);
    _a = side;
    calcVerts();
}

Figure* Square::clone() const {
    return new Square(*this);
}

bool Square::equals(const Figure& o) const {
    const Square* sq = dynamic_cast<const Square*>(&o);
    if (!sq) return false;
    return *this == *sq;
}
