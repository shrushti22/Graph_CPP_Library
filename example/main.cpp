#include <bits/stdc++.h>
using namespace std;

#include "cpplib.hpp"

int main()
{

    Graph<int> g(true, true);
    cout << "HELLO" << endl;

    g.addNode(1);
    cout << g.getSize() << endl;

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

    cout << g.shortestDist(1, 10) << endl;

    vector<pair<int, int>> v = g.shortestDist(1);
    for (auto it = v.begin(); it != v.end(); it++)
        cout << it->first << " " << it->second << endl;

    vector<int> v2 = g.topologicalSort();
    for (auto it = v2.begin(); it != v2.end(); it++)
        cout << *it << " ";

    cout << endl;

    cout << g.inDegree(10) << endl;
    cout << g.outDegree(10) << endl;

    vector<int> v3 = g.getAllNodes();
    for (auto it = v3.begin(); it != v3.end(); it++)
        cout << *it << " ";

    cout << endl;

    cout << g.isCyclic() << endl;

    return 0;
}