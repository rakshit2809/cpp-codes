#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> *vp = new vector<int>(); 
    vector<int> v;   

    vector<int> v2(10,-2);   
    vector<int> v3(100); 
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }
       for(int i=0;i<100;i++){
            cout<<"Capacity "<<v.capacity()<<endl;
            cout<<"Size "<<v.size()<<endl;

        v.push_back(i+1);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

   return 0;
}
