#include "Rectangle.h"

Rectangle::Rectangle() : _c(0, 0), _w(0), _h(0) {
    calcVerts();
}

Rectangle::Rectangle(const Point& c, double w, double h) : _c(c), _w(w), _h(h) {
    if (w < 0 || h < 0) {
        throw std::invalid_argument("Ebloid?");
    }
    calcVerts();
}

Rectangle::Rectangle(const Rectangle& o) : _c(o._c), _w(o._w), _h(o._h) {
    calcVerts();
}

Rectangle::Rectangle(Rectangle&& o) noexcept : _c(o._c), _w(o._w), _h(o._h) {
    calcVerts();
    o._w = 0;
    o._h = 0;
}

Rectangle& Rectangle::operator=(const Rectangle& o) {
    if (this != &o) {
        _c = o._c;
        _w = o._w;
        _h = o._h;
        calcVerts();
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& o) noexcept {
    if (this != &o) {
        _c = o._c;
        _w = o._w;
        _h = o._h;
        calcVerts();
        o._w = 0;
        o._h = 0;
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& o) const {
    return _c == o._c && std::abs(_w - o._w) < 1e-9 && std::abs(_h - o._h) < 1e-9;
}

void Rectangle::calcVerts() {
    double hw = _w / 2.0;
    double hh = _h / 2.0;
    _v[0] = Point(_c.x - hw, _c.y - hh);
    _v[1] = Point(_c.x + hw, _c.y - hh);
    _v[2] = Point(_c.x + hw, _c.y + hh);
    _v[3] = Point(_c.x - hw, _c.y + hh);
}

Point Rectangle::center() const {
    return _c;
}

Rectangle::operator double() const {
    return _w * _h;
}

void Rectangle::print(std::ostream& os) const {
    os << "Pryamougolne: ";
    for (int i = 0; i < 4; ++i) {
        os << _v[i];
        if (i < 3) os << " ";
    }
}

void Rectangle::read(std::istream& is) {
    double cx, cy, w, h;
    is >> cx >> cy >> w >> h;
    if (w < 0 || h < 0) {
        throw std::invalid_argument("kys");
    }
    _c = Point(cx, cy);
    _w = w;
    _h = h;
    calcVerts();
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

bool Rectangle::equals(const Figure& o) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(&o);
    if (!r) return false;
    return *this == *r;
}
