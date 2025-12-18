#include "Array.h"

Array::Array() : _data(nullptr), _sz(0), _cap(0) {
    resize(4);
}

Array::Array(size_t cap) : _data(nullptr), _sz(0), _cap(0) {
    resize(cap > 0 ? cap : 4);
}

Array::Array(const Array& o) : _data(nullptr), _sz(0), _cap(0) {
    resize(o._cap);
    for (size_t i = 0; i < o._sz; ++i) {
        _data[i] = o._data[i]->clone();
    }
    _sz = o._sz;
}

Array::Array(Array&& o) noexcept : _data(o._data), _sz(o._sz), _cap(o._cap) {
    o._data = nullptr;
    o._sz = 0;
    o._cap = 0;
}

Array::~Array() {
    clear();
    delete[] _data;
}

Array& Array::operator=(const Array& o) {
    if (this != &o) {
        clear();
        delete[] _data;
        _data = nullptr;
        _sz = 0;
        _cap = 0;
        resize(o._cap);
        for (size_t i = 0; i < o._sz; ++i) {
            _data[i] = o._data[i]->clone();
        }
        _sz = o._sz;
    }
    return *this;
}

Array& Array::operator=(Array&& o) noexcept {
    if (this != &o) {
        clear();
        delete[] _data;
        _data = o._data;
        _sz = o._sz;
        _cap = o._cap;
        o._data = nullptr;
        o._sz = 0;
        o._cap = 0;
    }
    return *this;
}

void Array::resize(size_t newCap) {
    Figure** tmp = new Figure*[newCap];
    for (size_t i = 0; i < _sz; ++i) {
        tmp[i] = _data[i];
    }
    delete[] _data;
    _data = tmp;
    _cap = newCap;
}

void Array::clear() {
    for (size_t i = 0; i < _sz; ++i) {
        delete _data[i];
        _data[i] = nullptr;
    }
    _sz = 0;
}

void Array::add(Figure* f) {
    if (_sz >= _cap) {
        resize(_cap * 2);
    }
    _data[_sz++] = f;
}

void Array::remove(size_t idx) {
    if (idx >= _sz) {
        throw std::out_of_range("Indeks ne v diapazone..");
    }
    delete _data[idx];
    for (size_t i = idx; i < _sz - 1; ++i) {
        _data[i] = _data[i + 1];
    }
    --_sz;
}

Figure* Array::get(size_t idx) const {
    if (idx >= _sz) {
        throw std::out_of_range("Indeks ne v diapazone..");
    }
    return _data[idx];
}

size_t Array::size() const {
    return _sz;
}

double Array::totalArea() const {
    double sum = 0;
    for (size_t i = 0; i < _sz; ++i) {
        sum += static_cast<double>(*_data[i]);
    }
    return sum;
}

void Array::printAll(std::ostream& os) const {
    for (size_t i = 0; i < _sz; ++i) {
        os << "[" << i << "] " << *_data[i] << "\n";
        os << "    Centr: " << _data[i]->center() << "\n";
        os << "    ploshad da: " << static_cast<double>(*_data[i]) << "\n";
    }
}
