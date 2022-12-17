//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution 
{
    public:
        void add_left_node(Node *root , vector<int>&v)
        {
            // if the given node is null node or the leaf node them we have come back
            if((root == NULL) || (root->left == NULL && root->right == NULL))
            {
                return;                
            }
            
            //if not then push the data og the given node
            v.push_back(root->data);
            
            if(root->left)
                add_left_node(root->left , v);
                
            else
                add_left_node(root->right , v);
        }
        
        
        void add_leaf_node(Node *root , vector<int>&v)
        {
            if(root == NULL)
                return;
                
            if(root->left == NULL && root->right == NULL)
                v.push_back(root->data);
            
            add_leaf_node(root->left , v);
            add_leaf_node(root->right , v);
            
        }
        
        void add_right_node(Node *root , vector<int>&v)
        {
            if((root == NULL) || (root->left == NULL && root->right == NULL))
            {
                return;                
            }
            
            if(root->right)
                add_right_node(root->right , v);
                
            else
                add_right_node(root->left , v);
                
            v.push_back(root->data);
            
        }
        
        vector <int> boundary(Node *root)
        {
            vector<int>v;
            if(root == NULL)
                return v;
            
            // push the main root data
            v.push_back(root->data);
            
            // for getting the left part nodes
            // starting from the left node of the root
            add_left_node(root->left, v);
            
            // left subtree leaf node
            add_leaf_node(root->left , v);
            
            // right subtree leaf_node
            add_leaf_node(root->right , v);
            
            // last of the operation is add all right nodes
            add_right_node(root->right , v);
            
            return v;
        }
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    /*
        void add_left_nodes(Node *root , vector<int>&v)
        {
            // starting from the left of the root node 
            Node *left_node = root->left;
            
            while(left_node)
            {
                // if current node is not a leaf node
                if(left_node->left != NULL && left_node->right != NULL)
                {
                    v.push_back(left_node->data);
                }
                
                //if the left of the given node is present then go to the right
                if(left_node->left)
                    left_node = left_node->left;
                        
                //else go to right
                else
                    left_node = left_node->right;
            }
        }
        
        
        void add_leaf_nodes(Node *root , vector<int>&v)
        {
            if(root->left == NULL && root->right == NULL)
            {
                v.push_back(root->data);
                return;
            }
                
            if(root->left)
                add_leaf_nodes(root->left , v);
            
            if(root->right)
                add_leaf_nodes(root->right , v);
        }
        
        void add_right_nodes(Node *root , vector<int>&v)
        {
            // we make a temp vector beacause of the we have to reverse the gievn vector 
            vector<int>temp;
            
            //for the right nodes starting form thr roght node of the root node
            Node *right_node = root->right;
            
            while(right_node)
            {
                if(right_node->left != NULL && right_node->right != NULL)
                {
                    temp.push_back(right_node->data);
                }
                
                if(right_node ->right)
                    right_node = right_node -> right;
                    
                else
                    right_node = right_node->left;
            }
            
            for(int i = temp.size() - 1; i >= 0 ; i--)
            {
                v.push_back(temp[i]);
            }
            
        }
        
        
        vector <int> boundary(Node *root)
        {
            vector<int>v;
            
            if(root == NULL)
                return v;
                
            if(root->left != NULL && root->right != NULL)
            {
                v.push_back(root->data);
            }
            
            add_left_nodes(root , v);
            add_leaf_nodes(root , v);
            add_right_nodes(root , v);
            
            return v;
        }
        
    */
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends