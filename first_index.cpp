#include <iostream>
using namespace std;

int first_idx(int arr[],int n, int key,int idx){
    if(idx==n)
    return -1;
    if(arr[idx]==key)
    return idx;
    else
    return first_idx(arr,n,key,idx+1);
}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<first_idx(arr,5,4,0)<<endl;
    return 0;
}