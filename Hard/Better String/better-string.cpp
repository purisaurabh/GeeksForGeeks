//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(string s)
    {
        int count = 1;
        unordered_map<char,int>m;
        for(int i = 0 ; i < s.size(); i++)
        {
            // if the given character is not find in the map
            if(m.find(s[i]) == m.end())
            {
                m[s[i]] = count;
                count *= 2;
            }
            
            else if(m.find(s[i]) != m.end())
            {
                int temp = m[s[i]];
                m[s[i]] = count;
                count *= 2;
                count = count - temp;
            }
        }
        
        return count;
    }
    
    string betterString(string str1, string str2) 
    {
        int first  = solve(str1);
        int second = solve(str2);
        
        if(first > second)
            return str1;
        
        else if(second > first)
            return str2;
        
        else if(first == second)
            return str1;
        
        return str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends