#include "MinPriorityQueue.hpp"

MinPriorityQueue::MinPriorityQueue() {
}

MinPriorityQueue::~MinPriorityQueue() {
}

void MinPriorityQueue::push(const PQNode &node) {
    // Put new node at the end and move it up
    heap.push_back(node);
    int index = (int)heap.size() - 1;
    heapifyUp(index);
}

PQNode MinPriorityQueue::top() const {
    // Smallest element is always at index 0
    return heap[0];
}

void MinPriorityQueue::pop() {
    if (heap.empty()) {
        return;
    }

    if (heap.size() == 1) {
        heap.pop_back();
        return;
    }

    // Move last element to the front and push it down
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapifyDown(0);
}

bool MinPriorityQueue::empty() const {
    return heap.empty();
}

void MinPriorityQueue::heapifyUp(int index) {
    // While we are not at the root and current dist is smaller than parent
    while (index > 0) {
        int p = parent(index);
        if (heap[index].dist < heap[p].dist) {
            PQNode temp = heap[index];
            heap[index] = heap[p];
            heap[p] = temp;
            index = p;
        } else {
            break;
        }
    }
}

void MinPriorityQueue::heapifyDown(int index) {
    int size = (int)heap.size();

    while (true) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        // pick the child with smaller dist
        if (left < size && heap[left].dist < heap[smallest].dist) {
            smallest = left;
        }
        if (right < size && heap[right].dist < heap[smallest].dist) {
            smallest = right;
        }

        // if the smallest is not the current index, swap
        if (smallest != index) {
            PQNode temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            index = smallest;
        } else {
            break; // heap property restored
        }
    }
}
