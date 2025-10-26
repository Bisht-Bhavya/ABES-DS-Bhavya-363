#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;   
};
struct Node* head = NULL;
struct Node* newnode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
 struct Node* insert(struct Node* head, int data) {
    struct Node* new_node = newnode(data);
    if (head == NULL) {
        return new_node;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}
struct Node* reverse(struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void display(struct Node* head) {
    struct Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main(){
    int l=1, data,ch;
     while(l){
        printf("Your choice:\n");
        printf("1.Insert in linked list\n");
        printf("2.Reverse the linked list\n");
        printf("3.Display\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 2:
                head = reverse(head);
                printf("Reversed the Linked List\n");
                break;
            case 3:
                display(head);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Press 1 to continue, 0 to exit: ");
        scanf("%d", &l);
    }
    return 0;
}