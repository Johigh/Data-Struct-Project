#include "Graph_1.hpp"

#include <limits>
#include <unordered_set>

//no intialization needed as vertices auto initializes to empty map
Graph::Graph() {
}

Graph::~Graph() {
}

void Graph::addVertex(std::string label) {
    //only add if it does not already exist
    if (vertices.find(label) == vertices.end()) {
        Vertex v;
        v.label = label;
        vertices[label] = v;
    }
}

void Graph::removeVertex(std::string label) {
    // If vertex does not exist, nothing to do
    if (vertices.find(label) == vertices.end()) {
        return;
    }

    // First remove any edges from other vertices that point to this one
    for (auto &pair : vertices) {
        std::vector<Edge> &nbrs = pair.second.neighbors;
        for (int i = 0; i < (int)nbrs.size(); /* no ++ here */) {
            if (nbrs[i].to == label) {
                // Erase this edge
                nbrs.erase(nbrs.begin() + i);
            } else {
                i++;
            }
        }
    }

    // Now erase the vertex itself
    vertices.erase(label);
}

void Graph::addEdge(std::string label1,
                    std::string label2,
                    unsigned long weight) {
    // No self loops and both vertices must exist
    if (label1 == label2) {
        return;
    }
    if (vertices.find(label1) == vertices.end() ||
        vertices.find(label2) == vertices.end()) {
        return;
    }

    // Check if edge already exists from label1 to label2
    std::vector<Edge> &nbrs1 = vertices[label1].neighbors;
    for (int i = 0; i < (int)nbrs1.size(); i++) {
        if (nbrs1[i].to == label2) {
            return; // edge already there
        }
    }

    // Undirected edge: add in both directions
    Edge e1;
    e1.to = label2;
    e1.weight = weight;
    vertices[label1].neighbors.push_back(e1);

    Edge e2;
    e2.to = label1;
    e2.weight = weight;
    vertices[label2].neighbors.push_back(e2);
}

void Graph::removeEdge(std::string label1,
                       std::string label2) {
    if (vertices.find(label1) == vertices.end() ||
        vertices.find(label2) == vertices.end()) {
        return;
    }

    // Remove label2 from label1's neighbor list
    std::vector<Edge> &nbrs1 = vertices[label1].neighbors;
    for (int i = 0; i < (int)nbrs1.size(); /* no ++ here */) {
        if (nbrs1[i].to == label2) {
            nbrs1.erase(nbrs1.begin() + i);
        } else {
            i++;
        }
    }

    // Remove label1 from label2's neighbor list
    std::vector<Edge> &nbrs2 = vertices[label2].neighbors;
    for (int i = 0; i < (int)nbrs2.size(); /* no ++ here */) {
        if (nbrs2[i].to == label1) {
            nbrs2.erase(nbrs2.begin() + i);
        } else {
            i++;
        }
    }
}

unsigned long Graph::shortestPath(std::string startLabel,
                                  std::string endLabel,
                                  std::vector<std::string> &path) {
    path.clear();

    // If either vertex is missing, we cannot find a path
    if (vertices.find(startLabel) == vertices.end() ||
        vertices.find(endLabel) == vertices.end()) {
        return std::numeric_limits<unsigned long>::max();
    }

    if (startLabel == endLabel) {
        path.push_back(startLabel);
        return 0;
    }

    const unsigned long INF = std::numeric_limits<unsigned long>::max();

    // Distance and predecessor maps
    std::unordered_map<std::string, unsigned long> dist;
    std::unordered_map<std::string, std::string> prev;
    std::unordered_set<std::string> visited;

    // Set all distances to INF
    for (auto &pair : vertices) {
        dist[pair.first] = INF;
    }

    dist[startLabel] = 0;

    MinPriorityQueue pq;
    PQNode startNode;
    startNode.dist = 0;
    startNode.label = startLabel;
    pq.push(startNode);

    while (!pq.empty()) {
        PQNode current = pq.top();
        pq.pop();

        std::string u = current.label;
        unsigned long d = current.dist;

        if (visited.find(u) != visited.end()) {
            continue;
        }

        visited.insert(u);

        // Once we reach the end label, we can stop
        if (u == endLabel) {
            break;
        }

        // Go through all neighbors
        std::vector<Edge> &nbrs = vertices[u].neighbors;
        for (int i = 0; i < (int)nbrs.size(); i++) {
            std::string v = nbrs[i].to;
            unsigned long w = nbrs[i].weight;

            if (visited.find(v) != visited.end()) {
                continue;
            }

            if (d == INF) {
                continue;
            }

            unsigned long newDist = d + w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                prev[v] = u;

                PQNode nextNode;
                nextNode.dist = newDist;
                nextNode.label = v;
                pq.push(nextNode);
            }
        }
    }

    if (dist[endLabel] == INF) {
        // No path found
        return INF;
    }

    // Reconstruct the path from endLabel back to startLabel
    std::vector<std::string> reversePath;
    std::string currentLabel = endLabel;

    while (true) {
        reversePath.push_back(currentLabel);
        if (currentLabel == startLabel) {
            break;
        }

        // Move to the previous vertex
        if (prev.find(currentLabel) == prev.end()) {
            // something went wrong
            path.clear();
            return INF;
        }

        currentLabel = prev[currentLabel];
    }

    // Now reverse the vector so it goes start -> end
    for (int i = (int)reversePath.size() - 1; i >= 0; i--) {
        path.push_back(reversePath[i]);
    }

    return dist[endLabel];
}
