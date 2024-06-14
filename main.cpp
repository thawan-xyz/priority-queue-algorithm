#include <iostream>
#include <vector>
using namespace std;

// @author Thawan

template <typename E>
// Converts an array into a max priority queue
void arrayToMaxPriorityQueue(vector<E>& array, int& length) {
    // Start from the last parent node and adjust downwards
    for (int index = length / 2; index > 0; --index) {
        // Current parent index and value
        int parentIndex = index; E parentValue = array[parentIndex];

        bool isPriorityQueue = false;
        // Adjust to maintain max priority queue property
        while (!isPriorityQueue && (2 * parentIndex) < length) {
            // Current first child index
            int childIndex = parentIndex * 2;

            // Determine the bigger child
            if (childIndex < length - 1) if (array[childIndex + 1] > array[childIndex]) childIndex++;

            // Check if parent satisfies max priority queue property
            if (parentValue >= array[childIndex]) {
                // Parent satisfies max priority queue property
                isPriorityQueue = true;
            }
            else {
                // Replace parent with bigger child and move to that child
                parentIndex = childIndex; array[parentIndex] = array[childIndex];
            }
        }
        // Place the original parent value in its correct position
        array[parentIndex] = parentValue;
    }
}

template <typename E>
// Removes and returns the highest priority element from a max priority queue
E removeMaxPriorityQueue(vector<E>& array, int& length) {
    // Store the highest priority element and move last element to root
    E tempValue = array[1]; array[1] = array[length - 1];

    // Remove the last element and update length
    array.pop_back(); length--;

    // Current parent index and value
    int parentIndex = 1; E parentValue = array[parentIndex];

    bool isPriorityQueue = false;
    // Adjust to maintain max priority queue property
    while (!isPriorityQueue && (2 * parentIndex) < length) {
        // Current first child index
        int childIndex = parentIndex * 2;

        // Determine the bigger child
        if (childIndex < length - 1) if (array[childIndex + 1] > array[childIndex]) childIndex++;

        // Check if parent satisfies max priority queue property
        if (parentValue >= array[childIndex]) {
            // Parent satisfies max priority queue property
            isPriorityQueue = true;
        }
        else {
            // Replace parent with bigger child and move to that child
            parentIndex = childIndex; array[parentIndex] = array[childIndex];
        }
    }
    // Place the original parent value in its correct position
    array[parentIndex] = parentValue;

    // Return the removed highest priority element
    return tempValue;
}

template <typename E>
// Converts an array into a min priority queue
void arrayToMinPriorityQueue(vector<E>& array, int& length) {
    // Start from the last parent node and adjust downwards
    for (int index = length / 2; index > 0; --index) {
        // Current parent index and value
        int parentIndex = index; E parentValue = array[parentIndex];

        bool isPriorityQueue = false;
        // Adjust to maintain min priority queue property
        while (!isPriorityQueue && (2 * parentIndex) < length) {
            // Current first child index
            int childIndex = parentIndex * 2;

            // Determine the smaller child
            if (childIndex < length - 1) if (array[childIndex + 1] < array[childIndex]) childIndex++;

            // Check if parent satisfies min priority queue property
            if (parentValue <= array[childIndex]) {
                // Parent satisfies min priority queue property
                isPriorityQueue = true;
            }
            else {
                // Replace parent with smaller child and move to that child
                parentIndex = childIndex; array[parentIndex] = array[childIndex];
            }
        }
        // Place the original parent value in its correct position
        array[parentIndex] = parentValue;
    }
}

template <typename E>
// Removes and returns the lowest priority element from a min priority queue
E removeMinPriorityQueue(vector<E>& array, int& length) {
    // Store the lowest priority element and move last element to root
    E tempValue = array[1]; array[1] = array[length - 1];

    // Remove the last element and update length
    array.pop_back(); length--;

    // Current parent index and value
    int parentIndex = 1; E parentValue = array[parentIndex];

    bool isPriorityQueue = false;
    // Adjust to maintain min priority queue property
    while (!isPriorityQueue && (2 * parentIndex) < length) {
        // Current first child index
        int childIndex = parentIndex * 2;

        // Determine the smaller child
        if (childIndex < length - 1) if (array[childIndex + 1] < array[childIndex]) childIndex++;

        // Check if parent satisfies min priority queue property
        if (parentValue <= array[childIndex]) {
            // Parent satisfies min priority queue property
            isPriorityQueue = true;
        }
        else {
            // Replace parent with smaller child and move to that child
            parentIndex = childIndex; array[parentIndex] = array[childIndex];
        }
    }
    // Place the original parent value in its correct position
    array[parentIndex] = parentValue;

    // Return the removed lowest priority element
    return tempValue;
}

int main() {
    return 0;
}
