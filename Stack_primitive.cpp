#include <iostream>
using namespace std;

#define MAX 5
int top = -1;
int stack[MAX]; 

void push(int x) {
    if (top == MAX - 1) {
        cout << "Overflow" << endl;
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        cout << "Underflow" << endl;
        return -1;
    } else {
        return stack[top--];
    }
}

void display() {
    if (top == -1) {
        cout << "stack is empty" << endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, x;
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> x;
                push(x);
                break;

            case 2: {
                int popped = pop();
                if (popped != -1)
                    cout << "Popped Element = " << popped << endl;
                break;
            }

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
