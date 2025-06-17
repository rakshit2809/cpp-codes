#include<iostream>
using namespace std;

int moore_voting(int arr[],int n){
int candidate = -1;
int votes = 0;

for(int i=0;i<n;i++){
     if(votes==0){
        candidate = arr[i];
        votes=1;
     }
    else if(arr[i]==candidate)
     votes++;
     else
     votes--;

}
int count =0;
for(int i=0;i<n;i++){
    if(arr[i]==candidate)
    count++;
}
if(count>=n/2)
return candidate;
return -1;
}

int main(){ 
    int arr[]={1,2,1,1,1,1,1,6,3};
    cout<<moore_voting(arr,9);
    return 0;
}