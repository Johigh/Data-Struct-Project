# Data-Struct-Project
## COP 4530 Final Project: Dijkstra’s Algorithm
John Bachta U#: 59139954  
Danae Ferguson U#: 33752946  
John Hightower U#: 05320833  
Elena Roussanova U#: 38647367  

### Overview
This project implements a simple graph library in C++ that computes shortest paths using Dijkstra’s algorithm.
The graph is undirected and weighted, and each vertex is identified by a string label (for example "1"–"6" in the sample graph).

The code is designed to work with a GraphBase interface provided by the course.
The main deliverable is a Graph class and its shortestPath method, which finds the minimum-distance path between two vertices.

### Features
Graph represented using an adjacency list
Support for:
- Adding/removing vertices
- Adding/removing undirected weighted edges
- Custom min-heap priority queue (no std::priority_queue)
Implementation of Dijkstra’s algorithm:
- Returns the shortest distance between two labels
- Fills a vector with the actual path (sequence of labels)

### File Structure

#### Code Files
GraphBase.hpp – Interface provided by the instructor
Graph.hpp / Graph.cpp – Implementation of the Graph class (including Dijkstra's shortestPath algorithm)
MinPriorityQueue.hpp / MinPriorityQueue.cpp – Simple min-heap priority queue used by Dijkstra
main.cpp – Test driver that builds a sample graph and calls shortestPath
README.md – This file

#### Additional Files
COPFinal_Project.pdf – Project report
Dijkstra’s Algorithm.pdf – Slides for the project presentation
