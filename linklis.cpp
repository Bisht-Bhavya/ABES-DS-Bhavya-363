#include <bits/stdc++.h>
using namespace std;
struct linklist{
    int data;
    struct linklist* next;
};
struct linklist* start = NULL;
struct linklist* p;

struct linklist* getnode(){
    struct linklist* node = (struct linklist*) malloc (sizeof(struct linklist*));
    node->next = NULL;
    return node;
}

void display(struct linklist* start){
p = start;
while( p != NULL ){
    cout << p->data <<" ";
    p = p->next;
}
cout << endl;
}

struct linklist* insbeg(struct linklist* start, int x){
struct linklist* node = getnode();
node->data = x;
node->next = start;
start = node ;
return (start);
}

struct linklist* insend(struct linklist* start, int x){
struct linklist* node = getnode();
node->data = x;
p = start;
if(start == NULL){
return node;
}
while(p->next != NULL){
    p = p->next;
}
p->next = node;
node->next = NULL;
return start;
}

struct linklist* insafter(struct linklist* start, int key, int x){
    struct linklist* node = getnode();
    node->data = x;
    p = start;
    if(start == NULL){
        return node;
    }
    while(p->data != key){
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    return start;
}

struct linklist* delbeg(struct linklist* start){
    p = start ;
    int x;
    start = start->next;
    x = start->data;
    free(p);
    return (start);
}

void delafter(struct linklist* start, int key){
    struct linklist* q = NULL;
    p = start;
    while(p->data != key){
     p = p->next;
    }
    q = p->next;
    p->next = p->next->next;
    free(q);
}

void delend(struct linklist* start){
    struct linklist* q = NULL;
    p = start;
    while(p->next != NULL){
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
}

void search(struct linklist* start, int x){
int index = 1;
p = start;
while(p->data != x && p->next != NULL){
    p  = p->next;
    index++;
}
if(p->data == x){
    cout << "found at node " << index << endl;
}else{
    cout << "no such value" << endl;
} }

void count(struct linklist* start){
int index = 1;
p = start;
while(p->next != NULL){
    p = p->next;
    index++;          
}
cout << "The number of nodes is: " << index<<endl;
}

int main(){
int choice, i=1,x;
while(i != 0){
cout << "Enter your choice: "<<endl;
cout << "1.Insertion at beginning"<<endl;
cout << "2.Insertion after a node" << endl;
cout << "3.Insertion at end" << endl;
cout << "4.Deletion at beginning"<<endl;
cout << "5.Deletion after a node"<<endl;
cout << "6.Deletion at end"<<endl;
cout << "7.Display" << endl;
cout << "8.Search" << endl;
cout << "9.Count nodes" << endl;
cin >> choice;
switch (choice)
{
case 1:

    cout << "Enter value to insert: " << endl;
    cin >> x;
    start = insbeg(start,x);
    break;

case 2:
    cout << "Enter value to insert: " << endl;
    cin >> x;
    cout << "Enter after which node you want to enter: "<<endl;
    int key;
    cin >> key;
    start = insafter(start,key,x);
    break;

case 3:

    cout << "Enter value to insert ";
    cin >> x;
    start = insend(start, x);
    break;

case 4:
    start = delbeg(start);
    break;

case 5:
    cout << "After which node to delete ";
    cin >> key;
    delafter(start, key);
    break;

case 6:
    delend(start);
break;

case 7:
display(start);
break;

case 8:
cout << "Enter the value to be search: ";
cin >> x;
search(start,x);
break;

case 9:
count(start);
break;

default:
cout << "Invalid choice";
    break;

}

cout << "Press zero for termination"<<endl;
cin >> i;
}
cout << "Terminated";
}