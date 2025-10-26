#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct linkedlist{
    int data;
    linkedlist* next;
};
int main(){
    linkedlist* head=NULL;
    int choice, ch, loop=1;
    while(loop!=false){
cout<<"Enter your choice: "<<endl;
cout<<"1. Traversal"<<endl;
cout<<"2. Insertion"<<endl;
cout<<"3. Deletion"<<endl;
cin>>choice;
switch(choice){
    case 1: 
    { 
        linkedlist* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
        break;
    }

    case 2:{
       cout<<"1.Enter at beginning"<<endl;
       cout<<"2.Enter between"<<endl;
       cout<<"3.Enter at end"<<endl;
         cin>>ch;
         linkedlist* newnode = new linkedlist();
       switch(ch){
        case 1:{
            cout<<"Enter data: ";
            cin>>newnode->data;
            newnode->next=head;
            head=newnode;
            break;
        }

        case 2:{
            cout<<"Enter data: ";
            cin>>newnode->data;
            int pos;
            cout<<"Enter position: ";
            cin>>pos;
            linkedlist* ptr=head;
            for(int i=0;i<pos-1;i++){
                ptr=ptr->next;
            }
            newnode->next=ptr->next;
            ptr->next=newnode;
            break;
        }

        case 3:{
            cout<<"Enter data: ";
            cin>>newnode->data;
            linkedlist* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            break;
        }
        default:{
            cout<<"Invalid choice"<<endl;
            break;
        }
       }
       break;
    }

    case 3:{
        cout<<"1.Delete at beginning"<<endl;
        cout<<"2.Delete between"<<endl;
        cout<<"3.Delete at end"<<endl;
        cin>>ch;
        switch(ch){
            case 1:{
                linkedlist* ptr=head;
                head=head->next;
                delete ptr;
                break;
            }

            case 2:{
                int pos;
                cout<<"Enter position: ";
                cin>>pos;
                linkedlist* ptr=head;
                for(int i=0;i<pos-1;i++){
                    ptr=ptr->next;
                }
                linkedlist* ptr2=ptr->next;
                ptr->next=ptr2->next;
                delete ptr2;
                break;
            }

            case 3:{
                linkedlist* ptr=head;
                while(ptr->next->next!=NULL){
                    ptr=ptr->next;
                }
                linkedlist* ptr2=ptr->next;
                ptr->next=NULL;
                delete ptr2;
                break;
            }

            default:{
                cout<<"Invalid choice"<<endl;
                break;
            }
        }
        break;
    }
}
cout<<"press 0 to terminate"<<endl;
cin>>loop;
}
}