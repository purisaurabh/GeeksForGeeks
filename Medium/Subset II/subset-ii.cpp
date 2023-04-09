//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int ind, vector<int> &v, vector<int> &arr, vector<vector<int>> &ans)
    {
        if(v.size() == 0) ans.push_back(v);
        if(ind == arr.size())
        {
            return;
        }
        
        for(int i = ind; i < arr.size(); i++)
        {
            if(i > ind && arr[i] == arr[i - 1]) continue;
            v.push_back(arr[i]);
            ans.push_back(v);
            solve(i + 1, v, arr, ans);
            v.pop_back();
        }
    }
      
  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end());
        vector<int> v;
        vector<vector<int>> ans;
        solve(0, v, nums, ans);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends