#include<iostream>
#include<climits>
using namespace std;
void bubble_sort(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
            swap(arr[i],arr[j]);
        }
    }
}
void selection_sort(int * arr, int n){
for(int i=0;i<n-1;i++){
    int miniidx=i;
    for(int j=i;j<n;j++){
        if(arr[miniidx]>arr[j])
            miniidx=j;
    }
    swap(arr[i],arr[miniidx]);
}
}
void insertion_sort(int * arr, int n){
for(int i =1;i<n;i++){
    int key = arr[i];
    int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        }
}

void merge_array(int *arr, int l, int r, int mid){
int a = l;
int b = mid+1;
int * ptr = new int[r-l+1];
int i=0;
while(a<=mid && b<=r){
    if(arr[a]<arr[b]){
        ptr[i++]=arr[a++];
    }
    else{
        ptr[i++]=arr[b++];
    }
}
while(b<=r){
        ptr[i++]=arr[b++];
}
while(a<=mid){
        ptr[i++]=arr[a++];

}
    for (int j = 0; j <= r - l; j++) {
        arr[l + j] = ptr[j];
    }
    delete [] ptr;
    }

void merge_sort(int *arr, int left, int right){
    if(left>=right) return;
    else{
        int mid = left + (right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge_array(arr,left, right, mid);
    }
}

int partition(int * arr, int l , int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j = l;j<=r-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);

    return i+1;

}

void quicksort(int * arr, int l, int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

int main(){
    int arr[] = {8, 6, 4, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }return 0;
}
