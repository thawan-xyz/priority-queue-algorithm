#include <iostream>
#include <vector>
using namespace std;

template <typename E>
class MaxPriorityQueue {
public:
    MaxPriorityQueue(vector<E> iArray, int iLength) : array{iArray}, length(iLength) {
        for (int index = length / 2; index > 0; --index) {
            int parentIndex = index; E parentValue = array[parentIndex];

            bool isPriorityQueue = false;
            while (!isPriorityQueue && (2 * parentIndex) < length) {
                int childIndex = parentIndex * 2;

                if (childIndex < length - 1) if (array[childIndex + 1] > array[childIndex]) childIndex++;

                if (parentValue >= array[childIndex]) {
                    isPriorityQueue = true;
                }
                else {
                    parentIndex = childIndex; array[parentIndex] = array[childIndex];
                }
            }
            array[parentIndex] = parentValue;
        }
    }

    ~MaxPriorityQueue() = default;

    E removeMax() {
        if (length <= 1) return E{};

        E tempValue = array[1]; array[1] = array[length - 1];

        array.pop_back(); length--;

        int parentIndex = 1; E parentValue = array[parentIndex];

        bool isPriorityQueue = false;
        while (!isPriorityQueue && (2 * parentIndex) < length) {
            int childIndex = parentIndex * 2;

            if (childIndex < length - 1) if (array[childIndex + 1] > array[childIndex]) childIndex++;

            if (parentValue >= array[childIndex]) {
                isPriorityQueue = true;
            }
            else {
                parentIndex = childIndex; array[parentIndex] = array[childIndex];
            }
        }
        array[parentIndex] = parentValue;

        return tempValue;
    }

    vector<E> getArray() const {
        return array;
    }

    int getLength() const {
        return length;
    }

private:
    vector<E> array;
    int length;
};

int main() {
    return 0;
}
