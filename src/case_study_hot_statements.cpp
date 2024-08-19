#include <benchmark/benchmark.h>

#include <iostream>
#include <cstring>
#include <string>

static void BM_uncache_loop_end_value(benchmark::State& state)
{
    char* input = new char[10000];
    std::memset(input, ' ', 10000);
    for (auto _ : state)
    {
        int count_whitespace = 0;
        for (std::size_t i = 0U; i < strlen(input); i++)
        {
            if (input[i] == ' ')
            {
                count_whitespace++;
            }
        }
        benchmark::DoNotOptimize(count_whitespace);
    }
    delete[] input;
}
BENCHMARK(BM_uncache_loop_end_value);

//////////////////////////////////////////////////////////////////

static void BM_cache_loop_end_value(benchmark::State& state)
{
    char* input = new char[10000];
    std::memset(input, ' ', 10000);
    for (auto _ : state)
    {
        int count_whitespace = 0;
        std::size_t len = strlen(input);
        for (std::size_t i = 0U; i < len; i++)
        {
            if (input[i] == ' ')
            {
                count_whitespace++;
            }
        }
        benchmark::DoNotOptimize(count_whitespace);
    }
    delete[] input;
}
BENCHMARK(BM_cache_loop_end_value);

//////////////////////////////////////////////////////////////////

void replace_whitespaces(char& c)
{
    if (c == ' ')
    {
        c = '_';
    }
}

static void BM_function_call_overheat(benchmark::State& state)
{
    std::string input(10000, ' ');
    for (auto _ : state)
    {
        for (std::size_t i = 0U; i < input.length(); i++)
        {
            replace_whitespaces(input[i]);
        }
    }
}
BENCHMARK(BM_function_call_overheat);

//////////////////////////////////////////////////////////////////

static void BM_reduce_function_call_overheat(benchmark::State& state)
{
    std::string input(10000, ' ');
    for (auto _ : state)
    {
        for (char& c : input)
        {
            if (c == ' ')
            {
                c = '_';
            }
        }
    }
}
BENCHMARK(BM_reduce_function_call_overheat);


BENCHMARK_MAIN();