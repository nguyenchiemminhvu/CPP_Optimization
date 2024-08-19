#include <benchmark/benchmark.h>

#include <iostream>
#include <set>
#include <unordered_set>

static void BM_test_set(benchmark::State& state)
{
    std::set<int> S;
    for (int i = 0; i < 10; i++)
    {
        S.insert(i);
    }

    for (auto _ : state)
    {
        S.find(state.range(0));
    }
    state.SetBytesProcessed(S.size() * state.iterations());
}

static void BM_test_unordered_set(benchmark::State& state)
{
    std::unordered_set<int> S;
    for (int i = 0; i < 10; i++)
    {
        S.insert(i);
    }

    for (auto _ : state)
    {
        S.find(state.range(0));
    }
    state.SetBytesProcessed(S.size() * state.iterations());
}

BENCHMARK(BM_test_set)->Arg(5)->Arg(7);
BENCHMARK(BM_test_unordered_set)->Arg(5)->Arg(7);

BENCHMARK_MAIN();