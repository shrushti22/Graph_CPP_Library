#Graph CPP Library

A library to help you built graph data structure.

Library provides you with inbuilt functionalities of graph which will ease down your work of writing every functions from scratch. You can use this library same as the other standard C++ library thus reducing the load of remembering new syntax. 

###Requirements
- cmake
- cpp compiler

###Installation
- Fork and Clone the repository
- Build the library
- Copy the library to your project

###Usage

**Include Library**
```
#include <cpplib.h>
```

**Declaring Graph**
```
// Syntax
Graph<dataType> variable_name(isDirected, isWeighted);

// Examples:
// directed graph with integer datatype
Graph<int> G(true, false);
//directed weighted graph with string datatype
Graph<string> G(true, true);
```

- `dataType`: This can be any valid C++ datatype.
- `isDirected`: This parameter will accept boolean value stating whether graph is directed or undirected. True for directed and false for undirected.
- `isWeighted`: This parameter will accept boolean value stating whether graph is weighted or not. True for weighted and false for unweighted.  


**Add Node into Graph**
```
//Syntax
graph_variable_name.addNode(value);

//Example
Graph<int> G(true, true);
G.addNode(1);
```
- `addNode(D value)`: This function can be used to insert node into graph. It has only one parameter which specifies node value whose datatype should be same as the datatype of the graph declared.

**Add Edge between two Nodes**
```
//Syntax
graph_variable_name.addEdge(src, dest, weight);

//Example
//add edge to directed and weighted graph
Graph<int> G(true, true);
G.addNode(1);
G.addNode(2);
G.addEdge(1, 2, 10);
```

- `addEdge(D src, D dest, int weight)`: This function is used to insert edge into the graph directed from src to destination with the given weight. If the graph is unweighted then weight parameter is not required. 

**Some utility functions**
```

//Example
Graph<int> G(true, true);
G.addNode(1);
G.addNode(2);
G.addEdge(1, 2, 10);

//function to get the number of nodes in the graph or graph size
cout<<G.getSize()<<endl; //output: 2

//function to get the weight of edge in the graph
cout<<G.getWeight(1, 2)<<endl; //output: 10

//function to print the graph
G.printGraph();

//function to check whether the given node is present in the graph or not
if(G.find(1))
    cout<<"Node 1 is present in the graph"<<endl;
else
    cout<<"Node 1 is not present in the graph"<<endl;

//function to check whether the graph is cyclic or not
if(G.isCyclic())
    cout<<"Graph is cyclic"<<endl;
else
    cout<<"Graph is not cyclic"<<endl;

//function to get the topological order of the graph
vector<int> topo = G.topologicalOrder();
for(int i=0; i<topo.size(); i++)
    cout<<topo[i]<<" "<<endl;

//function to find the shortest path between two nodes
int dist = G.shortestPath(1, 2);
cout<<"Shortest path between 1 and 2 is "<<dist<<endl;

//function to find the shortest path from given node to all other nodes
vector<int> dist = G.shortestPath(1);
for(int i=0; i<dist.size(); i++)
    if(dist[i]!=INT_MAX)
        cout<<"Shortest path from 1 to "<<i<<" is "<<dist[i]<<endl;
    else
        cout<<"No path from 1 to "<<i<<endl;

//function to get in-degree of the node
cout<<G.inDegree(1)<<endl;

//function to get out-degree of the node
cout<<G.outDegree(1)<<endl;

//function to get all the nodes in the graph
vector<int> nodes = G.getNodes();
for(int i=0; i<nodes.size(); i++)
    cout<<nodes[i]<<" "<<endl;
```
- `getSize()`: This function returns the number of nodes in the graph.  
- `getWeight(D src, D dest)`: This function returns the weight of the edge between src and dest. If the graph is unweighted then this function will return 1.
- `printGraph()`: This function prints the graph in the console.
- `find(D value)`: This function returns true if the node with the given value is present in the graph and false otherwise.
- `isCyclic()`: This function returns true if the graph is cyclic and false otherwise.
- `topologicalOrder()`: This function returns the topological order of the graph.
- `shortestPath(D src, D dest)`: This function returns the shortest path between src and dest.
- `shortestPath(D src)`: This function returns the shortest path from src to all other nodes.
- `inDegree(D value)`: This function returns the in-degree of the node with the given value.
- `outDegree(D value)`: This function returns the out-degree of the node with the given value.
- `getNodes()`: This function returns all the nodes in the graph.

### Contributions

You can contribute to this project by solving existing issues or adding a new feature.



### Contributors
- <a href="https://github.com/RutvijDv">Rutvij Vamja</a>
- <a href="https://github.com/shrushti22">Shrushti Vasaniya</a>