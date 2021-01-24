#include <bits/stdc++.h>

class Node{
    public:
        int value;
        struct Node* left;
        struct Node* right;
        
        Node(int value){
            value = value;
            left = NULL;
            right = NULL;
        }
};

class binarySearchTree{
  public:
    bool searchIterative(Node* root, int key);
    bool searchRecursive(Node* root, int key);
    
    Node* insertIterative(Node* root, int key);
    Node* insertRecursive(Node* root, int key);
};

// search operation iterative method
bool binarySearchTree::searchIterative(Node* root, int key){
    while(root!=NULL){
        std::cout << root->value;
        if(root->value == key){
            return true;
        }
        else if(root->value > key){
            root = root->left;
        }
        else if(root->value < key){
            root = root->right;
        }
    }
    return false;
}

// serach operation recursive method
bool binarySearchTree::searchRecursive(Node* root, int key){
    if(root!=NULL){
        return false;
    }
    else{
        if(root->value == key){
            return true;
        }
        else if(root->value > key){
            searchRecursive(root->left, key);
        }
        else{
            searchRecursive(root->right, key);
        }
    }
}

Node* getSuccessor(Node *curr){
    Node* next = curr->left;
    while(next!=NULL){
        curr = next;
        next = next->right;
    }
    return curr;
}

Node *delNode(Node *root, int x){
    if(root==NULL){
        return root;
    }
    else if(root->key < x){
        root->right = delNode(root->right, x);
    }
    else if(root->key > x){
        root->left = delNode(root->left, x);
    }
    else{
        Node* temp;
        if(root->left == NULL){
            temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            temp = root->left;
            delete root;
            return temp;
        }
        else{
            temp = getSuccessor(root);
            root->key = temp->key;
            root->right = delNode(root->right, root->key);
            return root;
        }
    }
} 



// insert operation recursive
Node* binarySearchTree::insertRecursive(Node* root, int key){
    if(root == NULL){
        root = new Node(key);
    }
    else{
        if(root->value == key){
            return;
        }
        else if(root>value > key){
            root->left = insertRecursive(root, key);
        }
        else{
            root->right = insertRecursive(root, key);
        }
    }
    return root;
}

int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=15;
	
	binarySearchTree* bst = new binarySearchTree();
	
	if(bst->searchRecursive(root,x))
	    std::cout<<"Found";
	else
	    std::cout<<"Not Found";
}