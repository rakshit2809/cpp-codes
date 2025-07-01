#include<iostream>
#include <string>
using namespace std;
template <typename t>
class node{
public:
    string key;
    t value;
    node * next;
    node(string k, t val){
        key = k;
        value = val;
        next = nullptr;
    }
    ~node{
        delete next;
    }
};

class mymap{
public:
    node<t> * bucketarray;
    int count;
    int numbucket;
    mymap(){
        count=0;
        numbucket=5;
        bucketarray = new node<t>[numbucket];
        for(int i=0;i<numbucket;i++){
            bucketarray[i]=nullptr;
        }}

        int getbucketindex(){
            int hashcode = 0;
            int base = 1;
            int p = 37
            for(int i = key.size(),i>=0;i--){
                hashcode += key[i]*base;
                base = base * p;
                hashcode = hashcode%numbucket;
                base = base%numbucket;
            }
            return hashcode%numbucket;
        }

        ~mymap{
            for(int i=0;i<numbucket;i++){
                delete bucketarray[i];
            }
            delete []bucketarray;
        }
    
    int size{
        return count;
    }

    t getvalue(string k){

    }
    
    void insert (string k, t val){

        int bucketindex = getbucketindex(key);
        
    }

    t remove (string key){

    }

    };

int main(){ 
    return 0;
}