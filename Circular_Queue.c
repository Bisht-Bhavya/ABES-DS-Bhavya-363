#include <stdio.h>
#define N 10

int arr[N];
int front = -1;
int rear = -1;

void insert(int n) {
    if ((rear + 1) % N == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % N;
    }
    arr[rear] = n;
}

int delete() {
    if (front == -1) {
        printf("Underflow\n");
        return 0;
    }
    int val = arr[front];
    if (front == rear) { 
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % N;
    }
    return val;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear)  break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main() {
    int choice, n;
    int i = 1;

    while (i != 0) {
        printf("\nEnter your choice:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf("Deleted element: %d\n", delete());
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid choice\n");
        }

        printf("Press 0 to terminate: ");
        scanf("%d", &i);
    }

    return 0;
}
