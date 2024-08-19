#include <benchmark/benchmark.h>
#include <string>

static void BM_remove_ctrl_naive(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}

BENCHMARK(BM_remove_ctrl_naive);

BENCHMARK_MAIN();