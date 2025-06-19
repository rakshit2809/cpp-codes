#include <iostream>
#include <queue>
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

void print_tree(node<int>* root){
if(!root) return;
cout<<root->data<<" ";
print_tree(root->left);
print_tree(root->right);
}

node<int>* take_input( ){
    int rootdata;
    cout<<"enter root data: ";
    cin>>rootdata;
    if(rootdata==-1)
    return nullptr;
    node<int>* root = new node<int>(rootdata);
    root->left = take_input();
    root->right = take_input();
    return root;
}

node<int>* take_input_levelwise( ){
    int rootdata;
    cout<<"enter root data: ";
    cin>>rootdata;
    node<int>* root = new node<int>(rootdata);

    queue <node<int>*> q; 
    q.push(root);
    while(!q.empty()){
    node<int>* f = q.front();
    q.pop();
    cout << "Enter left child of " << f->data << ": ";
    int leftd;
    cin>>leftd;
    if(leftd!=-1){
        node<int>* l = new node<int> (leftd);
        q.push(l);
        f->left=l;
    }
    cout << "Enter right child of " << f->data << ": ";
    int rightd;
    cin>>rightd;
    if(rightd!=-1){
        node<int>* r = new node<int> (rightd);
        q.push(r);
        f->right=r;
    }

    }
    return root;
    }

    void level_order_print(node<int>* root){
        if(!root) return;
    queue <node<int>*> q; 
    q.push(root);
    while(!q.empty()){
        node<int>* p = q.front();
        q.pop();
        cout << p->data << " ";
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }
    return;
    }
    
    void level_order_print_2(node<int>* root){
    if(!root) return;
    queue <node<int>*> q; 
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        node<int>* p = q.front();
        q.pop();
        if(!p){
            if(q.empty())
            q.push(nullptr);
            else
            cout<<endl;
        }
        cout << p->data << " ";
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }
    return;
    }

int main(){
node<int> * ptr = take_input_levelwise();
level_order_print_2(ptr);

    return 0;
}