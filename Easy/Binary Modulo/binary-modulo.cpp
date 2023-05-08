//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            int value = 1;
            int ans = 0;
            
            for(int i = s.size()-1; i >= 0; i--)
            {
                value = value % m;
                ans += value * (s[i] == '1' ? 1 : 0);
                ans = ans % m;
                value = value * 2;
            }
            
            return ans;
            
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
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends