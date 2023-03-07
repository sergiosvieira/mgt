#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <ostream>
#include "default.h"

namespace Mgt {
    template <std::size_t Cols, std::size_t Rows = Cols>
    using Matrix = std::array<std::array<Type, Cols>, Rows>;

    template <std::size_t Cols, std::size_t Rows = Cols>
    std::ostream& operator<<(std::ostream& os,
                             const Matrix<Cols, Rows>& matrix) {
        for (std::size_t i = 0; i < Rows; ++i) {
            for (std::size_t j = 0; j < Cols; ++j) {
                os << matrix[i][j];
                if (j < Cols - 1) os << ' ';
            }
            os << '\n';
        }
        return os;
    }

    // Creates a identity matrix
    template<size_t Cols>
    Matrix<Cols> identity() {
        Matrix<Cols> result;
        for (size_t i = 0; i < Cols; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                if (i == j) result[i][j] = 1.f;
                else result[i][j] = 0.f;
            }
        }
        return result;
    }

    template<size_t Cols, size_t Rows = Cols>
    Matrix<Rows, Cols> transpose(const Matrix<Cols, Rows>& m) {
        Matrix<Rows, Cols> result = {};
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result[j][i] = m[i][j];
            }
        }
        return result;
    }

    template <size_t Cols, size_t Rows = Cols>
    Matrix<Cols, Rows> operator+(const Matrix<Cols, Rows>& m,
                                 const Matrix<Cols, Rows>& n) {
        Matrix<Cols, Rows> result = m;
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result[i][j] += n[i][j];
            }
        }
        return result;
    }

    template <size_t Cols, size_t Rows = Cols>
    Matrix<Cols, Rows> operator-(const Matrix<Cols, Rows>& m,
                                 const Matrix<Cols, Rows>& n) {
        Matrix<Cols, Rows> result = m;
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result[i][j] -= n[i][j];
            }
        }
        return result;
    }
}


#endif // MATRIX_H
