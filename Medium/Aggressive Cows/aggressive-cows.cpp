//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool is_possible(vector<int> &stall , int mid , int k)
    {
        int cow_count = 1;
        int last_position = stall[0];
        
        for(int i = 0 ; i < stall.size() ; i++)
        {
            if(stall[i] - last_position >= mid)
            {
                cow_count++;
                if(cow_count == k)
                    return true;
                
                last_position = stall[i];
            }
        }
        
        return false;
    }
    int solve(int n, int k, vector<int> &stall) 
    {
        // Write your code here
        sort(stall.begin() , stall.end());
        int maxi = -1;
        for(int i = 0 ; i < n; i++)
        {
            maxi = max(maxi  , stall[i]);
        }
        
        int s = 0;
        int e = maxi;
        int ans = -1;
        
        int mid = s + (e-s)/2;
        while(s <= e)
        {
            //right part
            if(is_possible(stall , mid , k))
            {
                ans = mid;
                s = mid+1;
            }
            
            //left part
            else
            {
                e = mid-1;
            }
            
            mid = s + (e-s)/2;
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

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends