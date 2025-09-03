#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
int i;
    vector<int>v;
//cout<<"Size of vector : "<<v.size()<<endl;
//cout<<"Capacity of vector : "<<v.capacity()<<endl;

v.push_back(1);
//cout<<"Size of vector : "<<v.size()<<endl;
//cout<<"Capacity of vector : "<<v.capacity()<<endl;

v.push_back(3);
//cout<<"Size of vector : "<<v.size()<<endl;
//cout<<"Capacity of vector : "<<v.capacity()<<endl;

v.push_back(6);
//cout<<"Size of vector : "<<v.size()<<endl;
//cout<<"Capacity of vector : "<<v.capacity()<<endl;

v.push_back(8);
//cout<<"Size of vector : "<<v.size()<<endl;
//cout<<"Capacity of vector : "<<v.capacity()<<endl;

v.push_back(9);
//cout<<"Size of vector : "<<v.size()<<endl;
//cout<<"Capacity of vector : "<<v.capacity()<<endl;

for(i=0;i<v.size();i++)
    //cout<<v[i]<<" ";
    cout<<v.at(i)<<" ";
    cout<<endl;

for(auto value:v)
 cout<<value<<" ";
 cout<<endl; 

 //Poping the element
v.pop_back();
for(auto value:v)
cout<<value<<" ";
cout<<endl;
cout<<"front: "<<v.front()<<" "<<"Last: "<<v.back()<<endl;

//Insertion and deletion in vector
v.insert(v.begin(),2);
for(auto value:v)
cout<<value<<" ";
cout<<endl;

v.insert(v.begin()+2,10);
for(auto value:v)
cout<<value<<" ";
cout<<endl;

v.insert(v.begin()+4,3,11);
for(auto value:v)
cout<<value<<" ";
cout<<endl;

v.erase(v.begin());
for(auto value:v)
cout<<value<<" ";
cout<<endl;

v.erase(v.begin()+3,v.begin()+6);
for(auto value:v)
cout<<value<<" ";
cout<<endl;

//vector<int>v1(2,4,5,6,)
vector<int>v1={1,2,3,4,5,6,7,8};
for(auto value:v1)
cout<<value<<" ";
cout<<endl;

vector<int>::iterator itr;
for(auto itr=v.begin();itr!=v.end();itr++)
cout<<*(itr)<<" ";
cout<<endl;

vector<int>::reverse_iterator rit;
for(auto rit=v.rbegin();rit!=v.rend();rit++)
cout<<*(rit)<<" ";
cout<<endl;

}