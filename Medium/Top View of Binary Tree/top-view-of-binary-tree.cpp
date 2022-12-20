//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        
        if(root == NULL)
            return ans;
        
        // horizontal distance is the number line distance
        
        /*
            store the each node
            in this the first int is the horizontal distance and the second int for the root->data
        */
        map<int,int>top_node;
        
        // store the each node and their horizontal distance
        queue<pair<Node*,int>>q;
        
        // first of all we store the root node 
        q.push(make_pair(root , 0));
        
        // traverse for each node
        while(!q.empty())
        {
            // get the front value of the queue
            pair<Node*,int>temp = q.front();
            q.pop();
            
            /*
            we separate the first value for the node 
            and the second value for the horizontal distance
            */
            
            Node *front_node = temp.first;
            int horizontal_distance = temp.second;
            
            if(top_node.find(horizontal_distance) == top_node.end())
            {
                // store the root->data at their respective horizontal distance
                top_node[horizontal_distance] = front_node->data;
            }
            
            if(front_node->left)
                q.push(make_pair(front_node->left , horizontal_distance-1));
                
            if(front_node->right)
                q.push(make_pair(front_node->right , horizontal_distance+1));
            
        }
        
        for(auto i : top_node)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends