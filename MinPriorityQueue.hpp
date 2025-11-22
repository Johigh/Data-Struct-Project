#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <string>
#include <vector>

struct PQNode {
    unsigned long dist;
    std::string label;
};

// Very simple min-heap priority queue for Dijkstra
class MinPriorityQueue {
public:
    MinPriorityQueue();
    ~MinPriorityQueue();

    void push(const PQNode &node);  // add new node
    PQNode top() const;             // read smallest node
    void pop();                     // remove smallest node
    bool empty() const;             // true if queue is empty

private:
    std::vector<PQNode> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

    int parent(int index) const { return (index - 1) / 2; }
    int leftChild(int index) const { return 2 * index + 1; }
    int rightChild(int index) const { return 2 * index + 2; }
};

#endif
