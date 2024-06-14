#include <iostream>
using namespace std;

template <typename E>
class MaxPriorityQueue {
public:
    MaxPriorityQueue(E* array, int length, int capacity) : array{array}, length(length), capacity(capacity) {
        for (int index = length / 2; index > 0; --index) {
            int parentIndex = index; E parentValue = array[parentIndex];

            bool isPriorityQueue = false;
            while (!isPriorityQueue && (2 * parentIndex) <= length) {
                int childIndex = parentIndex * 2;

                if (childIndex < length) if (array[childIndex + 1] > array[childIndex]) childIndex++;

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
    }

    E remove() {
        if (length < 1) return E{};

        E tempValue = array[1]; array[1] = array[length];

        length--;

        int parentIndex = 1; E parentValue = array[parentIndex];

        bool isPriorityQueue = false;
        while (!isPriorityQueue && (2 * parentIndex) <= length) {
            int childIndex = parentIndex * 2;

            if (childIndex < length) if (array[childIndex + 1] > array[childIndex]) childIndex++;

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

    void print() {
        for (int i = 1; i <= length; ++i) {
            cout << array[i]; if (i != length) cout << " ";
        }
    }

    void sort(int range) {
        if (range > length) return;

        auto copy = new E[range + 1]; for (int i = 0; i <= range; ++i) { copy[i] = array[i]; }

        while (range > 0) {
            E tempValue = copy[1]; copy[1] = copy[range];

            range--;

            int parentIndex = 1; E parentValue = copy[parentIndex];

            bool isPriorityQueue = false;
            while (!isPriorityQueue && (2 * parentIndex) <= range) {
                int childIndex = parentIndex * 2;

                if (childIndex < range) if (copy[childIndex + 1] > copy[childIndex]) childIndex++;

                if (parentValue >= copy[childIndex]) {
                    isPriorityQueue = true;
                }
                else {
                    copy[parentIndex] = copy[childIndex]; parentIndex = childIndex;
                }
            }
            copy[parentIndex] = parentValue;

            cout << tempValue; if (range != 0) cout << " ";
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
