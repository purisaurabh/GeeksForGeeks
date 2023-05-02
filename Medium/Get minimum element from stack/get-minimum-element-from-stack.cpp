//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(s.empty())
            return -1;
        
            stack<int>temp;
            int mini = INT_MAX;
            
            while(!s.empty())
            {
                mini = min(mini , s.top());
                temp.push(s.top());
                s.pop();
            }
            
            while(!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
            
            return mini;
       }
       
       /*returns poped element from stack*/
       int pop(){
          if(s.empty())
            return -1;
            
          int temp = s.top();
          s.pop();
          
          return temp;
       }
       
       
       /*push element x into the stack*/
       void push(int x){
           s.push(x);
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends