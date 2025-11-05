#include <bits/stdc++.h>
using namespace std;
struct linklist{
    int data;
    struct linklist* next;
    struct linklist* prev;
};

struct linklist* start = NULL;
struct linklist* p;

struct linklist* getnode(){
    struct linklist* node = (struct linklist*) malloc (sizeof(struct linklist*));
    node->next = NULL;
    node->prev = NULL;
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
if(start == NULL){
    return node;
}
node->next = start;
node->prev = NULL;
start = node;
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
node->prev = p;
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
    node->prev = p;
    p->next->prev = node;
    p->next = node;
    return start;
}

struct linklist* insbef(struct linklist* start, int key, int x){
    struct linklist* node = getnode();
    node->data = x;
    p = start;
    if(start == NULL){
        return node;
    }
    while(p->data != key){
        p = p->next;
    }
    node->next = p;
    node->prev = p->prev;
    p->prev->next = node;
    p->prev = node;
    return start;
}

struct linklist* delbeg(struct linklist* start){
    p = start ;
    start = start->next;
    start->prev = NULL;
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

void delbef(struct linklist* start, int key){
    struct linklist* q = NULL;
    p = start;
    while(p->data != key){
     p = p->next;
    }
    q = p->prev;
    p->prev = p->prev->prev;
    p->prev->next = p;
    free(q);
}

void delend(struct linklist* start){
    struct linklist* q = NULL;
    p = start;
    while(p->next != NULL){
        q = p;
        p = p->next;
    }
    free(p);
    q->next = NULL;
}

int main(){
int choice,x;
do{
cout << "Enter your choice: "<<endl;
cout << "1.Insertion at beginning"<<endl;
cout << "2.Insertion after a node" << endl;
cout << "3.Insertion before a node"<<endl;
cout << "4.Insertion at end" << endl;
cout << "5.Deletion at beginning"<<endl;
cout << "6.Deletion after a node"<<endl;
cout << "7.Deletion before a node"<<endl;
cout << "8.Deletion at end"<<endl;
cout << "9.Display" << endl;
cout << "Press 0 for termination"<<endl;
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
    cout << "Enter value to insert: " << endl;
    cin >> x;
    cout << "Enter before which node you want to enter: "<<endl;
    cin >> key;
    start = insbef(start,key,x);
    break;

case 4:

    cout << "Enter value to insert ";
    cin >> x;
    start = insend(start, x);
    break;

case 5:
    start = delbeg(start);
    break;

case 6:
    cout << "After which node to delete ";
    cin >> key;
    delafter(start, key);
    break;
case 7:
    cout << "Before which node to delete ";
    cin >> key;
    delbef(start, key);
    break;

case 8:
    delend(start);
    break;

case 9:
    display(start);
    break;

case 0:
cout << "Terminated";
break;
default:
cout << "Invalid choice";
    break;
   
}
} while(choice != 0);
}