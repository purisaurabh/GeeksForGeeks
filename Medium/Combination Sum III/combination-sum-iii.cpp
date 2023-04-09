//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void find(int k , int n ,vector<int>&temp, vector<vector<int>>&ans , int start)
    {
        // base case
        if(temp.size() == k)
        {
            if(n == 0)
                ans.push_back(temp);
            
            return;
        }
        
        for(int i = start; i <= 9 ; i++)
        {
            temp.push_back(i);
            find(k , n-i, temp , ans , i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int>temp;
        int start = 1;
        find(k , n , temp , ans  , start);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends