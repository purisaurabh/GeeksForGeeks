//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        for(int i=0;i<N;i++)
        {
            pq.push(make_pair(lines[i][0],0));
            pq.push(make_pair(lines[i][1],1));
        }
        
        int maxi = 0;
        int count = 0;
        
        while(!pq.empty())
        {
            pair<int,int> x = pq.top();
            pq.pop();
            if(x.second == 0)
                count++;
            else
                count--;
                
            maxi = max(maxi,count);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends