#include <stdio.h>
#define N 10  // Maximum size of the deque

int arr[N];
int front = -1;
int rear = -1;

// Insert element at rear
void insert_rear(int n) {
    if ((rear + 1) % N == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {  // First element
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % N;
    }
    arr[rear] = n;
    printf("Inserted %d at rear.\n", n);
}

// Insert element at front
void insert_front(int n) {
    if ((front - 1 + N) % N == rear) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {  // First element
        front = 0;
        rear = 0;
    } else {
        front = (front - 1 + N) % N;
    }
    arr[front] = n;
    printf("Inserted %d at front.\n", n);
}

// Delete element from front
int delete_front() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = arr[front];
    if (front == rear) {  // Only one element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % N;
    }
    return val;
}

// Delete element from rear
int delete_rear() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = arr[rear];
    if (front == rear) {  // Only one element
        front = -1;
        rear = -1;
    } else {
        rear = (rear - 1 + N) % N;
    }
    return val;
}

// Display all elements
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % N;
    }
    printf("\n");
}

// Default insert for legacy compatibility
void insert(int n) {
    insert_rear(n);
}

int main() {
    int choice, n;
    int running = 1;

    while (running) {
        printf("\n========== DEQUE MENU ==========\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert at front: ");
            scanf("%d", &n);
            insert_front(n);
            break;

        case 2:
            printf("Enter the element to insert at rear: ");
            scanf("%d", &n);
            insert_rear(n);
            break;

        case 3:
            n = delete_front();
            if (n != -1)
                printf("Deleted element from front: %d\n", n);
            break;

        case 4:
            n = delete_rear();
            if (n != -1)
                printf("Deleted element from rear: %d\n", n);
            break;

        case 5:
            display();
            break;

        case 0:
            running = 0;
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
