#include<iostream>
using namespace std; 

template <typename T>
class node{
    public:
    T data;
    node<T>* right;
    node<T>* left;
    node(T d){
        data=d;
        right=nullptr;
        left=nullptr;
    }
};


void printTree(node<int>* root){
   if(root==NULL){   /// base case
    return;
   }

   cout<<root->data<<": ";
   if(root->left!=NULL){
    cout<<"L"<<root->left->data;
   }

   if(root->right!=NULL){
    cout<<"R"<<root->right->data;
   }
   cout<<endl;

   printTree(root->left);
   printTree(root->right);
}
    bool hasData(node<int>* node, int data){
        if(node==NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }

        if(node->data > data){
            return hasData(node->left, data);
        }else{
           return hasData(node->right, data);
        }
    }

int main(){
    return 0;
}