    #include<iostream>
    using namespace std;
    int kth_smallest(int * arr1, int * arr2,int k){
        int i=0,j=0;
        int q;
        while(k--){
            if(arr1[i]<arr2[j]){
                q = arr1[i];
                i++;
            }
            else{
            q = arr2[j];
            j++;
            }
        }
        return q;
    }
    int main(){ 
        int A[] = {2, 3, 6, 7, 9};
        int B[] = {1, 4, 8, 10};
        int k = 5;

        cout << "Kth smallest element is: " << kth_smallest(A, B, k) << endl;

        return 0;
    }