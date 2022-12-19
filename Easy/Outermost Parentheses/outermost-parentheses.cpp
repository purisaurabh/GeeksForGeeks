//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& str) 
    {
        // code here
        stack<char>s;
        string ans = "";
        
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(str[i] == '(' && s.empty())
            {
                s.push(str[i]);
            }
            
            else if(str[i] == '(')
            {
                s.push(str[i]);
                ans += '(';
                
            }
            
            else if(str[i] == ')')
            {
                s.pop();
                
                if(s.size() > 0)
                {
                    ans += ')';
                }
            }
        }
        
        return ans;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends