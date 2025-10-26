#include <stdio.h>
#define N 10
int arr[N];

void insert(int n, int rear){
if(rear == N-1){
printf("Queue is full");
return;
}
rear++;
arr[rear] = n;
}

int delete(int front, int rear){
    if(front == rear){
        printf("Underflow");
        return -1;
    }
    front++;
    return arr[front];
}
int main(){
int n;
int rear = -1;
int front = -1;
int i = 1;
while(i != 0){
printf("Enter your choice");
printf("1.Insertion");
printf("2.Deletion");
printf("3.Display");
scanf("%d", &n);
switch(n){
case 1:
printf("Enter the element to insert: ");
scanf("%d", &n);
insert(n,rear);
break;
case 2:

}
}
}