#include <benchmark/benchmark.h>
#include <string>

std::string trim_whitespace_naive(std::string s)
{
    std::string res;
    for (std::size_t i = 0U; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            res = res + s[i];
        }
    }

    return res;
}

static void BM_trim_whitespace_naive(benchmark::State& state)
{
    std::string input = "this is a string";
    for (auto _ : state)
    {
        std::string res = trim_whitespace_naive(input);
    }
}
BENCHMARK(BM_trim_whitespace_naive);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_eliminate_temporaries(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_eliminate_temporaries);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_reserve_storage(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_reserve_storage);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_eliminate_copying_args(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_eliminate_copying_args);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_iterators(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_iterators);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_eliminate_copying_returned(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_eliminate_copying_returned);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_c_strings(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_c_strings);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_improved_algorithm(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_improved_algorithm);

/////////////////////////////////////////////////////////////////////////////////

static void BM_trim_whitespace_improved_allocator(benchmark::State& state)
{
    for (auto _ : state)
    {

    }
}
BENCHMARK(BM_trim_whitespace_improved_allocator);


BENCHMARK_MAIN();