cmake_minimum_required(VERSION 3.10)
project(CppOptimization)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# https://github.com/google/benchmark
find_package(benchmark REQUIRED)
find_package(Threads)

function(compile_executables target_name file_path)
    add_executable(${target_name} ${file_path})
    target_link_libraries(${target_name}
        PRIVATE
            benchmark::benchmark
            Threads::Threads
    )
endfunction()

compile_executables(benchmark_setup_test ${CMAKE_CURRENT_SOURCE_DIR}/src/benchmark_setup_test.cpp)