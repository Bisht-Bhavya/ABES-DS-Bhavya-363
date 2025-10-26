#include <bits/stdc++.h>
using namespace std;

struct linklist {
    int data;
    struct linklist* next;
};

struct linklist* start = NULL;

// Create new node
struct linklist* getnode(int x) {
    struct linklist* node = (struct linklist*) malloc(sizeof(struct linklist));
    node->data = x;
    node->next = NULL;
    return node;
}

// Display list
void display(struct linklist* start) {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct linklist* p = start->next;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != start->next);
    cout << endl;
}

// Insert at beginning
struct linklist* insbeg(struct linklist* start, int x) {
    struct linklist* node = getnode(x);
    if (start == NULL) {
        node->next = node;
        return node; // first node (points to itself)
    }
    node->next = start->next;
    start->next = node;
    return start;
}

// Insert at end
struct linklist* insend(struct linklist* start, int x) {
    struct linklist* node = getnode(x);
    if (start == NULL) {
        node->next = node;
        return node;
    }
    node->next = start->next;
    start->next = node;
    return node; // new last node becomes start
}

// Insert after a given key
struct linklist* insafter(struct linklist* start, int key, int x) {
    if (start == NULL) return NULL;
    struct linklist* node = getnode(x);
    struct linklist* p = start->next;
    do {
        if (p->data == key) {
            node->next = p->next;
            p->next = node;
            if (p == start) start = node; // update last node if inserted at end
            return start;
        }
        p = p->next;
    } while (p != start->next);
    cout << "Key not found\n";
    free(node);
    return start;
}

// Delete from beginning
struct linklist* delbeg(struct linklist* start) {
    if (start == NULL) return NULL;
    struct linklist* p = start->next;
    if (p == start) { // only one node
        free(p);
        return NULL;
    }
    start->next = p->next;
    free(p);
    return start;
}

// Delete after a given key
void delafter(struct linklist* start, int key) {
    if (start == NULL) return;
    struct linklist* p = start->next;
    do {
        if (p->data == key) {
            struct linklist* q = p->next;
            if (q == start) start = p; // deleting last node
            p->next = q->next;
            free(q);
            return;
        }
        p = p->next;
    } while (p != start->next);
    cout << "Key not found\n";
}

// Delete from end
struct linklist* delend(struct linklist* start) {
    if (start == NULL) return NULL;
    struct linklist* p = start->next;
    if (p == start) { // only one node
        free(p);
        return NULL;
    }
    while (p->next != start) {
        p = p->next;
    }
    p->next = start->next;
    free(start);
    return p; // new last node
}

int main() {
    int choice, i=1, x, key;
    while (i != 0) {
        cout << "\nEnter your choice:\n";
        cout << "1. Insertion at beginning\n";
        cout << "2. Insertion after a node\n";
        cout << "3. Insertion at end\n";
        cout << "4. Deletion at beginning\n";
        cout << "5. Deletion after a node\n";
        cout << "6. Deletion at end\n";
        cout << "7. Display\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                start = insbeg(start, x);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> x;
                cout << "Enter key after which to insert: ";
                cin >> key;
                start = insafter(start, key, x);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> x;
                start = insend(start, x);
                break;
            case 4:
                start = delbeg(start);
                break;
            case 5:
                cout << "Enter key after which to delete: ";
                cin >> key;
                delafter(start, key);
                break;
            case 6:
                start = delend(start);
                break;
            case 7:
                display(start);
                break;
            default:
                cout << "Invalid choice\n";
        }

        cout << "Press 0 to terminate, any other key to continue: ";
        cin >> i;
    }
    cout << "Terminated\n";
}
