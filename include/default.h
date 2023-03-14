#ifndef DEFAULT_H
#define DEFAULT_H

#include <numeric>

namespace Mgt {
    using Type = float;

    bool isEqual(Type a,
                 Type b,
                 Type e = std::numeric_limits<Type>::epsilon()) {
        return std::abs(a - b) < e;
    }
}

#endif // DEFAULT_H
