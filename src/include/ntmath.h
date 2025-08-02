#ifndef __NTMATH_H__
#define __NTMATH_H__

#include <cstdlib>

namespace modular {

uint64_t mod_add(uint64_t a, uint64_t b, uint64_t q);
uint64_t mod_sub(uint64_t a, uint64_t b, uint64_t q);

} 

#endif /* __NTMATH_H__ */