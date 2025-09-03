#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int main(){
 int n,i;
 int ar[5];
 cout<<"Enter the elements: ";
 for(i=0;i<5;i++){
  cin>>ar[i];
 }
cout<<"Enter the element to be found: ";
cin>>n;
for(i=0;i<5;i++){
    if(ar[i]==n){
        cout<<"Element found";
        exit(0);
    }
}
cout<<"Element not found";
}