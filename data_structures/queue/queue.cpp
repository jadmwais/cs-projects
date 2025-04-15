#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    // Add item to the end
    void enqueue(int value) {
        if (rear >= MAX_SIZE - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear] = value;
        cout << value << " enqueued." << endl;
    }

    // Remove item from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }

    // View front item
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
        return front > rear;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// --- Main Program ---
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    return 0;
}
