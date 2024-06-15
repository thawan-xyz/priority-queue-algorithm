#include <iostream>
using namespace std;

template <typename E>
class PriorityQueue {
public:
    PriorityQueue(E* array, int capacity, int length) : array{array}, capacity(capacity), length(length) {
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

    ~PriorityQueue() = default;

    void insert(E value) {
        if (length == capacity) return;

        array[length] = value;

        int childIndex = length; E childValue = array[childIndex];

        length++;

        bool isPriorityQueue = false;
        while (!isPriorityQueue && childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (array[parentIndex] >= childValue) {
                isPriorityQueue = true;
            }
            else {
                array[childIndex] = array[parentIndex]; childIndex = parentIndex;
            }
        }
        array[childIndex] = childValue;
    }

    E remove() {
        if (length < 0) return E{};

        E tempValue = array[0]; array[0] = array[length - 1];

        int parentIndex = 0; E parentValue = array[parentIndex];

        length--;

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
    int capacity;
    int length;
};

int main() {
    return 0;
}
