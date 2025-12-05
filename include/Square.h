#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include <stdexcept>
#include <cmath>

class Square : public Figure {
public:
    Square();
    Square(const Point& c, double side);
    Square(const Square& o);
    Square(Square&& o) noexcept;
    ~Square() override = default;

    Square& operator=(const Square& o);
    Square& operator=(Square&& o) noexcept;
    bool operator==(const Square& o) const;

    Point center() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    Figure* clone() const override;
    bool equals(const Figure& o) const override;

private:
    Point _c;
    double _a;
    void calcVerts();
    Point _v[4];
};

#endif
