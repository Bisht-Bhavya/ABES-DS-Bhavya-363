#include <iostream>
using namespace std;
struct stacknode {
    int data;
    stacknode* next;
};

struct stacknode* top = NULL;
struct stacknode* ptr = NULL;

struct stacknode* newnode(int x){
    struct stacknode* node = (struct stacknode*)malloc(sizeof(struct stacknode));
    node->data = x;
    node->next = NULL;
    return node;
}

void push(int x) {
    ptr = newnode(x);
    if (top == NULL) {
        top = ptr;
    } else {
        ptr->next = top;
        top = ptr;
    }
}

int pop() {
    if (top == NULL) {
        cout << "Underflow" << endl;
        return -1;
    } else {
        ptr = top;
        int popped = ptr->data;
        top = top->next;
        free(ptr);
        return popped;
    }
}

void display() {
    if (top == NULL) {
        cout << "stack is empty" << endl;
        return;
    }
    ptr = top;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
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
