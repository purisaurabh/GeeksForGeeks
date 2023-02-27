//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    // Eg : 1 2 3 4 5
    Node *reverse(Node *head, int k)
    {
        // Rotate list by k elements
        Node* root = head;
        while(head->next)  head = head->next; 
        head->next = root;
        while(k--) head = head->next;
        Node* newHead = head->next;
        head->next = NULL;
        
        // After rotating   3 4 5 1 2
        
        // Reverse Array
        Node* prev = NULL;
        Node* nex = NULL;
        while(newHead)
        {
            nex = newHead->next;
            newHead->next = prev;
            prev = newHead;
            newHead = nex;
        }
        //After reversing   2 1 5 4 3
        return prev;
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends