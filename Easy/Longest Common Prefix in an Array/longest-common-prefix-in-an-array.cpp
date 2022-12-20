//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N == 0)
            return "";
        
        sort(arr,arr+N);
        
        string p = arr[0];
        string q = arr[N-1];
        
        string ans = "";
        
        for(int i = 0 ; i < p.size(); i++)
        {
            if(p[i] == q[i])
            {
                ans += p[i];
            }
            
            else
            {
                break;
            }
        }
        
        if(ans.size() > 0)
        {
            return ans;
        }
        
        else
        {
            return "-1";
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends