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
    unordered_map<T, vector<pair<T, int>>> adjList;
    unordered_map<T, int> bfsShortestPath(T src);
    unordered_map<T, int> djikstras(T src);
    bool cycleDGUtil(T src, unordered_map<T, bool> &visited, unordered_map<T, bool> &recStack);
    bool cycleDG(T src);
    bool cycleUDGUtil(T src, unordered_map<T, bool> &visited, int parent);
    bool cycleUDG(T src);

public:
    Graph(bool isDirected = false, bool isWeighted = false);
    void addNode(T val);
    void addEdge(T src, T dest, int weight = 1);
    int getWeight(T src, T dest);
    void print();
    int getSize();
    bool find(T val);
    int shortestDist(T src, T dest);
    vector<pair<T, int>> shortestDist(T src);
    vector<T> topologicalSort();
    bool isCyclic();
    int inDegree(T val);
    int outDegree(T val);
    vector<T> getAllNodes();
};

#include "graph.cpp"

#endif