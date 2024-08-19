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

std::string trim_whitespace_eliminate_temporaries(std::string s)
{
    std::string res;
    for (std::size_t i = 0U; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            res += s[i];
        }
    }

    return res;
}

static void BM_trim_whitespace_eliminate_temporaries(benchmark::State& state)
{
    std::string input = "this is a string";
    for (auto _ : state)
    {
        std::string res = trim_whitespace_eliminate_temporaries(input);
    }
}
BENCHMARK(BM_trim_whitespace_eliminate_temporaries);

/////////////////////////////////////////////////////////////////////////////////

std::string trim_whitespace_iterators(std::string s)
{
    std::string res;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it != ' ')
        {
            res += *it;
        }
    }

    return res;
}

static void BM_trim_whitespace_iterators(benchmark::State& state)
{
    std::string input = "this is a string";
    for (auto _ : state)
    {
        std::string res = trim_whitespace_iterators(input);
    }
}
BENCHMARK(BM_trim_whitespace_iterators);

/////////////////////////////////////////////////////////////////////////////////

std::string trim_whitespace_eliminate_copying_args(const std::string& s)
{
    std::string res;
    for (std::size_t i = 0U; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            res += s[i];
        }
    }

    return res;
}

static void BM_trim_whitespace_eliminate_copying_args(benchmark::State& state)
{
    std::string input = "this is a string";
    for (auto _ : state)
    {
        std::string res = trim_whitespace_eliminate_copying_args(input);
    }
}
BENCHMARK(BM_trim_whitespace_eliminate_copying_args);

/////////////////////////////////////////////////////////////////////////////////

void trim_whitespace_eliminate_copying_returned(const std::string& s, std::string& res)
{
    res.clear();
    for (std::size_t i = 0U; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            res += s[i];
        }
    }
}

static void BM_trim_whitespace_eliminate_copying_returned(benchmark::State& state)
{
    std::string input = "this is a string";
    std::string res;
    for (auto _ : state)
    {
        trim_whitespace_eliminate_copying_returned(input, res);
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