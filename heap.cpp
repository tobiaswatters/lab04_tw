// heap.cpp
// Diba Mirza
// Tobias Watters

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
    for (auto i=start; i!=end; i++) {
        vdata.push_back(*i);
    }
    for (int i = static_cast<int>(vdata.size()/2 - 1); i >= 0; i--) {

        // while left child exists
        while (2*i + 1 < static_cast<int>(vdata.size())) { // while current node has children

            int left = 2*i + 1;
            int right = 2*i + 2;

            // only left child exists
            if (right >= static_cast<int>(vdata.size())) {
                if (vdata[left]<vdata[i]) {
                    int temp = vdata[left]; // swap values with left child
                    vdata[left] = vdata[i];
                    vdata[i] = temp;
                    i = left;
                }
                else break; // min heap property restored: break while
            } else {
                int minChild; // index of smallest child
                if (vdata[left]<vdata[right]) minChild = left; else minChild = right; 
                
                if (vdata[minChild] < vdata[i]) { // swap with smallest child
                    int temp = vdata[minChild];
                    vdata[minChild] = vdata[i];
                    vdata[i] = temp; 
                    i = minChild; // update current index
                } else break; // min heap property restored: break while
            }
        }
    }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);

    int i = static_cast<int>(vdata.size() - 1);

    // bubble up
    while (i > 0 && vdata[(i - 1) / 2] > vdata[i]) { // while not root
        int parent = (i - 1) / 2; // swap
        int temp = vdata[parent];
        vdata[parent] = vdata[i];
        vdata[i] = temp;

        i = parent; // update current index
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    
    vdata[0] = vdata[static_cast<int>(vdata.size()-1)]; // rewrite "root" node
    vdata.pop_back(); // delete last entry of vdata

    int i = 0; // current index
    // bubble down:
    while (2*i + 1 < static_cast<int>(vdata.size())) { // while current node has children

        int left = 2*i + 1;
        int right = 2*i + 2;

        // only left child exists
        if (right >= static_cast<int>(vdata.size())) {
            if (vdata[left]<vdata[i]) {
                int temp = vdata[left]; // swap values with left child
                vdata[left] = vdata[i];
                vdata[i] = temp;
                i = left;
            }
            else break; // min heap property restored: break while
        } else {
            int minChild; // index of smallest child
            if (vdata[left]<vdata[right]) minChild = left; else minChild = right; 
            
            if (vdata[minChild] < vdata[i]) { // swap with smallest child
                int temp = vdata[minChild];
                vdata[minChild] = vdata[i];
                vdata[i] = temp; 
                i = minChild; // update current index
            } else break; // min heap property restored: break while
        }
    }
}

// Returns the minimum element in the heap
int Heap::top(){
    if (!vdata.empty()) return vdata[0];
    else return 0;
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    