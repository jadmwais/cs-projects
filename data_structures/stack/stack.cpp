#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Add element to the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }

    // Remove top element
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    // Peek at top element
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Display stack contents
    void display() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// --- Main Program ---
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    return 0;
}
