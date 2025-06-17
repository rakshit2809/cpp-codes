#include<iostream>
using namespace std;

bool issorted(int arr[], int n){
    if(n==0||n==1){
        return true;
    }
    if(arr[0]>arr[1])
    return false;
    return issorted(arr+1,n-1);
}
    
int main(){
    int arr[]={1,2,7,4,5};
    cout<<issorted(arr,5);
}