#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
int n,m,x,i;
set<int>set1,set2,uni;
cout<<"Enter the size of set A: ";
cin >> n;
cout<<"Enter the size of set B: ";
cin >> m;
cout << "Enter the elements of set A: ";
for(i=0;i<n;i++){
    cin >> x;
    set1.insert(x);
}
cout << "Enter the elements of set B: ";
for(i=0;i<m;i++){
    cin >> x;
    set2.insert(x);
}
uni=set1;
uni.insert(set2.begin(),set2.end());
cout << "First set: ";
    for (int val : set1) cout << val << " ";
    cout << "\n";

    cout << "Second set: ";
    for (int val : set2) cout << val << " ";
    cout << "\n";

    cout << "Union: ";
    for (int val : uni) cout << val << " ";
    cout << "\n";
}