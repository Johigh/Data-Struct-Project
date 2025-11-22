#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>

#include "GraphBase.hpp"
#include "MinPriorityQueue.hpp"

// Simple graph class that uses an adjacency list
class Graph : public GraphBase {
public:
    Graph();
    ~Graph();

    void addVertex(std::string label) override;
    void removeVertex(std::string label) override;

    void addEdge(std::string label1,
                 std::string label2,
                 unsigned long weight) override;

    void removeEdge(std::string label1,
                    std::string label2) override;

    unsigned long shortestPath(std::string startLabel,
                               std::string endLabel,
                               std::vector<std::string> &path) override;

private:
    struct Edge {
        std::string to;
        unsigned long weight;
    };

    struct Vertex {
        std::string label;
        std::vector<Edge> neighbors;
    };

    // Map from label to vertex
    std::unordered_map<std::string, Vertex> vertices;
};

#endif
