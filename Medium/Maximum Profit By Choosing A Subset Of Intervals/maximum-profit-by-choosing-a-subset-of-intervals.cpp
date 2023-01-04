//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
       vector<vector<int>>d;
       for(int i=0;i<intervals.size();i++)
       {
           d.push_back({intervals[i][1],intervals[i][0],intervals[i][2]});
       }
       sort(d.begin(),d.end());
       map<int,int>m={{0,0}};
       for(auto it:d)
       {
           int cur=prev(m.upper_bound(it[1]))->second+it[2];
           if(cur>m.rbegin()->second)
           {
               m[it[0]]=cur;
           }
       }
       return m.rbegin()->second;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends