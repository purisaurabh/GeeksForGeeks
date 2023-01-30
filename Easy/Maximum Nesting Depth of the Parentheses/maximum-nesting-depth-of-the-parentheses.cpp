//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) 
    {
        // code here
        stack<char>st;
        int maxi = 0;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(')
                st.push('(');
            
            else if(s[i] == ')')
            {
                if(st.empty())
                    continue;
                
                if(maxi < st.size())
                    maxi = st.size();
                
                st.pop();
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends