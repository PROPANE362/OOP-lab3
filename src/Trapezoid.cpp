#include "Trapezoid.h"

Trapezoid::Trapezoid() : _c(0, 0), _top(0), _bot(0), _h(0) {
    calcVerts();
}

Trapezoid::Trapezoid(const Point& c, double top, double bot, double h)
    : _c(c), _top(top), _bot(bot), _h(h) {
    if (top < 0 || bot < 0 || h < 0) {
        throw std::invalid_argument("Durak?");
    }
    calcVerts();
}

Trapezoid::Trapezoid(const Trapezoid& o)
    : _c(o._c), _top(o._top), _bot(o._bot), _h(o._h) {
    calcVerts();
}

Trapezoid::Trapezoid(Trapezoid&& o) noexcept
    : _c(o._c), _top(o._top), _bot(o._bot), _h(o._h) {
    calcVerts();
    o._top = 0;
    o._bot = 0;
    o._h = 0;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& o) {
    if (this != &o) {
        _c = o._c;
        _top = o._top;
        _bot = o._bot;
        _h = o._h;
        calcVerts();
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& o) noexcept {
    if (this != &o) {
        _c = o._c;
        _top = o._top;
        _bot = o._bot;
        _h = o._h;
        calcVerts();
        o._top = 0;
        o._bot = 0;
        o._h = 0;
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& o) const {
    return _c == o._c &&
           std::abs(_top - o._top) < 1e-9 &&
           std::abs(_bot - o._bot) < 1e-9 &&
           std::abs(_h - o._h) < 1e-9;
}

void Trapezoid::calcVerts() {
    double hh = _h / 2.0;
    double ht = _top / 2.0;
    double hb = _bot / 2.0;
    _v[0] = Point(_c.x - hb, _c.y - hh);
    _v[1] = Point(_c.x + hb, _c.y - hh);
    _v[2] = Point(_c.x + ht, _c.y + hh);
    _v[3] = Point(_c.x - ht, _c.y + hh);
}

Point Trapezoid::center() const {
    return _c;
}

Trapezoid::operator double() const {
    return (_top + _bot) * _h / 2.0;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapecii: ";
    for (int i = 0; i < 4; ++i) {
        os << _v[i];
        if (i < 3) os << " ";
    }
}

void Trapezoid::read(std::istream& is) {
    double cx, cy, top, bot, h;
    is >> cx >> cy >> top >> bot >> h;
    if (top < 0 || bot < 0 || h < 0) {
        throw std::invalid_argument("Duralei");
    }
    _c = Point(cx, cy);
    _top = top;
    _bot = bot;
    _h = h;
    calcVerts();
}

Figure* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::equals(const Figure& o) const {
    const Trapezoid* t = dynamic_cast<const Trapezoid*>(&o);
    if (!t) return false;
    return *this == *t;
}
