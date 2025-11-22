#include <iostream>
#include <vector>
#include <tuple>
#include <string>

#include "Graph.hpp"

//test the Graph and Dijkstra code
int main() {
    Graph g;

    //add vertices 1 to 6 (as strings)
    std::vector<std::string> vertices;
    vertices.push_back("1");
    vertices.push_back("2");
    vertices.push_back("3");
    vertices.push_back("4");
    vertices.push_back("5");
    vertices.push_back("6");

    for (int i = 0; i < (int)vertices.size(); i++) {
        g.addVertex(vertices[i]);
    }

    //add edges from the example in the assignment
    std::vector< std::tuple<std::string, std::string, unsigned long> > edges;
    edges.push_back(std::make_tuple("1", "2", 7));
    edges.push_back(std::make_tuple("1", "3", 9));
    edges.push_back(std::make_tuple("1", "6", 14));
    edges.push_back(std::make_tuple("2", "3", 10));
    edges.push_back(std::make_tuple("2", "4", 15));
    edges.push_back(std::make_tuple("3", "4", 11));
    edges.push_back(std::make_tuple("3", "6", 2));
    edges.push_back(std::make_tuple("4", "5", 6));
    edges.push_back(std::make_tuple("5", "6", 9));

    for (int i = 0; i < (int)edges.size(); i++) {
        std::string a = std::get<0>(edges[i]);
        std::string b = std::get<1>(edges[i]);
        unsigned long w = std::get<2>(edges[i]);
        g.addEdge(a, b, w);
    }

    //find the shortest path from 1 to 5
    std::vector<std::string> path;
    unsigned long distance = g.shortestPath("1", "5", path);

    std::cout << "Shortest distance from 1 to 5: " << distance << std::endl;
    std::cout << "Path: ";
    for (int i = 0; i < (int)path.size(); i++) {
        std::cout << path[i];
        if (i + 1 < (int)path.size()) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    return 0;
}
