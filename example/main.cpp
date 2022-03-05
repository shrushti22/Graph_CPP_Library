#include <bits/stdc++.h>
using namespace std;

#include "cpplib.hpp"

int main()
{

    Graph g(true, true);

    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);
    g.addNode(5);
    g.addNode(6);
    g.addNode(7);
    g.addNode(8);
    g.addNode(9);
    g.addNode(10);

    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(2, 6, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(3, 8, 1);
    g.addEdge(4, 9, 1);
    g.addEdge(4, 10, 1);
    g.addEdge(5, 10, 1);
    g.addEdge(6, 10, 1);
    g.addEdge(7, 10, 1);
    g.addEdge(8, 10, 1);
    g.addEdge(9, 10, 1);

    g.print();

    return 0;
}