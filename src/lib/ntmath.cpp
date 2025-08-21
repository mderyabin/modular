#include "ntmath.h"


namespace modular {

size_t MSB(uint64_t t) {
    size_t msb = 0;
    while (t > 0) {
        msb++;
        t >>= 1;
    }
    return msb;
}

uint64_t barrett_precompute(uint64_t q, size_t logq) {
    return static_cast<uint64_t>((static_cast<uint128_t>(1) << (2*logq)) / q);
}

uint64_t mod_mul_barrett(uint64_t a, uint64_t b, uint64_t q, uint64_t prec, size_t logq) {
    uint128_t mul = static_cast<uint128_t>(a) * static_cast<uint128_t>(b);

    uint128_t tmp1 = mul;
    uint128_t tmp2 = tmp1 >> (logq - 2);

    tmp1 = tmp2 * prec;
    tmp2 = tmp1 >> (logq + 2);
    tmp1 = tmp2 * q;

    uint64_t res = static_cast<uint64_t>(mul - tmp1);

    if (res >= q) res -= q;
    // if (res >= q) res -= q;

    return res;
}

uint64_t shoup_precompute(uint64_t c, uint64_t q) {
    uint128_t w = static_cast<uint128_t>(c);
    w <<= 64;
    w /= q;
    return static_cast<uint64_t>(w);
}

uint64_t mod_mul_shoup(uint64_t a, uint64_t c, uint64_t q, uint64_t prec) {
    uint64_t res;
   
    uint128_t aa  = static_cast<uint128_t>(a);
    uint64_t mul = a * c;
    uint64_t tmp = static_cast<uint64_t>((aa * prec) >> 64) * q;

    res = mul - tmp;  // mod 2^64

    if (res >= q) res -= q;

    return res;
}



} // namespace modular