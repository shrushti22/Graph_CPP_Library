#include <bits/stdc++.h>
using namespace std;

#define CONFIG_CATCH_MAIN

#include <catch.hpp>
#include "cpplib.hpp"

TEST_CASE("Constructing Graph", "[constructors]")
{
    SECTION("Graph construction 1")
    {
        Graph<int> g;

        REQUIRE(g.getSize() == 0);
    }
    SECTION("Graph Construction 2")
    {
        Graph<int> g;
        g.addNode(1);
        g.addNode(2);

        REQUIRE(g.getSize() == 2);
    }
}
