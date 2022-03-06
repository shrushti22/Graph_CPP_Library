#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
    int size;
    bool isDirected;
    bool isWeighted;
    unordered_map<T, vector<pair<T, int>>> mp;

public:
    Graph(bool isDirected = false, bool isWeighted = false);
    void addNode(T val);
    void addEdge(T src, T dest, int weight = 1);
    void print();
    int getSize();
};

#endif