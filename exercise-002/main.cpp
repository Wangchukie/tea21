#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"


auto main(int argc, char **argv) -> int
{
    int count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-C,--count", 
                        count,
                        fmt::format("count = {}",count))->default_val(20);
        app.parse(argc, argv);


    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    std::vector<int> data(count);

    std::srand(std::time(nullptr));

    for (int i = 0; i < count; ++i) {
        data[i] = std::rand() %101;
    }
    /**
    for (auto& i : data){
        i = distrib(gen);
    }
    
    */
    auto start = std::chrono::system_clock::now();
    std::sort(data.begin(),data.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed =(end - start);    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    
    fmt::print("Created a Vector with count = {}\n",count);
    fmt::print("Created a Vector with data = {}\n",fmt::join(data,", "));
    fmt::print("Duration: {}", elapsed);

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
