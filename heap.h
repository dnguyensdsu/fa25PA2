//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    // inserts the index at size and restores the heap upward
    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size,weightArr);
        size++;
    }

    // removes the smallest index
    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // checks if heap is empty
        if (size == 0) {
            return -1;
        }
        // Replace root with last element, then call downheap
        int root = data[0]; // root is the smallest element
        data[0] = data[size - 1]; // last element becomes the root
        size--;
        downheap(0,weightArr);
        return root; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2; // parents spot in the heap array
            if (weightArr[data[pos]] < weightArr[data[parent]]) { // compare nodes
                swap(data[pos],data[parent]); // swaps the node index
                pos = parent;
            }
            else {
                return;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = pos * 2 + 1; // left child
            int right = pos * 2 + 2; // right child

            int min = pos; // start at smallest

            // if the left child is a thing and is smaller, mark
            if (left < size && weightArr[data[left]] < weightArr[data[min]]) {
                min = left;
            }

            // otherwise, if right child is a thing and is smaller than left, mark
            if (right < size && weightArr[data[right]] < weightArr[data[min]]) {
                min = right;
            }
            // if the child is smaller than both, we swap and start from child
            if (min != pos) {
                swap(data[pos],data[min]);
                pos = min; // moves down to the smaller child
            }
            else {
                break;
            }
        }
    }
};

#endif