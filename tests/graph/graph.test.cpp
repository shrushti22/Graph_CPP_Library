#include <bits/stdc++.h>
using namespace std;

#define CONFIG_CATCH_MAIN

#include <catch.hpp>
#include "cpplib.hpp"

TEST_CASE("Constructing Graph", "[constructors]")
{
    SECTION("Create graph object")
    {
        Graph<int> g;

        REQUIRE(g.getSize() == 0);
    }
    SECTION("Add node to the graph")
    {
        Graph<int> g;
        g.addNode(1);
        g.addNode(2);

        REQUIRE(g.getSize() == 2);
        REQUIRE(g.find(2) == true);
        REQUIRE(g.find(10) == false);
    }

    SECTION("Add edge to the graph")
    {
        Graph<int> g;
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1, 2, 10);

        REQUIRE(g.getSize() == 2);
        REQUIRE(g.getWeight(1, 2) == 10);
    }
}

TEST_CASE("Graph Operations", "[operations]")
{
    SECTION("Print graph")
    {
        Graph<int> g(false, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1, 2, 10);

        g.print();
    }

    SECTION("Get size of the graph")
    {
        Graph<int> g(false, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1, 2, 10);

        REQUIRE(g.getSize() == 2);
    }

    SECTION("Find node in the graph")
    {
        Graph<int> g(false, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1, 2, 10);

        REQUIRE(g.find(1) == true);
        REQUIRE(g.find(10) == false);
    }

    SECTION("Get weight of the edge")
    {
        Graph<int> g(false, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1, 2, 10);

        REQUIRE(g.getWeight(1, 2) == 10);
    }
}

TEST_CASE("Graph Shortest Path Algorithms", "[algorithms]")
{
    SECTION("Shortest path between 2 nodes using bfs")
    {

        Graph<int> g;
        g.addNode(0);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);
        g.addNode(5);
        g.addNode(6);
        g.addNode(7);
        g.addNode(8);

        g.addEdge(0, 1);
        g.addEdge(0, 3);
        g.addEdge(1, 2);
        g.addEdge(3, 4);
        g.addEdge(3, 7);
        g.addEdge(4, 5);
        g.addEdge(4, 6);
        g.addEdge(4, 7);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        int dis = g.shortestDist(0, 7);

        REQUIRE(dis == 2);
    }

    SECTION("Shortest path between 2 nodes using djikstra")
    {
        Graph<int> g(false, true);
        g.addNode(0);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);
        g.addNode(5);
        g.addNode(6);
        g.addNode(7);
        g.addNode(8);

        g.addEdge(0, 1, 1);
        g.addEdge(0, 3, 1);
        g.addEdge(1, 2, 1);
        g.addEdge(3, 4, 1);
        g.addEdge(3, 7, 1);
        g.addEdge(4, 5, 1);
        g.addEdge(4, 6, 1);
        g.addEdge(4, 7, 1);
        g.addEdge(5, 6, 1);
        g.addEdge(6, 7, 1);

        int dis = g.shortestDist(0, 7);

        REQUIRE(dis == 2);
    }
}

TEST_CASE("Topological sort", "[sort]")
{
    SECTION("Topological sort")
    {
        Graph<int> g(true, false);
        g.addNode(0);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);
        g.addNode(5);
        g.addNode(6);
        g.addNode(7);

        g.addEdge(0, 1);
        g.addEdge(0, 3);
        g.addEdge(1, 2);
        g.addEdge(3, 4);
        g.addEdge(3, 7);
        g.addEdge(4, 5);
        g.addEdge(4, 6);
        g.addEdge(4, 7);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        vector<int> topo = g.topologicalSort();

        REQUIRE(topo[0] == 0);
        REQUIRE(topo[1] == 1);
        REQUIRE(topo[2] == 3);
        REQUIRE(topo[3] == 2);
        REQUIRE(topo[4] == 4);
        REQUIRE(topo[5] == 5);
        REQUIRE(topo[6] == 6);
        REQUIRE(topo[7] == 7);
    }
}

TEST_CASE("Cycle detection", "[cycle]")
{
    SECTION("Undirected graph")
    {
        Graph<int> g;
        g.addNode(0);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);
        g.addNode(5);
        g.addNode(6);
        g.addNode(7);

        g.addEdge(0, 1);
        g.addEdge(0, 3);
        g.addEdge(1, 2);
        g.addEdge(3, 4);
        g.addEdge(3, 7);
        g.addEdge(4, 5);
        g.addEdge(4, 6);
        g.addEdge(4, 7);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        REQUIRE(g.isCyclic() == true);
    }

    SECTION("Directed graph")
    {
        Graph<int> g(true, false);
        g.addNode(0);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);
        g.addNode(5);
        g.addNode(6);
        g.addNode(7);

        g.addEdge(0, 1);
        g.addEdge(0, 3);
        g.addEdge(1, 2);
        g.addEdge(3, 4);
        g.addEdge(3, 7);
        g.addEdge(4, 5);
        g.addEdge(4, 6);
        g.addEdge(4, 7);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        REQUIRE(g.isCyclic() == false);
    }
}

TEST_CASE("Degree of nodes", "[degree]")
{
    SECTION("Indegree and outdegree of directed graph")
    {
        Graph<int> g(true, false);
        g.addNode(0);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);
        g.addNode(5);
        g.addNode(6);
        g.addNode(7);
        g.addNode(8);

        g.addEdge(0, 1);
        g.addEdge(0, 3);
        g.addEdge(1, 2);
        g.addEdge(3, 4);
        g.addEdge(3, 7);
        g.addEdge(4, 5);
        g.addEdge(4, 6);
        g.addEdge(4, 7);
        g.addEdge(5, 6);
        g.addEdge(6, 7);

        REQUIRE(g.inDegree(0) == 0);
        REQUIRE(g.inDegree(1) == 1);
        REQUIRE(g.inDegree(2) == 1);
        REQUIRE(g.inDegree(3) == 1);
        REQUIRE(g.inDegree(4) == 1);
        REQUIRE(g.inDegree(5) == 1);
        REQUIRE(g.inDegree(6) == 2);
        REQUIRE(g.inDegree(7) == 3);
        REQUIRE(g.inDegree(8) == 0);

        REQUIRE(g.outDegree(0) == 2);
        REQUIRE(g.outDegree(1) == 1);
        REQUIRE(g.outDegree(2) == 0);
        REQUIRE(g.outDegree(3) == 2);
        REQUIRE(g.outDegree(4) == 3);
        REQUIRE(g.outDegree(5) == 1);
        REQUIRE(g.outDegree(6) == 1);
        REQUIRE(g.outDegree(7) == 0);
        REQUIRE(g.outDegree(8) == 0);
    }
}