#include <iostream>
using namespace std;

bool check (char str[] , int s , int e){
    if(s>e)
    return true;
    if(str[s]==str[e])
    return check(str,s+1,e-1); 
    else
    return false;
}
int main(){
    char str[]="abccba";
    cout<< check(str,0,5);
}