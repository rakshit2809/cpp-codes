#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
int * arr = new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int * ptr1 = arr;
int* ptr2 = arr+n-1;
while(ptr1<ptr2){
    while(*ptr1%2!=1){
        ptr1++;
    }
    while(*ptr2%2!=0){
        ptr2--;
    }
    if(ptr1<ptr2){
    swap(*ptr1,*ptr2);
    ptr1++;
    ptr2--;}
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
