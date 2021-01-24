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
    private:
        
    public:
        bool searchIterative(Node* root, int key);
        bool searchRecursive(Node* root, int key);
        Node* replaceNode(Node* root);
        template <class T>
        Node* binarySearchTree::deleteNode(Node* root, T key);
        Node* insertIterative(Node* root, int key);
        Node* insertRecursive(Node* root, int key);
};

Node* binarySearchTree::replaceNode(Node* root){
    Node* curr = root->left;
    while(curr!=NULL){
        root = curr;
        curr = curr->right;
    }
    return root;
}

template <class T>
Node* binarySearchTree::deleteNode(Node* root, T key){
    if(root== NULL){
        return root;
    }
    else if(root->value > key){
        deleteNode(root->left, key);
    }
    else if(root->value < key){
        deleteNode(root->right, key);
    }
    else{
        Node* temp;
        if (root->left == NULL){
            temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            temp = root->left;
            delete root;
            return temp;
        }
        else{
            temp = replaceNode(root);
            root->value = temp->value;
            root->left = deleteNode(root->left, temp->value);
            return root;
        }
    }
}

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