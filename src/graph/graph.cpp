#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <bits/stdc++.h>
using namespace std;

#include "graph.hpp"

template <typename T>
Graph<T>::Graph(bool isDirected, bool isWeighted)
{
    this->size = 0;
    this->isDirected = isDirected;
    this->isWeighted = isWeighted;
}

template <typename T>
void Graph<T>::addNode(T val)
{
    this->mp[val] = vector<pair<T, int>>();
    this->size++;
}

template <typename T>
void Graph<T>::addEdge(T src, T dest, int weight)
{
    this->mp[src].push_back(make_pair(dest, weight));

    if (!this->isDirected)
        this->mp[dest].push_back(make_pair(src, weight));
}

template <typename T>
void Graph<T>::print()
{
    for (auto it = this->mp.begin(); it != this->mp.end(); it++)
    {
        cout << it->first << ": ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            cout << "(" << it2->first << ", " << it2->second << ") ";
        cout << endl;
    }
}

template <typename T>
int Graph<T>::getSize()
{
    return this->size;
}

#endif
