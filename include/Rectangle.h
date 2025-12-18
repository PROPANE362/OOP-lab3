#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <stdexcept>
#include <cmath>

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(const Point& c, double w, double h);
    Rectangle(const Rectangle& o);
    Rectangle(Rectangle&& o) noexcept;
    ~Rectangle() override = default;

    Rectangle& operator=(const Rectangle& o);
    Rectangle& operator=(Rectangle&& o) noexcept;
    bool operator==(const Rectangle& o) const;

    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* clone() const override;
    bool equals(const Figure& o) const override;

private:
    Point _c;
    double _w, _h;
    void calcVerts();
    Point _v[4];
};

#endif
