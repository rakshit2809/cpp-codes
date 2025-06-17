#include <iostream>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min = INT_MAX;
        int idx=-1;
        for(int j=i;j<n;j++){
            if(min>arr[j]){
                min=arr[j];
                idx=j;
            }
        }
        swap(arr[i],arr[idx]);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    for(auto x : arr){
        cout<< x << " ";
    }
}