#include <bits/stdc++.h>

template<class T>
class Node{
    public:
        int value;
        struct Node* left;
        struct Node* right;
        
        Node(T value){
            value = value;
            left = NULL;
            right = NULL;
        }
};

class binarySearchTree{
    private:
        
    public:
        template <class T>
        bool searchIterative(Node* root, T key);
        template <class T>
        bool searchRecursive(Node* root, T key);
        Node* replaceNode(Node* root);
        void binarySearchTree::inOrder(Node* root);
        void binarySearchTree::preOrder(Node* root);
        void binarySearchTree::postOrder(Node* root);
        void printLeafNodes(Node* root);
        template <class T>
        Node* binarySearchTree::deleteNode(Node* root, T key);
        template <class T>
        std::vector<T> inOrder(Node* root)
        template <class T>
        Node* insertRecursive(Node* root, T key);
};

void printLeafNodes(Node* root){
    if (root == NULL){
        return;
    }
    else if(root->left ==NULL && root->right){
        std::cout<< root->value <<"\t";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void binarySearchTree::inOrder(Node* root){
    if(root ==  NULL){
        return root;
    }
    inOrder(root->left);
    std::cout << root->value <<"\t";
    inOrder(root->right);
}

void binarySearchTree::preOrder(Node* root){
    if(root == NULL){
        return root;
    }
    std::cout<<root->value<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}

void binarySearchTree::postOrder(Node* root){
    if(root == NULL){
        return root;
    }
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->value << "\t";
}

template <class T>
std::vector<T> inOrder(Node* root){
    std::vector<T> v1, v2;
    if(root == NULL){
        return v1;
    }
    v2 = inOrder(root->left);
    v1.insert(v1.end(), v2.begin(), v2.end());
    v2 = inOrder(root->right);
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

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
template <class T>
bool binarySearchTree::searchIterative(Node* root, T key){
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
template <class T>
bool binarySearchTree::searchRecursive(Node* root, T key){
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
template <class T>
Node* binarySearchTree::insertRecursive(Node* root, T key){
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
}