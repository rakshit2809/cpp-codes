#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=0;i<n;i++){    
        bool flag=false;
        for(int j=i;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
                flag=true;}
        }
        if(!flag){
            break;}

    }
    return;
}

int main(){

    int arr[]={1,10,5,3,12};
    int arr3[]={1,2,3,4,5};
    bubble_sort(arr,5);
    bubble_sort(arr3,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    
}