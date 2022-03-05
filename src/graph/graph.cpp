#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <bits/stdc++.h>
using namespace std;

#include "graph.hpp"

Graph::Graph(bool isDirected = false, bool isWeighted = false)
{
    this->size = 0;
    this->isDirected = isDirected;
    this->isWeighted = isWeighted;
}

void Graph::addNode(int val)
{
    this->mp[val] = vector<pair<int, int>>();
    this->size++;
}

void Graph::addEdge(int src, int dest, int weight = 1)
{
    this->mp[src].push_back(make_pair(dest, weight));

    if (!this->isDirected)
        this->mp[dest].push_back(make_pair(src, weight));
}

void Graph::print()
{
    for (auto it = this->mp.begin(); it != this->mp.end(); it++)
    {
        cout << it->first << ": ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            cout << "(" << it2->first << ", " << it2->second << ") ";
        cout << endl;
    }
}

#endif
