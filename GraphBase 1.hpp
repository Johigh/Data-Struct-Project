#ifndef GRAPHBASE_H
#define GRAPHBASE_H

#include <string>
#include <vector>

class GraphBase {
public:
    virtual ~GraphBase() {}

    // Add a vertex with this label to the graph
    virtual void addVertex(std::string label) = 0;

    // Remove the vertex and any edges that touch it
    virtual void removeVertex(std::string label) = 0;

    // Add an undirected edge between label1 and label2
    virtual void addEdge(std::string label1,
                         std::string label2,
                         unsigned long weight) = 0;

    // Remove the edge between label1 and label2
    virtual void removeEdge(std::string label1,
                            std::string label2) = 0;

    // Dijkstra: fill vector with path and return total distance
    virtual unsigned long shortestPath(std::string startLabel,
                                       std::string endLabel,
                                       std::vector<std::string> &path) = 0;
};

#endif
