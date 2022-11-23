//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int mthHalf(int n, int m)
    {
        // code here
        int num = n;
        int count = 1;
        while(count < m)
        {
            num = num / 2;
            count++;
        }
        
        return num;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        
        Solution ob;
        cout<<ob.mthHalf(N, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends