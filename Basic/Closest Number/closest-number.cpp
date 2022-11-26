//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) 
    {
        // code here
        int first_number = 0;
        for(int i = N; i >= -1e5; i--)
        {
            if(i % M == 0)
            {
                first_number = i;
                break;
            }
        }
        
        int second_number = 0;
        for(int i = N ; i < 1e5 ; i++)
        {
            if(i % M == 0)
            {
                second_number = i;
                break;
            }
        }
        
        int a = N-first_number;
        int b = second_number - N;
        
        if(a > b)
            return second_number;
        
        else
            return first_number;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends