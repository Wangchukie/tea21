#include <fmt/chrono.h>
#include <fmt/format.h>
#include <thread>

#include "CLI/CLI.hpp"
#include "config.h"

int get_Input(void)
{
    std::cout << std::endl << "1 for Button input/else for waiting: ";
    int user_input;
    std::cin >> user_input;
    return user_input;
};

void sleep_ms( int ms)
{
std::this_thread::sleep_for(std::chrono::milliseconds(ms));
};


typedef enum {
    STATE_UPWARDS = 0,
    STATE_UP = 1,
    STATE_DOWNWARDS = 2,
    STATE_DOWN
} states;

states state = STATE_UPWARDS;

void stateMaschine ();

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    while(true)
    {
        stateMaschine();
        sleep_ms(100);
    }

    return 0; /* exit gracefully*/
}

void stateMaschine()
{
    switch(state)
    {
        case STATE_UPWARDS:
        printf("UPWARDS");
        if(1 == get_Input())
        {
            state = STATE_DOWNWARDS;
        }
        else
        {
            state = STATE_UP;
        }
        break;
        /////////////////////////////
        case STATE_UP:
        printf("UP");
        if(1 == get_Input())
        {
            state = STATE_DOWNWARDS;
        }
        else
        {
            state = STATE_UP;
        }
        break;
        ////////////////////////////
        case STATE_DOWNWARDS:
        printf("DOWNWARDS");
        if(1 == get_Input())
        {
            state = STATE_UPWARDS;
        }
        else
        {
            state = STATE_DOWN;
        }
        break;
        ////////////////////////////
        case STATE_DOWN:
        printf("DOWN");
        if(1 == get_Input())
        {
            state = STATE_UPWARDS;
        }
        else
        {
            state = STATE_DOWN;
        }
        break;
    }
};