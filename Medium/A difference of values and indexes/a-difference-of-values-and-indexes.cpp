//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        int ans1=INT_MIN;
        int mini = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,arr[i]-i);
            int temp1 = arr[i]-i-mini;
            ans1 = max(ans1,temp1);
        }
        int ans2 = INT_MIN;
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
             maxi = max(maxi,arr[i]+i);
            int temp2 = maxi - arr[i]-i;
            ans2 = max(ans2,temp2);
            //cout<<ans2;
        }
        ans1 = max(ans1,ans2);
        return ans1;
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends