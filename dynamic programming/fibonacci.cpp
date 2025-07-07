#include<iostream>
using namespace std;

int fib(int n){
    if(n==0||n==1) return n;
    else return fib(n-1)+fib(n-2);
}

int fib2(int n, int * dp){
    if(n==0 || n==1){
        return n;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    int output = fib2(n-1,dp) + fib2(n-2,dp);
    dp[n] = output;   /// store for future use
    return output;
}

int fib3(int n){

    int * dp = new int [n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    int out = dp[n];
    delete [] dp;
    return out;

}

int main(){
   int n;
   cin>>n;

   int *arr = new int[n+1];
   for(int i=0;i<=n;i++){
    arr[i] = 0;     /// Initialise with any invalid value like -2,-10..
   }
   cout<<fib3(n)<<endl;
   cout<<fib2(n,arr)<<endl;
   cout<<fib(n)<<endl;

   delete []arr;    /// do not forget to delete array

    return 0;
}