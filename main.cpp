#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Stack {
private:
    int top;
    int* arr;
    int size;

public:
    Stack(int size = 10) {
        this->size = size;
        top = -1;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count() {
        return (top + 1);
    }

    int peek(int pos) {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            return arr[pos];
        }
    }

    void change(int pos, int val) {
        arr[pos] = val;
        cout << "Value successfully changed at index " << pos << endl;
    }

    void display() {
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    Queue(int size = 10) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
        } else if (isEmpty()) {
            front = rear = 0;
            arr[rear] = val;
        } else {
            rear++;
            arr[rear] = val;
        }
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return 0;
        } else if (front == rear) {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        } else {
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }

    int count() {
        return (rear - front + 1);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void sortList() {
    vector<int> list;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.push_back(value);
    }

    sort(list.begin(), list.end());

    cout << "Sorted list:\n";
    for (const auto& elem : list) {
        cout << elem << " ";
    }
    cout << endl;
}

void stackMenu(Stack& s1) {
    int option, position, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. isFull()\n";
        cout << "2. isEmpty()\n";
        cout << "3. Push()\n";
        cout << "4. Pop()\n";
        cout << "5. Count()\n";
        cout << "6. Peek()\n";
        cout << "7. Change()\n";
        cout << "8. Display()\n";
        cout << "9. Clear Screen\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << (s1.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
                break;
            case 2:
                cout << (s1.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;
                break;
            case 3:
                cout << "Enter the value to push: ";
                cin >> value;
                s1.push(value);
                break;
            case 4:
                cout << "Popped value: " << s1.pop() << endl;
                break;
            case 5:
                cout << "Stack count: " << s1.count() << endl;
                break;
            case 6:
                cout << "Enter the position to peek: ";
                cin >> position;
                cout << "Value at position " << position << ": " << s1.peek(position) << endl;
                break;
            case 7:
                cout << "Enter the position to change: ";
                cin >> position;
                cout << "Enter the new value: ";
                cin >> value;
                s1.change(position, value);
                break;
            case 8:
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (option != 0);
}

void queueMenu(Queue& q1) {
    int option, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. isFull()\n";
        cout << "2. isEmpty()\n";
        cout << "3. Enqueue()\n";
        cout << "4. Dequeue()\n";
        cout << "5. Count()\n";
        cout << "6. Display()\n";
        cout << "7. Clear Screen\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << (q1.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 2:
                cout << (q1.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 3:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q1.enqueue(value);
                break;
            case 4:
                cout << "Dequeued value: " << q1.dequeue() << endl;
                break;
            case 5:
                cout << "Queue count: " << q1.count() << endl;
                break;
            case 6:
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (option != 0);
}

int main() {
    Stack s1;
    Queue q1;
    int operation;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Stack Operations\n";
        cout << "2. Queue Operations\n";
        cout << "3. Sort a List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> operation;

        switch (operation) {
            case 1:
                stackMenu(s1);
                break;
            case 2:
                queueMenu(q1);
                break;
            case 3:
                sortList();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (operation != 4);

    return 0;
}
