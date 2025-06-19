#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class Node{
public:
T data;
vector <Node<T>*> ptr;
Node(T data){
    this->data=data;
}
~Node{
    for(Node<T>* p:ptr){
        delete p;
    }

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
Node<int> * root = new Node<int>(d);
int n;
cout<<"enter no of childrens of data entered: ";
cin>>n;
for(int i=0;i<n;i++){
    Node<int>* child = take_input();
    root->ptr.push_back(child);
}
return root;
}

Node<int>* take_input_level_wise(){
    int rootdata;
    cout<<"enter rootdata: ";
    cin>>rootdata;
    Node<int>* rootnode = new Node<int>(rootdata);
    queue <Node<int>*> q;
    q.push(rootnode);
    while(!q.empty()){
        Node<int>* front = q.front();
        q.pop();
        int n;
        cout<<"enter no of childeren of "<<front->data<<" :";
        cin>>n;
        for(int i=0;i<n;i++){
            int childdata;
            cout<<"enter "<<i<<"th child data: ";
            cin>>childdata;
            Node<int>* childnode = new Node<int>(childdata);
            q.push(childnode);
            front->ptr.push_back(childnode);
        }
    }
    return rootnode;
}

void level_order_print(Node<int>* root){
    queue<Node<int>*>q;
    q.push(root);
    while(!q.empty()){
        Node<int>* p = q.front();
        cout<<p->data<<":";
        q.pop();
        while(!p->ptr.empty()){
            q.push(p->ptr.front());
            Node<int>* s = (p->ptr).front();
            cout<<s->data<<" ";
        p->ptr.erase(p->ptr.begin()); 
        }
        cout<<endl;
    }
    
}

int count_nodes(Node<int>* root){
    if(!root)
    return 0;
int ans = 1;
for(int i=0;i<(root->ptr).size();i++){
    ans += count_nodes(root->ptr[i]);
}
return ans;
}

int height(Node<int>* root){
    int max = 0;
    for(Node<int>* p : root->ptr){
        int childheight = height(p);
        if(childheight>max)
        max = childheight;
    }
    return max+1;
}

void printatlevelk(Node<int>* root, int k){
    if(!root){
        return;
    }   
    if(k==0){
    cout<<root->data<<" ";
    return;}
    for(Node<int>* p : root->ptr){
        printatlevelk(p,k-1);
    }
return;
}

int leafnodes(Node<int>* root){
    if((root->ptr).size()==0)
    return 1;
    int ans=0;
    for(Node<int>* p : root->ptr){
        ans += leafnodes(p);
    }
    return ans;
}

void pre_order_traversal(Node<int>* root){
    cout<<root->data<<" ";
    for(Node<int>* p : root->ptr){
        pre_order_traversal(p);
    }
    return;
}
void post_order_traversal(Node<int>* root){
    for(Node<int>* p : root->ptr){
        post_order_traversal(p);
    }
    cout<<root->data<<" ";
    return;
}

void delete_tree(Node<int>* root){
    if(!root)
    return;
    for(Node<int>* p : root->ptr){
        delete_tree(p);
    }
    delete root;
    return;
}


int main(){ 
    Node<int>* root = new Node<int>(5);
    Node<int>* c1 = new Node<int>(3);
    Node<int>* c2 = new Node<int>(2);
    root->ptr.push_back(c1);
    root->ptr.push_back(c2);
    cout << height(root) << endl;
    return 0;
}