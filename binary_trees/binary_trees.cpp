#include <iostream>
#include <queue>
#include <climits>
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
            cout<<endl;
            if(!q.empty())
            q.push(nullptr);
        
        }
        else{
        cout << p->data << " ";
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }}
    return;
    }

    bool searchNode(node<int>* root, int key){
   if(root==NULL){
    return false;
   }
   if(root->data == key){
    return true;
   }

   return (searchNode(root->left,key) || searchNode(root->right,key));
}

    bool helper(node<int>* left1, node<int>* right1){
        if(!left1 && !right1)
        return true;
        else if (!left1||!right1)
        return false;
        if(left1->data!=right1->data)
        return false;
        return helper(left1->left,right1->right) && helper(left1->right,right1->left);
    }

    bool issymmetric(node<int>* root){
        if(!root)
        return true;
        
        return helper(root->left,root->right);

    }

    int height(node<int>* root){
        if(!root->left && !root->right){
            return 1;
        }
        if(!root)
        return 0;
        return max(height(root->left),height(root->right))+1;
    }

int minValue(node<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);

    return min(root->data, min(leftMin,rightMin));
}

void minValueOtherWay(node<int>* root,int &ans){
    if(root==NULL){
        return;
    }
    ans = min(ans,root->data);
    minValueOtherWay(root->left,ans);
    minValueOtherWay(root->right,ans);
}

int maxValue(node<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);

    return max(root->data, max(leftMax,rightMax));
}

void maxValueOtherWay(node<int>* root,int &ans){
    if(root==NULL){
        return;
    }
    ans = max(ans,root->data);
    maxValueOtherWay(root->left,ans);
    maxValueOtherWay(root->right,ans);
}

int countLeafNode(node<int>* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }

    return countLeafNode(root->left) + countLeafNode(root->right);
}

void countLeafNodeOtherWay(node<int>* root,int &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans++;
        return; 
    }
    countLeafNodeOtherWay(root->left,ans);
    countLeafNodeOtherWay(root->right,ans);
}

int diameter(node<int>* root){
    if(!root) return 0;
    return max(max(diameter(root->left),diameter(root->right)),height(root->left)+height(root->right));
}

    bool getpath(node<int>* root, int key, vector<int> &v){
        if(!root)
        return false;
        if(root->data==key){
            v.insert(v.begin(), root->data);
            return true;
        if(getpath(root->left,key,v)||getpath(root->right,key,v)){
            v.insert(v.begin(), root->data);
            return true;
        }
        }
    }

int main() {
   /*node<int>* ptr = take_input_levelwise();

    cout << "\n--- Level Order with Line Breaks ---\n";
    level_order_print_2(ptr);

    cout << "\n--- Flat Level Order (Single Line) ---\n";
    level_order_print(ptr);

    cout << endl;
    return 0;*/ 
}
