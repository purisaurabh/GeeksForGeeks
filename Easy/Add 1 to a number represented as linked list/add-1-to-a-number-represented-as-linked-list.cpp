//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        // reverse the linked list
        Node *dummy = NULL;
        Node *temp = head;
        while(temp != NULL)
        {
            Node *next = temp->next;
            temp->next = dummy;
            dummy = temp;
            temp = next;
        }
        
        int sum = 0;
        int carry = 0;
        Node *result = NULL;
        
        dummy->data += 1;
        while(dummy != NULL)
        {
            sum = 0;
            sum += dummy->data + carry ;
            
            carry = sum / 10;
            Node *new_node = new Node(sum % 10);
            new_node ->next = result;
            result = new_node;
            dummy = dummy->next;
        }
        
        if(carry != 0)
        {
            Node *new_node = new Node(carry);
            new_node ->next = result;
            result = new_node;
        }
        
        return result;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends