#ifndef LINEAR_H
#define LINEAR_H

#include "vector.h"
#include "matrix.h"

namespace Mgt {
    template<size_t Cols>
    Vector<Cols> operator*(const Matrix<Cols>& matrix,
                           const Vector<Cols>& vector) {
        Vector<Cols> result = {};
        for (size_t i = 0; i < Cols; i++) {
            for (size_t j = 0; j < Cols; j++) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }
}

#endif // LINEAR_H
