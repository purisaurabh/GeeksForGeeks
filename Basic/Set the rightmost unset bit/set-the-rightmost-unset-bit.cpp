//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int n)
    {
        // Write Your Code here
        int ans = n;
        int position = 0;
        while( n != 0)
        {
            if((n & 1) == 0)
            {
                ans = ans | ( 1 << position);
                break;
            }
            
            n = n >> 1;
            position++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends