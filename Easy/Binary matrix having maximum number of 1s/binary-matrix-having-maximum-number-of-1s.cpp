//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    vector<int> findMaxRow(vector<vector<int>> mat, int n) 
    {
        //code here
        int count = INT_MIN;
        int row_number = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int another = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(mat[i][j] == 1)
                {
                    another++;
                }
            }
            
            if(another > count)
            {
                count = another;
                row_number = i;
            }
        }
        
        vector<int>ans;
        ans.push_back(row_number);
        ans.push_back(count);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends