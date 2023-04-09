//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void solve(vector<int>&arr , int target ,vector<vector<int>>&ans,vector<int>&output,int index)
    {
        if(target == 0)
        {
            ans.push_back(output);
            return;
        }
        
        for(int i = index; i < arr.size(); i++)
        {
            if(i > index && arr[i] == arr[i-1])
            {
                continue;
            }
            
            if(arr[i] > target)
                break;
            
            output.push_back(arr[i]);
            
            //then we update the target value by minusing the index value and make a recursive call
            solve(arr , target-arr[i] , ans , output , i+1);
            
            // then backtracking is happen here
            output.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        
        solve(candidates , target , ans , output , index);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends