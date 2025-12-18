#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <stdexcept>
#include <cmath>

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(const Point& c, double top, double bot, double h);
    Trapezoid(const Trapezoid& o);
    Trapezoid(Trapezoid&& o) noexcept;
    ~Trapezoid() override = default;

    Trapezoid& operator=(const Trapezoid& o);
    Trapezoid& operator=(Trapezoid&& o) noexcept;
    bool operator==(const Trapezoid& o) const;

    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* clone() const override;
    bool equals(const Figure& o) const override;

private:
    Point _c;
    double _top, _bot, _h;
    void calcVerts();
    Point _v[4];
};

#endif
