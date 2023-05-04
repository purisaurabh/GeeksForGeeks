//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) 
    {
        stack<string>st;
        int n = pre_exp.size()-1;
        for(int i = n ; i >= 0 ; i--)
        {
            char ch = pre_exp[i];
            
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                string temp = "";
                temp += ch;
                st.push(temp);
            }
            
            else
            {
                string first = st.top();
                st.pop();
                
                string second = st.top();
                st.pop();
                 
                string new_str = '('+ first + ch + second + ')';
                st.push(new_str);
            }
        }
        
        
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends