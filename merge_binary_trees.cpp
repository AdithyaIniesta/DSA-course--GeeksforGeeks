#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



vector<int> merge(Node *root1,Node *root2);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


vector<int> inOrder(Node* root){
    vector<int> temp1;
    if(root == NULL){
        return temp1;
    }
    
    vector<int> temp2 = inOrder(root->left);
    temp1.insert(temp1.begin(), temp2.begin(), temp2.end());
    temp1.push_back(root->data);
    temp2 = inOrder(root->right);
    temp1.insert(temp1.begin(), temp2.begin(), temp2.end());
    return temp1;
}

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.
vector<int> merge(Node *root1, Node *root2)
{
   vector<int> tree1 = inOrder(root1);
   vector<int> tree2 = inOrder(root2);
   
   if(root1 == NULL && root2 !=  NULL){
        return inOrder(root2);
    }
    else if(root1 != NULL && root2 ==  NULL){
        return inOrder(root1);
    }
    
   tree2.insert(tree2.end(), tree1.begin(), tree1.end());
   sort(tree2.begin(), tree2.end());
   return tree2;
}