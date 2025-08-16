#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int first_missing(vector<int> & v){
    int sum = accumulate(v.begin(), v.end(), 0);
    int n = v.size()+1;
    int csum = (n)*(n+1)/2;
    return csum-sum;
    }
int main() {
    vector<int> arr = {1,2,3,5};
    cout<<"Missing Integer is "<<first_missing(arr);
    return 0;
}
