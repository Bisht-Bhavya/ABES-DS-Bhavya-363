#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct linklist{
    int data;
    struct linklist* next;
};

struct linklist* head = NULL;
struct linklist* ptr;

void traversal(struct linklist* head){
ptr = head;
while( ptr != NULL ){
    cout<<ptr->data<<" ";
    ptr = ptr->next;
}
}

void insertion(){
    ptr = head;
   while(ptr!=NULL){
   ptr = ptr->next;
   }
    linklist* newnode = new linklist();
    cout<<"Enter value: ";
    cin>>newnode->data;
    newnode->next = NULL;  
} 

int main( ){
    int loop=1;
    struct linklist* s;
    head = s;
    while(loop!=0){
    cout <<"1. Traversal"<<endl;
    cout<<"2. Insertion"<<endl;
    int ch;
    cin>>ch;
     switch(ch){
         case 1:
         traversal(s);
          break;
 
         case 2:  
        insertion();
        break;
    }
    cout<<"Enter 0 for termination: "<<endl;
    cin>>loop;
}
}