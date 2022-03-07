#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <bits/stdc++.h>
using namespace std;

#include "graph.hpp"

template <typename T>
unordered_map<T, int> Graph<T>::bfsShortestPath(T src){
    unordered_map<T, int> dist;
    unordered_map<T, bool> visited;
    queue<T> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        T u = q.front();
        q.pop();
        for(auto v : this->adjList[u]){
            if(!visited[v.first]){
                visited[v.first] = true;
                dist[v.first] = dist[u] + v.second;
                q.push(v.first);
            }
        }
    }
    return dist;
}

template <typename T>
unordered_map<T, int> Graph<T>::djikstras(T src){
    unordered_map<T, int> dist;
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;

    for(auto node : this->adjList){
        dist[node.first] = INT_MAX;
    }

    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        pair<int, T> u = pq.top();
        pq.pop();
        for(auto v : this->adjList[u.second]){
            if(dist[u.second] + v.second < dist[v.first]){
                dist[v.first] = dist[u.second] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    return dist;
}

template <typename T>
bool Graph<T>::cycleDGUtil(T src, unordered_map<T, bool> &visited, unordered_map<T, bool> &recStack){
    visited[src] = true;
    recStack[src] = true;
    for(auto v : this->adjList[src]){
        if(!visited[v.first] && cycleDGUtil(v.first, visited, recStack)){
            return true;
        }
        else if(recStack[v.first]){
            return true;
        }
    }
    recStack[src] = false;
    return false;
}

template <typename T>
bool Graph<T>::cycleDG(T src){
    unordered_map<T, bool> visited;
    unordered_map<T, bool> recStack;
    for(auto node : this->adjList){
        visited[node.first] = false;
        recStack[node.first] = false;
    }
    
    for(auto node : this->adjList){
        if(!visited[node.first]){
            if(cycleDGUtil(node.first, visited, recStack)){
                return true;
            }
        }
    }
    return false;
}

template <typename T>
bool Graph<T>::cycleUDGUtil(T src, unordered_map<T, bool> &visited, int parent){
    visited[src] = true;
    for(auto v : this->adjList[src]){
        if(!visited[v.first]){
            if(cycleUDGUtil(v.first, visited, src)){
                return true;
            }
        }
        else if(v.first != parent){
            return true;
        }
    }
    return false;
}

template <typename T>
bool Graph<T>::cycleUDG(T src){
    unordered_map<T, bool> visited;
    for(auto node : this->adjList){
        visited[node.first] = false;
    }
    
    for(auto node : this->adjList){
        if(!visited[node.first]){
            if(cycleUDGUtil(node.first, visited, -1)){
                return true;
            }
        }
    }
    return false;
}

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
    this->adjList[val] = vector<pair<T, int>>();
    this->size++;
}

template <typename T>
void Graph<T>::addEdge(T src, T dest, int weight)
{
    this->adjList[src].push_back(make_pair(dest, weight));

    if (!this->isDirected)
        this->adjList[dest].push_back(make_pair(src, weight));
}

template <typename T>
void Graph<T>::print()
{
    for (auto it = this->adjList.begin(); it != this->adjList.end(); it++)
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

template <typename T>
bool Graph<T>::find(T val)
{
    return this->adjList.find(val) != this->adjList.end();
}

template <typename T>
int Graph<T>::shortestDist(T src, T dest)
{
    if(!this->find(src) || !this->find(dest))
        return -1;

    

    if(this->isWeighted){
        return this->djikstras(src)[dest];
    }
    else{
        return this->bfsShortestPath(src)[dest];
    }
}

template <typename T>
vector<pair<T, int>> Graph<T>::shortestDist(T src)
{
    if(this->adjList.find(src) == this->adjList.end()){
        vector<pair<T, int>> dist(this->size);

        for(auto node : this->adjList){
            dist.push_back(make_pair(node.first, INT_MAX));
        }

        return dist;
    }
    if(this->isWeighted){
        unordered_map<T, int> dist = this->djikstras(src);

        for(auto node : this->adjList){
            if(dist[node.first] == INT_MAX){
                dist[node.first] = -1;
            }
        }

        return vector<pair<T, int>>(dist.begin(), dist.end());
    }
    else{
        unordered_map<T, int> dist = this->bfsShortestPath(src);

        for(auto node : this->adjList){
            if(dist[node.first] == INT_MAX){
                dist[node.first] = -1;
            }
        }

        return vector<pair<T, int>>(dist.begin(), dist.end());
    }
}



template <typename T>
vector<T> Graph<T>::topologicalSort()
{
    unordered_map<T, int> indegree;
    for(auto it = this->adjList.begin(); it != this->adjList.end(); it++){
        indegree[it->first] = 0;
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
            indegree[it2->first]++;
        }
    }
    
    queue<T> q;
    for(auto it = indegree.begin(); it != indegree.end(); it++){
        if(it->second == 0)
            q.push(it->first);
    }
    
    vector<T> res;
    while(!q.empty()){
        T u = q.front();
        q.pop();
        res.push_back(u);
        for(auto it = this->adjList[u].begin(); it != this->adjList[u].end(); it++){
            indegree[it->first]--;
            if(indegree[it->first] == 0)
                q.push(it->first);
        }
    }
    
    if(res.size() != this->size)
        return vector<T>();
    
    return res;
}

template <typename T>
bool Graph<T>::isCyclic()
{
    if(this->isDirected){
        return this->cycleDG(this->adjList.begin()->first);
    }
    else{
        return this->cycleUDG(this->adjList.begin()->first);
    }
}

template <typename T>
int Graph<T>::inDegree(T val)
{
    if(this->adjList.find(val) == this->adjList.end())
        return -1;
    
    int count = 0;
    for(auto it = this->adjList.begin(); it != this->adjList.end(); it++){
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
            if(it2->first == val)
                count++;
        }
    }
    return count;
}

template <typename T>
int Graph<T>::outDegree(T val)
{
    if(this->adjList.find(val) == this->adjList.end())
        return -1;
    
    return this->adjList[val].size();
}

template <typename T>
vector<T> Graph<T>::getAllNodes()
{
    vector<T> res;
    for(auto it = this->adjList.begin(); it != this->adjList.end(); it++){
        res.push_back(it->first);
    }
    return res;
}

#endif
