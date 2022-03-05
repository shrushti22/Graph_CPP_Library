#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int size;
    bool isDirected;
    bool isWeighted;
    unordered_map<int, vector<pair<int, int>>> mp;

public:
    Graph(bool isDirected, bool isWeighted);
    void addNode(int val);
    void addEdge(int src, int dest, int weight);
    void print();
};

#endif