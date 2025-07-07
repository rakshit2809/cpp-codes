#include <iostream>
#include <vector>
using namespace std;

class heap{
public:
    vector <int> v;

    heap(int dsize = 10){
        v.reserve(dsize+1);
        v.push_back(-1);
        }

    void push(int data){
        v.push_back(data);// push data to end of heap
        int idx = v.size()-1;
        int parent = idx/2;
        while(idx>1 && v[parent]<v[idx]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent/=2;
        }
    }    

    int top(){
    return v[1];}

    void heapify(int i){
        int left = 2*i;
        int right = 1+(2*i);
        int min_idx = i;
        if(left < v.size() && v[left]<v[i]){
            min_idx=left;
        }
        if(right < v.size() && v[right]<v[i]){
            min_idx=right;
        }
        if(min_idx!=i){
            swap(v[i],v[min_idx]);
            heapify(min_idx);
        }
        return;
    }

    bool empty(){
        return v.size()==1;
    }

    void remove_min(){
            swap(v[1],v[v.size()-1]);
            v.pop_back();
            heapify(1);
    }
};

int main(){

    return 0;
}