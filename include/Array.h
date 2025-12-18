#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include <cstddef>
#include <stdexcept>

class Array {
public:
    Array();
    Array(size_t cap);
    Array(const Array& o);
    Array(Array&& o) noexcept;
    ~Array();

    Array& operator=(const Array& o);
    Array& operator=(Array&& o) noexcept;

    void add(Figure* f);
    void remove(size_t idx);
    Figure* get(size_t idx) const;
    size_t size() const;
    double totalArea() const;
    void printAll(std::ostream& os) const;

private:
    Figure** _data;
    size_t _sz;
    size_t _cap;

    void resize(size_t newCap);
    void clear();
};

#endif
