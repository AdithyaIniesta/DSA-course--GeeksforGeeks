#include <bits/stdc++.h>

class Node{
    public:
    struct Node* left;
    struct Node* right;
    int value;
    Node(int key){
        value = key;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        template<class T>
        Node* insert(Node* root,T key);
        void printTree(Node* root);
        int findMinimumDifference(Node* root, int key);
        int absoluteDifference(int x, int y);
};

BinarySearchTree::BinarySearchTree(){

}

BinarySearchTree::~BinarySearchTree(){
    std::cout<<"Deleted the binary search tree\n";
}

template<class T>
Node* BinarySearchTree::insert(Node* root,T key){
    if(root == NULL){
        return new Node(key);
    }

    else if(root->value < key){
        root->right = insert(root->right, key);
    }

    else if(root->value > key){
        root->left = insert(root->left, key);
    }
    return root;
}

int BinarySearchTree::absoluteDifference(int x, int y){
    if(x >= y){
        return x - y;
    }
    else{
        return y - x;
    }
}

int BinarySearchTree::findMinimumDifference(Node* root, int key){
    if(root == NULL){
        return INT_MAX;
    }
    if(root->value == key){
        return 0;
    }
    
    int diff;
    
    if(root->value > key){
        diff = findMinimumDifference(root->left, key);
        diff = std::min(diff, absoluteDifference(root->value, key));
        return diff;
    }
    
    if(root->value < key){
        diff = findMinimumDifference(root->right, key);
        diff = std::min(diff, absoluteDifference(root->value, key));
        return diff;
    }
}

void BinarySearchTree::printTree(Node* root){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    std::cout<<root->value;
    printTree(root->right);
}

int main(){
    std::vector<int> v{4,2,5,1,3};
    BinarySearchTree* BST = new BinarySearchTree();
    Node* parent = NULL;
    for (int x : v) {
        parent = BST->insert(parent, x);
    }
    BST->printTree(parent);
    std::cout<<"\nMinimum Difference\n";
    std::cout<<BST->findMinimumDifference(parent, 6);
    return 0;
}
