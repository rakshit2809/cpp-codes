#include<iostream>
using namespace std;

class stack{
    public:
    int arr[100];
    int n=0;
    void push(int val){
        if(n==100){
            cout<<"error"<<endl;
            return;
        } 
        arr[n] = val;
        n++;
    }
    void pop(){
        if(n==0){
            cout<<"error"<<endl;
            return;
        }
        n--;
    }
    int top(){
        return arr[n-1];
    }
    bool isempty(){
        return n==0;
    }
    int size(){
        return n;
    }
};