//{ Driver Code Starts
//Initial Template for C++
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




// } Driver Code Ends
//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
    Node *find_target(Node *root , int target)
    {
        if(root == NULL)
            return NULL;
        
        if(root->data == target)
            return root;
        
        else if(root->data > target)
        {
            return find_target(root->left , target);
        }
        
        else
        {
            return find_target(root->right , target);
        }
    }
    
    long long int verticallyDownBST(Node *root,int target)
    {
        // Code here
        Node *target_node = find_target(root , target);
        
        if(target_node == NULL) 
            return -1;
            
        long long int ans = 0;
        queue<pair<Node* , int>>q;
        
        q.push({target_node , 0});
        
        while(!q.empty())
        {
            Node *node = q.front().first;
            int node_val = q.front().second;
            q.pop();
            
            if(node_val == 0)
                ans += node->data;
            
            if(node->left)
            {
                q.push({node->left , node_val - 1});
            }
            
            if(node->right)
            {
                q.push({node->right , node_val + 1});
            }
            
        }
        
        return ans - target_node->data;
        
    }
};

//{ Driver Code Starts.

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        int target;
        cin>>target;
        string newline;
        getline(cin,newline);
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.verticallyDownBST(root, target)<<endl;
   }
   return 0;
}
// } Driver Code Ends