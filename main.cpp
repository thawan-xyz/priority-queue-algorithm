#include <iostream>
using namespace std;

template <typename E>
class MaxPriorityQueue {
public:
    MaxPriorityQueue(E* array, int length, int capacity) : array{array}, length(length), capacity(capacity) {
        for (int index = length - 1 / 2; index > -1; --index) {
            int parentIndex = index; E parentValue = array[parentIndex];

            bool isPriorityQueue = false;
            while (!isPriorityQueue && ((2 * parentIndex) + 1) < length) {
                int childIndex = (2 * parentIndex) + 1;

                if (childIndex < length - 1) if (array[childIndex + 1] > array[childIndex]) childIndex++;

                if (parentValue >= array[childIndex]) {
                    isPriorityQueue = true;
                }
                else {
                    array[parentIndex] = array[childIndex]; parentIndex = childIndex;
                }
            }
            array[parentIndex] = parentValue;
        }
    }

    ~MaxPriorityQueue() = default;

    void insert(E value) {
        if (length == capacity) return;

        array[length + 1] = value;

        length++;

    }

    E remove() {
        if (length < 0) return E{};

        E tempValue = array[0]; array[0] = array[length - 1];

        length--;

        int parentIndex = 0; E parentValue = array[parentIndex];

        bool isPriorityQueue = false;
        while (!isPriorityQueue && ((2 * parentIndex) + 1) < length) {
            int childIndex = (2 * parentIndex) + 1;

            if (childIndex < length - 1) if (array[childIndex + 1] > array[childIndex]) childIndex++;

            if (parentValue >= array[childIndex]) {
                isPriorityQueue = true;
            }
            else {
                array[parentIndex] = array[childIndex]; parentIndex = childIndex;
            }
        }
        array[parentIndex] = parentValue;

        return tempValue;
    }

    void print() const {
        for (int i = 0; i < length; ++i) {
            cout << array[i]; if (i < length - 1) cout << " ";
        }
    }

    E* getArray() const {
        return array;
    }

    int getLength() const {
        return length;
    }

    int getCapacity() const {
        return capacity;
    }

private:
    E* array;
    int length;
    int capacity;
};

int main() {
    return 0;
}
