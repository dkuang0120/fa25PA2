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

    void push(int idx, int weightArr[]) {
        if (size >= 64) { //edge case if heap is full
            return;
        }
        data[size] = idx; // place element at the end
        upheap(size, weightArr); // move it up until heap is proper
        size++; // increase heap size
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) { // edge case if heap is empty
            return -1;
        }
        int root = data[0]; // root holds smallest element
        data[0] = data[size - 1]; // move last element to root position
        size--; // decrement size once element is removed
        if (size > 0) { // push structure down if heap is not empty
            downheap(0, weightArr);
        }

        return root; // return smallest index
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int p = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[data[p]]) {
                int temp = data[pos];
                data[pos] = data[p];
                data[p] = temp;
                pos = p;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int smallest = pos;

            if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) {
                smallest = leftChild;
            }
            if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) {
                smallest = rightChild;
            }
            if (smallest != pos) {
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif