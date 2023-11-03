#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

int bss;
int data = 4711;
int rodata;

auto main(int argc, char **argv) -> int
{

    fmt::print("Value of variable bss {}address of varaible bss{}\n", bss, fmt::ptr(&bss));
    fmt::print("Value of variable data {}address of varaible data{}\n", data, fmt::ptr(&data));
    fmt::print("Value of variable rodata {}address of varaible rodata{}\n", rodata, fmt::ptr(&rodata));

   
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("\nHello, {}!\n", "Timo");
    return 0; /* exit gracefully*/
}
