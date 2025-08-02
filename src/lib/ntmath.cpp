#include "ntmath.h"


namespace modular {

// c = a+b mod q
uint64_t mod_add(uint64_t a, uint64_t b, uint64_t q) {
    uint64_t d = a + b;
    return (d < q) ? d : d - q;
}

// c = a-b mod q
uint64_t mod_sub(uint64_t a, uint64_t b, uint64_t q) {
    uint64_t d = a - b;
    return (a > b) ? d : q + d;
}

} // namespace modular