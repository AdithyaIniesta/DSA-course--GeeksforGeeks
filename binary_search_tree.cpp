#include <bits/stdc++.h>

struct Node{
    int value;
    struct Node* left;
    struct Node* right;

    Node(int key){
        value = key;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }
    else{
        if(root->value == key){
            return root;
        }
        else if(root->value > key){
            root->left = insert(root->left, key);
        }
        else{
            root->right = insert(root->right, key);
        }
    }
}

Node* constructBST(Node* root, std::vector<int> T){
    std::vector<int>::iterator it;
    for (it = T.begin(); it != T.end() ; it++){
        root = insert(root, it);
    }
    return root;
}

std::vector<int> inOrder(Node* root){
    std::vector<int> v1;
    if (root == NULL){
        return v1;
    }
    else{
        std::vector<int> v2;
        v2 = inOrder(root->left);
        v1.insert(v1.end(), v2.begin(), v2.begin());
        v1.push_back(root->value);
        v2 = inOrder(root->right);
        v1.insert(v1.end(), v2.start(), v2.end());
        return v1;
    }
}

std::vector<int> mergeTwoBST(Node* root1, Node* root2){
    if(root1 == NULL && root2 !=  NULL){
        return inOrder(root2);
    }
    else if(root1 != NULL && root2 ==  NULL){
        return inOrder(root1);
    }
    else{
        std::vector<int> v1 = inOrder(root1);
        std::vector<int> v2 = inOrder(root2);
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(), v1.end());
        return v1;
    }
}

void printVector(std::vector<int> v){
    std::vector<int>::iterator it;
    for(it = v.begin();it != v.end(); it++){
        std::cout << *it <<"\t";
    }
    std::cout<<"\n";
}


int main(){
    std::vector<int> v1{1,2,5,3,6,4};
    std::vector<int> v2{9,5,6,4,2,10,15};
    std::vector<int> v3;

    Node* root_of_bst1, root_of_bst2;
    root_of_bst1 = constructBST(root_of_bst1, v1);
    root_of_bst2 = constructBST(root_of_bst1, v2);
    v3 = mergeTwoBST(root_of_bst1, root_of_bst2);
    printVector(v3);
    return 0;
}