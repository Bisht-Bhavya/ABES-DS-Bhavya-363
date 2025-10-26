#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int value;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    while (true)
       {
        cin>>value;
        if(value == -1)
        break;
        v1.push_back(value);
    }
    while(true)
    {
        cin>>value;
        if(value == -1)
        break;
        v2.push_back(value);
    }
    int n,m,i=0,j=0;
    n = v1.size();
    m = v2.size();
    while(i<n && j<m)
    {
        if(v1[i] < v2[j]){
        v3.push_back(v1[i]);
            i++;
        }else{
        v3.push_back(v2[j]);
            j++;
        }
    }
    while (i < n) {
        v3.push_back(v1[i]);
        i++;
    }
    while (j < m) {
        v3.push_back(v2[j]);
        j++;
    }
    for(i=0 ; i < n ;i++){
    cout<<v1[i]<<" ";
 }
 cout<<"\n";
    for(j=0 ; j < m; j++){
     cout<<v2[j]<<" ";
    }
cout<<"\n";
    for(int x:v3){
        cout<<x<<" ";
    }
}