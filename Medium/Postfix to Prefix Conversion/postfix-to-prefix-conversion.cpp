//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp)\
    {
        stack<string>st;
        int n = post_exp.size()-1;
        
        
        for(int i = 0; i <= n ; i++)
        {   
            char ch = post_exp[i];
            
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
                
                string new_str = ch + second + first;
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends