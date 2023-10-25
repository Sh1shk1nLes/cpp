#include <iostream>
#include <stdexcept>

using namespace std;

class StackArr {
private:
    int* data;
    int capacity;
    int size;

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
        for (int i = 0; i < size; i++) cout << data[size - i - 1] << " ";
        cout << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    
    StackArr myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);

    myStack.display();

    myStack.pop();
    myStack.pop();
    myStack.pop();

    myStack.display();


    myStack.pop();
    myStack.pop();

    myStack.display();

    myStack.pop();

    myStack.display();
}
