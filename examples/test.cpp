#include <iostream>
#include <iomanip>
#include "ntmath.h"
#include "utils.h"

using namespace std;
using namespace modular;

bool is_arrays_equal(uint64_t *ax, uint64_t *bx, size_t N) {
    for (size_t i = 0; i < N; i++) {
        if (ax[i] != bx[i]) return false;
    }
    return true;
}

int main(/*int argc, char const *argv[]*/) {
    
    uint64_t q = generate_number(1ULL<<60);
    size_t N = 10;
    
    uint64_t ax[N];
    uint64_t bx[N];
    uint64_t cx[N];
    uint64_t cx_gold[N];

    random_uniform_vector_mod_q(ax, N, q);
    random_uniform_vector_mod_q(bx, N, q);


    /* testing add */
    for (size_t i = 0; i < N; i++) {
        cx[i] = mod_add(ax[i], bx[i], q);
        cx_gold[i] = (ax[i] + bx[i]) % q;
    }

    cout << setw(25) << "Test mod_add: ";
    if (is_arrays_equal(cx, cx_gold, N)) {
        cout << "passed";
    } else {
        cout << "failed";
    }
    cout << endl;

    /* testing sub */
    for (size_t i = 0; i < N; i++) {
        cx[i] = mod_sub(ax[i], bx[i], q);
        cx_gold[i] = (q + ax[i] - bx[i]) % q;
    }

    cout << setw(25) << "Test mod_sub: ";
    if (is_arrays_equal(cx, cx_gold, N)) {
        cout << "passed";
    } else {
        cout << "failed";
    }
    cout << endl;

    /* testing barrett */
    size_t logq = MSB(q);
    uint64_t prec = barrett_precompute(q, logq);

    for (size_t i = 0; i < N; i++) {
        cx[i] = mod_mul_barrett(ax[i], bx[i], q, prec, logq);
        cx_gold[i] = static_cast<uint64_t>(static_cast<uint128_t>(ax[i]) * static_cast<uint128_t>(bx[i]) % static_cast<uint128_t>(q));    
    }

    cout << setw(25) << "Test mod_mul_barrett: ";
    if (is_arrays_equal(cx, cx_gold, N)) {
        cout << "passed";
    } else {
        cout << "failed";
    }
    cout << endl;
    
    /* testing shoup */
    for (size_t i = 0; i < N; i++) {
        uint64_t b_prec = shoup_precompute(bx[i], q);

        cx[i] = mod_mul_shoup(ax[i], bx[i], q, b_prec);
        cx_gold[i] = static_cast<uint64_t>(static_cast<uint128_t>(ax[i]) * static_cast<uint128_t>(bx[i]) % static_cast<uint128_t>(q));
    }

    cout << setw(25) << "Test mod_mul_shoup: ";
    if (is_arrays_equal(cx, cx_gold, N)) {
        cout << "passed";
    } else {
        cout << "failed";
    }
    cout << endl;
   
    return 0;
}
