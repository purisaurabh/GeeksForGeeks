//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int s = 1;
        int e = INT_MAX;
        
        int ans = 0;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            long long int sum = 0;
            
            for(int i = 0 ; i < nums.size(); i++)
            {
                if(nums[i]% mid == 0)
                {
                    sum += (nums[i]/mid);
                }
                
                else
                {
                    sum += (nums[i]/mid + 1);
                }
                
            }
            
            if(sum > K)
            {
                s = mid + 1;
            }
            
            else
            {
                ans = mid;
                e = mid - 1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends