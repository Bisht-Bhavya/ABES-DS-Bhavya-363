#include<iostream>
using namespace std;
#define MAX 10
int top = -1;
int stack[MAX];

void push(int decimal){
    if(top == MAX-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        stack[++top] = decimal;
    }
}

void pop(){
    if( top == -1){
        cout<<"Stack underflow"<<endl;
    }
    else{
        return stack[top--];
    }
} 

int main(){
    cout<<"Enter number: ";
    int n, rem, num, dec = 0,power =1;
    cin>>n;
    while( num > 0){
        rem= rem % 10;
        num = num / 10;
    dec += rem * power;
    power = power * 2;
    push(dec);
    }
}