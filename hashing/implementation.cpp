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
    }363.
    
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

        void rehash(){
            node<t>** temp = buckets;
            buckets = new node<t>* [2*numbucket];
            for(int i=0;i<2*numbucket;i++){
                buckets[i]=nullptr;
            }
            int oldsize = numbucket;
            numbucket *=2;
            count = 0;
            
            for(int i=0; i<oldsize;i++){
                node<t>* head = temp[i];
                while(head){
                    string a = head->key;
                    t b = head->value;
                    insert(a,b);
                    head=head->next;
                }

            }
            for(int i=0;i<oldsize;i++){
                delete temp[i];
            }
            delete [] temp;
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
        return t();

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

        double loadfactor = (double)count/numbucket;
        if(loadfactor>0.7){
            rehash();
        }

    }

    t remove (string key){

        int bucketindex = getbucketindex(key);
        node<t> * head = buckets[bucketindex];
        node<t> * prev = nullptr;
        while(head){
            if(head->key==key){
                if(prev==nullptr)
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
            return t(); // signifies the given key isnt present.  
        }

        double getloadfactor(){
            return (1.0*count)/numbucket;
        }

    };

int main(){ 
    mymap<int> ourmap;
    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        ourmap.insert(key,value);
        cout<<ourmap.getloadfactor()<<endl;
    }
    cout<<ourmap.size()<<endl;

    ourmap.remove("abc1");
    ourmap.remove("abc6");

    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout<<key<<" "<<ourmap.getvalue(key)<<endl;
    }
     cout<<ourmap.size()<<endl;
  return 0;

}