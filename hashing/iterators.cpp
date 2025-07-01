#include <iostream>
#include <string>
#include <unordered_map>
#include<map>
using namespace std;

int main(){

    unordered_map<string,int> m;

    m["a"]=1;
    m["b"]=2;
    m["c"]=3;
    m["d"]=4;
    m["e"]=5;
    m["f"]=6;
// iterator can be seen as  pointer of a pair class object 

    for(unordered_map<string,int>:: iterator it = m.begin();it!=m.end();it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }

map<string,int> ma;

    ma["a"]=1;
    ma["b"]=2;
    ma["c"]=3;
    ma["d"]=4;
    ma["e"]=5;
    ma["f"]=6;

    for(map<string,int>:: iterator it = ma.begin();it!=ma.end();it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }

    return 0;
}