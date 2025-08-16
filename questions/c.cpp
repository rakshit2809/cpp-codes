    #include<iostream>
    #include<algorithm>
    using namespace std;
    int kth_smallest(int * arr,int k,int n){
    sort(arr, arr + n);
    return arr[k - 1];
    }
    int main(){ 
        int A[] = {2, 3, 6, 7, 9};
        int k = 5;

        cout << "Kth smallest element is: " << kth_smallest(A,k,5) << endl;

        return 0;
    }