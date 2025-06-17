#include <iostream>
using namespace std;

int last_idx(int arr[],int n, int key,int idx){
    if(idx==-1)
    return -1;
    if(arr[idx]==key)
    return idx;
    else
    return last_idx(arr,n,key,idx-1);
}

int main(){
    int arr[]={1,4,4,4,5};
    cout<<last_idx(arr,5,4,4)<<endl;
    return 0;
}