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
    if(Root==nullptr)
    return;
    cout<<Root->data<<" ";
    for(Node<int>* x : Root->ptr){
        print_tree(x);
    }
}

Node<int>* take_input( ){
int d;
cout<<"enter data: ";
cin>>d;
Node * root = new Node<int>(d);
int n;
cout<<"enter no of childrens of data entered: ";
cin>>n;
for(int i=0;i<n;i++){
    Node<int>* child = take_input();
    root->ptr.push_back(child);
}
return root;
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