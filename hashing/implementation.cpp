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
    ~node(){
        delete next;
    }
};
template <typename t>
class mymap{
public:
    node<t> ** buckets;
    int count;
    int numbucket;
    mymap(){
        count=0;
        numbucket=5;
        buckets = new node<t>*[numbucket];
        for(int i=0;i<numbucket;i++){
            buckets[i]=nullptr;
        }}

        int getbucketindex(string key){
            int hashcode = 0;
            int base = 1;
            int p = 37;
            for(int i = key.size()-1;i>=0;i--){   
                hashcode += key[i]*base;
                base = base * p;
                hashcode = hashcode%numbucket;
                base = base%numbucket;
            }
            return hashcode%numbucket;
        }

        ~mymap(){
            for(int i=0;i<numbucket;i++){
                delete buckets[i];
            }
            delete []buckets    ;
        }
    
    int size(){
        return count;
    }

    t getvalue(string k){
        int bucketindex = getbucketindex(k);
        node<t> * head = buckets[bucketindex];
        while(head){
            if(head->key==k){
                return head->value;
            }
            head=head->next;
        }
        return 0;

    }
    
    void insert (string k, t val){

        int bucketindex = getbucketindex(k);

        node<t> * head = buckets[bucketindex];
        while (head!=nullptr){
            if(head->key == k){
            head->value = val;
            return;}
            head = head->next;

        }
        node<t>* n  =  new node<t> (k,val); 
        n->next=buckets[bucketindex];
        buckets[bucketindex]=n;
        count++;
    }

    t remove (string key){

        int bucketindex = getbucketindex(key);
        node<t> * head = buckets[bucketindex];
        node<t> * prev = nullptr;
        while(head){
            if(head->key==key){
                if(prev)
                buckets[bucketindex]=head->next;
                else
                prev->next = head->next;
            }
            t V = head->value;
            head->next=nullptr;
            delete head;
            count--;
            return V;
            }
            return 0; // signifies the given key isnt present.  
        }

    };

int main(){ 
    return 0;
}