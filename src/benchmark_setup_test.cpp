#include <benchmark/benchmark.h>

#include <iostream>
#include <set>
#include <unordered_set>

std::unordered_set<int> S;

static void DoSetUp(const benchmark::State& state)
{
    for (auto i = 0; i < state.range(0); i++)
    {
        S.insert(state.range(i + 1));
    }
}

static void DoTearDown(const benchmark::State& state)
{
    S.clear();
}

static void BM_test(benchmark::State& state)
{
    for (auto _ : state)
    {
        S.find(5);
    }
    state.SetBytesProcessed(S.size() * state.iterations());
}

BENCHMARK(BM_test)->Setup(DoSetUp)->Teardown(DoTearDown)->Args({5, 1, 2, 3, 4, 5})->Args({10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

BENCHMARK_MAIN();