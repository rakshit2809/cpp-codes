#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> &v, int sv){
cout<<sv<<endl;
int n = v.size();
for(int i=0;i<n;i++){
    if(v[sv][i]==1){
        print(v,i);
    }
}
}

int main(){ 

    int n,e;
    cin>>n>>e;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<=e;i++){
        int fv,sv;
        cin>>fv>>sv;
        matrix[fv][sv]=1;
        matrix[sv][fv]=1;
    }

    print(matrix,0);
    return 0;
}