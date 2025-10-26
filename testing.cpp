#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    vector<int> v1 = {1,2,3,4,5,6};
    vector<int> v2 = {7,8,9,10,11};
    vector<int> v3(v1.size() + v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for(int value:v3){
        cout<<value<<" ";
    }
   }
