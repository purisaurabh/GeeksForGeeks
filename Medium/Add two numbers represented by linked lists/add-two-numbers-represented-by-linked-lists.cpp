//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
   {
       // code here
       Node *result = NULL;
       
       // first of all reverse the both the linked list
       Node *prev_1 = NULL;
       Node *temp = first;
       while(temp != NULL)
       {
           Node *next = temp->next;
           temp->next = prev_1;
           prev_1 = temp;
           temp = next;
       }
       
       Node *prev_2 = NULL;
       temp = second;
       while(temp != NULL)
       {
           Node *next = temp->next;
           temp->next = prev_2;
           prev_2 = temp;
           temp = next;
       }
       
       
       int carry = 0;
       int sum = 0;
       
       while(prev_1 != NULL && prev_2 != NULL)
       {
           sum = 0;
           sum += prev_1->data + prev_2 -> data + carry;
           carry = sum / 10;
           
           Node *new_node = new Node(sum % 10);
           new_node->next = result;
           result = new_node;
           prev_1 = prev_1 -> next;
           prev_2 = prev_2 -> next;
       }
       
       sum = 0;
       while(prev_1 != NULL)
       {
         sum = 0; 
         sum += prev_1->data + carry;
         carry = sum / 10;
         
         Node *new_node = new Node(sum % 10);
         new_node -> next = result;
         result = new_node;
         prev_1 = prev_1 -> next;
       }
       
       
       sum = 0;
       while(prev_2 != NULL)
       {
         sum = 0;        
         sum += prev_2->data + carry;
         carry = sum/10;
         Node *new_node = new Node(sum % 10);
   
         new_node->next = result;
         result = new_node;
         prev_2 = prev_2->next;
       }
       
       if(carry != 0)
       {
           Node *new_node = new Node(carry);
           new_node->next = result;
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends