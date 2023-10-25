#include <iostream>
#include <stdexcept>
using namespace std;

class StackArr {
private:
    int* data;
    int capacity;
    int size;
    friend class StackArrAdapter;
public:
    StackArr(int capacity) {
        this->capacity = capacity;
        this->data = new int[capacity];
        this->size = 0;
    }

    ~StackArr() {
        delete[] data;
    }

    void push(int value) {
        if (!isFull()) {
            data[size] = value;
            size++;
        }
    }

    void pop() {
        if (!isEmpty()) size--;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << data[size - i - 1] << " ";
        }
        cout << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

class StackArrAdapter : public StackArr {
public:
    StackArrAdapter(int capacity) : StackArr(capacity) {}

    void SetElement(int index, int data) {
        if (index >= 0 && index < size) {
            this->data[index] = data;
        }
    }

    int GetElement(int index) {
        if (index >= 0 && index < size) {
            return this->data[index];
        }
    }
};

int main() {
    StackArrAdapter stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.display();

    stack.SetElement(2, 99);

    stack.display();


    int element = stack.GetElement(2);
    cout << element << endl;
}
