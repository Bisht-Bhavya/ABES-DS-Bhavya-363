#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
int a,n,mid;
cout<<"Enter the array size:";
cin>>n;
int v[n];
cout<<"Enter the array elements:";
for(int i = 0 ;i < n ; i++){
    cin>>v[i];
}
cout<<"Enter the element to be found: ";
cin>>a;
int min = 0;
int max = n;
for(int i = 0; i < n; i++){
    mid = (min + max) / 2;
if(v[mid] < a){
    min = mid;
}
if(v[mid] > a){
    max = mid;
}
if(v[mid]==a){
cout<<"Found";
exit(0);
}
}
cout<<"Not Found";
}