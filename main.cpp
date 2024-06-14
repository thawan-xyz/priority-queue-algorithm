#include <iostream>
#include <vector>
using namespace std;

template <typename E>
void arrayToPriorityQueue(vector<E>& array, int& length) {
    for (int index = length / 2; index > 0; --index) {
        int parentIndex = index; E parentValue = array[parentIndex];

        bool isPriorityQueue = false;
        while (!isPriorityQueue && (2 * parentIndex <= length)) {
            int childIndex = parentIndex * 2;

            if (childIndex < length) if (array[childIndex + 1] > array[childIndex]) childIndex++;

            if (parentValue > array[childIndex]) {
                isPriorityQueue = true;
            }
            else {
                array[parentIndex] = array[childIndex];
                parentIndex = childIndex;
            }
        }
        array[parentIndex] = parentValue;
    }
}

int main() {
    return 0;
}
