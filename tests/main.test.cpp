#define CATCH_CONFIG_RUNNER // Configure catch to use main

#include "catch.hpp"

using namespace std;
int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);

    return result;
}