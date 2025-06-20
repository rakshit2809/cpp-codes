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