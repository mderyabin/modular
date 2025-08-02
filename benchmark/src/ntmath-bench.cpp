#include "benchmark/benchmark.h"

#include "ntmath.h"
#include "utils.h"

using namespace modular;

void BC_ModAddNaive(benchmark::State& state) {
    uint64_t q = generate_number(1ULL<<63);

    uint64_t a = generate_number(q);

    uint64_t b = generate_number(q);

    uint64_t c;


    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(a);
        benchmark::DoNotOptimize(b);

        c = (a+b) % q;

        benchmark::DoNotOptimize(c);
    }
}

void BC_ModAdd(benchmark::State& state) {
    uint64_t q = generate_number(1ULL<<62);

    uint64_t a = generate_number(q);

    uint64_t b = generate_number(q);

    uint64_t c;


    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(a);
        benchmark::DoNotOptimize(b);
        
        c = mod_add(a, b, q);

        benchmark::DoNotOptimize(c);
    }
}

void BC_ModSubNaive(benchmark::State& state) {
    uint64_t q = generate_number(1ULL<<62);

    uint64_t a = generate_number(q);

    uint64_t b = generate_number(q);

    uint64_t c;


    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(a);
        benchmark::DoNotOptimize(b);

        c = (a-b) % q;

        benchmark::DoNotOptimize(c);
    }
}

void BC_ModSub(benchmark::State& state) {
    uint64_t q = generate_number(1ULL<<62);

    uint64_t a = generate_number(q);

    uint64_t b = generate_number(q);

    uint64_t c;


    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(a);
        benchmark::DoNotOptimize(b);

        c = mod_sub(a, b, q);

        benchmark::DoNotOptimize(c);
    }
}

BENCHMARK(BC_ModAddNaive)->Unit(benchmark::kNanosecond)->Repetitions(30)->ReportAggregatesOnly(true);
BENCHMARK(BC_ModAdd)->Unit(benchmark::kNanosecond)->Repetitions(30)->ReportAggregatesOnly(true);
BENCHMARK(BC_ModSubNaive)->Unit(benchmark::kNanosecond)->Repetitions(30)->ReportAggregatesOnly(true);
BENCHMARK(BC_ModSub)->Unit(benchmark::kNanosecond)->Repetitions(30)->ReportAggregatesOnly(true);

BENCHMARK_MAIN();