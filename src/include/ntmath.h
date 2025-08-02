#ifndef __NTMATH_H__
#define __NTMATH_H__

#include <cstdlib>

namespace modular {

// c = a+b mod q
inline uint64_t mod_add(uint64_t a, uint64_t b, uint64_t q) {
    // uint64_t d = a + b;
    // return (d < q) ? d : d - q;
    return (a + b < q) ? a + b : a + b - q;
}

// c = a-b mod q
inline uint64_t mod_sub(uint64_t a, uint64_t b, uint64_t q) {
    // uint64_t d = a - b;
    // return (a > b) ? d : q + d;
    return (a > b) ? a - b : q + a - b;
}

} 

#endif /* __NTMATH_H__ */