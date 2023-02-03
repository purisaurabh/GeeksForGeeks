//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) 
	{
	    // code here
	    int prev_1 = 0;
	    int prev_2 = 0;
	    
	    for(int i = 0 ; i < n ; i++)
	    {
	        int curr = max(prev_1 , prev_2 + arr[i]);
	        prev_2 = prev_1;
	        prev_1 = curr;
	    }
	    
	    return prev_1;
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
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends