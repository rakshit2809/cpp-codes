#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class Node{
public:
T data;
vector <Node<T>*> ptr;
Node(T data){
    this->data=data;
}
};
void print_tree( Node<int>* Root){
        cout<<Root->data<<" ";
    for(Node<int>* x : Root->ptr){
        print_tree(x);
    }
}
    
int main(){ 
    Node<int>* root = new Node<int>(5);
    Node<int>* c1 = new Node<int>(3);
    Node<int>* c2 = new Node<int>(2);
    root->ptr.push_back(c1);
    root->ptr.push_back(c2);
    print_tree(root);
    return 0;
}