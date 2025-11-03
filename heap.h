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
        // adds idx to end of array
        data[size] = idx;
        // moves idx/ fixes it if the minheap order is wrong
        upheap(size,weightArr);
        //size goes up everytime something is pushed
        size++;
    }

    // removes the smallest node index and returns it
    int pop(int weightArr[]) {
        // checks if heap is empty
        if (size == 0) {
            cout << "Heap underflow.";
            return -1; // -1 error
        }
        // Replace root with last element, then call downheap
        int root = data[0]; // root is the smallest element
        data[0] = data[size - 1]; // last element becomes the root
        // size gets smaller
        size--;
        // moves the swapped root down
        downheap(0,weightArr);
        // returns the smallest node index that was removed
        return root;
    }

    // moves nodes up until the minheap order is correct
    void upheap(int pos, int weightArr[]) {
        // Swaps child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2; // parents spot in the heap array
            if (weightArr[data[pos]] < weightArr[data[parent]]) { // compare nodes of child and parent with their weights
                swap(data[pos],data[parent]); // swaps the node index if child is smaller
                pos = parent; // move up to new pos
            }
            else {
                // returns if order is correct
                return;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // Swaps parent downward while larger than any child
        while (true) {
            int left = pos * 2 + 1; // left child index
            int right = pos * 2 + 2; // right child index
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