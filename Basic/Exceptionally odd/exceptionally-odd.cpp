//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    /*
    int getOddOccurrence(int arr[], int n) 
    {
        // code here
        unordered_map<int,int>m;
        
        for(int i = 0 ; i < n ; i++)
        {
            m[arr[i]]++;
        }
        
        int maxi = INT_MIN;
        int element;
        
        
        for(auto i : m)
        {
            if(i.second % 2 != 0)
            {
                return i.first;
            }
        }
        
        return element;
    }
    */
    
    int getOddOccurrence(int arr[], int n) 
    {
        int xor_ = 0;
        for(int i = 0 ; i < n ; i++)
        {
            xor_ = xor_ ^ arr[i];
        }
        
        return xor_;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends