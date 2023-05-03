//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int prece(char ch)
    {
        if(ch == '^')
            return 3;
        
        else if(ch == '*' || ch == '/')
            return 2;
        
        else if(ch == '+' || ch == '-')
            return 1;
        
        else
            return -1;
    }
    
    string infixToPostfix(string s) 
    {
        stack<char>st;
        string result = "";
        
        for(int i = 0 ; i < s.size(); i++)
        {
            char ch = s[i];
            
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'B'))
            {
                result += ch;
            }
            
            else if(ch == '(')
            {
                st.push('(');
            }
            
            else if(ch == ')')
            {
                while(st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                
                st.pop();
            }
            
            else
            {
                while(!st.empty() && prece(ch) <= prece(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
                
                st.push(ch);
            }
        }
        
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends