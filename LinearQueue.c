#include <stdio.h>
#define N 10
int arr[N];
int front = -1;
int rear = -1;
void insert(int n){
if(front == 0 && rear == N-1){
printf("Queue is full \n");
return;
}
rear++;
arr[rear] = n;
}

int delete(){
    if(front == rear){
        printf("Underflow \n");
        return 0;
    }
    front++;
    return arr[front];
}

void display(){
    if(front == rear){
        printf("Queue is empty \n");
        return;
    }
    for(int i = front + 1; i <= rear; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
int n;
int i = 1;
while(i != 0){
printf("Enter your choice: \n");
printf("1.Insertion\n");
printf("2.Deletion\n");
printf("3.Display\n");
scanf("%d", &n);
switch(n){
case 1:
printf("Enter the element to insert: \n");
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
printf("Invalid choice \n");
}
printf("press 0 to terminate: ");
scanf("%d", &i);
}
}