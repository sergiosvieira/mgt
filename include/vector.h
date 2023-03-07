#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>
#include <array>
#include <cmath>
#include "default.h"


namespace Mgt {
    template <std::size_t Cols>
    using Vector = std::array<Type, Cols>;

    template<std::size_t Cols>
    std::ostream& operator<<(std::ostream& out,
                             const Vector<Cols>& v) {
        out << '[';
        for (size_t i = 0; i < v.size(); ++i) {
            out << v[i];
            if (i < v.size() - 1) out << ' ';
        }
        out << "]";
        return out;
    }

    // Initialize a vector with Cols dimentions
    // last value is always equal to 1.f
    template<size_t Cols>
    Vector<Cols> init() {
        Vector<Cols> result = {};
        result[Cols-1] = 1.f;
        return result;
    }

    // Multiplies a vector by a scalar
    template<size_t Cols>
    Vector<Cols> operator*(const Vector<Cols>& v,
                           Type scalar) {
        Vector<Cols> result = v;
        for (size_t i = 0; i < v.size(); ++i) {
            result[i] *= scalar;
        }
        return result;
    }

    // Adds vectors
    template<size_t Cols>
    Vector<Cols> operator+(const Vector<Cols>& v1,
                           const Vector<Cols>& v2) {
        Vector<Cols> result = v1;
        for (size_t i = 0; i < v1.size(); ++i) {
            result[i] += v2[i];
        }
        return result;
    }

    template<size_t Cols>
    Vector<Cols> operator-(const Vector<Cols>& v) {
        Vector<Cols> result = v;
        for (size_t i = 0; i < v.size(); ++i) {
            result[i] = -result[i];
        }
        return result;
    }

    // Subtract vectors
    template<size_t Cols>
    Vector<Cols> operator-(const Vector<Cols>& v1,
                           const Vector<Cols>& v2) {
        Vector<Cols> result = v1 + (-v2);
        return result;
    }

    // Divides a vector by a scalar
    template<size_t Cols>
    Vector<Cols> operator/(const Vector<Cols>& v1,
                           Type scalar) {
        Vector<Cols> result = v1;
        for (size_t i = 0; i < v1.size(); ++i) {
            result[i] /= scalar;
        }
        return result;
    }

    // Calculates the magnitude of a vector
    template <size_t Cols>
    float magnitude(const Vector<Cols>& v) {
        float sum = 0.f;
        for (size_t i = 0; i < v.size(); ++i) {
            sum += pow(v[i], 2.f);
        }
        return std::sqrt(sum);
    }

    // Calculates the unit length of a vector
    template <size_t Cols>
    Vector<Cols> unit_length(const Vector<Cols>& v) {
        Vector<Cols> result = v;
        float m = magnitude(v);
        return result / m;
    }
}

#endif // VECTOR_H
