Euler path of an undirected (or directed) graph is a path that traverses all edges in the graph, exactly once. An Euler tour is an Euler path which starts and ends at the same vertex. A graph is said to be simple if it has no self-loops at any vertex and it does not have more than one edge between two vertices as shown in the image below. An Euler tour exists in an undirected, simple graph if and only if:

- The graph is connected, and
- Each vertex has an even degree. (That is, each vertex has even number of edges incident on it.)

![alt text](https://github.com/namangupta98/EulerTour/blob/main/EulerianCycleOctahedron_1000.gif)

# Overview

Let G = (V, E) be an undirected, connected, simple graph.  The goal of this project is to find if an Euler tour(not Euler path) exists for given undirected, connected, simple graphs, and to print such a tour, if they do indeed have one.

## Dependencies

- GCC Compiler
```
sudo apt install gcc
```

## Install Instructions
Open terminal and clone the repository
```
git clone https://github.com/namangupta98/EulerTour.git
```

## Run Instructions

```
gcc main.c -o main -std=c99
./main input/in1.txt
```
## Output

- A.txt has the printed Euler Tour if one exists.
- B.txt (Only when no Euler Tour exists) has the number of C operations taken by the a graph for each vertex and each edge.
- C.txt has the total number of C operations taken by the a graph for vertex and edge.
