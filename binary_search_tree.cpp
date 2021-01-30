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
        int countLeafNodes(Node*);
        template <class T>
        std::vector<T> inOrder(Node* root)
        template <class T>
        Node* insertRecursive(Node* root, T key);
};

int binarySearchTree::countLeafNodes(Node* root){
    int count = 0;
    if (root == NULL){
        return count;
    }
    else if(root->left == NULL && root->right == NULL){
        return count + 1;
    }
    count += countLeafNodes(root->left);
    count +=countLeafNodes(root->right);
    return count;
}

void binarySearchTree::printLeafNodes(Node* root){
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
    curr = curr->left;
    while(curr !=NULL && curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

template <class T>
Node* binarySearchTree::deleteNode(Node* root, T key){
   if(root == NULL){
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
        if(root->right == NULL){
            temp = root->left;
            delete root;
            return temp;
        }
        else{
            temp = getSuccessor(root);
            root->key = temp->key;
            root->left = delNode(root->left,root->key);
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
	
	Node* root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=15;
	
	binarySearchTree* bst = new binarySearchTree();
}


/*

#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node* traverseLinkedList(Node* root){
    if(root == NULL){
        return root;
    }
    
    Node* temp = root;
    while(temp!=NULL){
        std::cout<<temp->data<<" --> ";
        temp = temp->next;
    }
    std::cout<<"N"<<"\n";
    return root;
}

template<class T>
Node* pushBack(Node* root, T key){
    
    if(root == NULL){
        return new Node(key);
    }
    
    Node* temp = root;
    Node* lastNode = new Node(key);
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = lastNode;
    temp = temp->next;
    return root;
}

template<class T>
Node* insertPosition(Node* root, int pos, T key){
    Node* temp = root;
    Node* new_node = new Node(key);
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count = count + 1;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return root;
}

template<class T>
Node* deleteNode(Node* root, T key){
    
}

int main() 
{ 
	Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->next=temp2;
	head = traverseLinkedList(head);
	head = pushBack(head, 40);
	head = insertPosition(head, 4,35);
	head = traverseLinkedList(head);
	return 0;
} 


*/