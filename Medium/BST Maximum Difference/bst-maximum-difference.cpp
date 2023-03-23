//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    Node *find(Node *root , int target , int &upper_sum){
        
        if(root == NULL)
            return NULL;
            
        if(root->data == target)
            return root;
        
        upper_sum += root->data;
    
        if(root->data > target)
            return find(root->left , target , upper_sum);
        
        if(root->data < target)
            return find(root->right , target , upper_sum);
        
        return NULL;
        
    }
    
    void minimum_sum(Node *root , int &mini , int lower_sum)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
        {
            lower_sum += root->data;
            mini = min(mini , lower_sum);
        }
        
        lower_sum += root->data;
        minimum_sum(root->left , mini , lower_sum);
        minimum_sum(root->right , mini , lower_sum);
    }
    
    int maxDifferenceBST(Node *root,int target)
    {
        int upper_sum = 0;
        Node *target_root = find(root , target , upper_sum);
        
        if(!target_root)
            return -1;
        
        int mini = 1e9;
        
        minimum_sum(target_root , mini , 0);
        mini -= target;
        return upper_sum - mini;
    }
};




























//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends