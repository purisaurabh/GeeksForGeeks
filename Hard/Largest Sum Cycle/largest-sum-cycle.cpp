//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
        long long ans = -1;
        
        void dfs(int node , int prev_node , vector<vector<int>> &adj , vector<long long > &sum , vector<long long> &visited , vector<long long> &visited_path)
        {
            sum[node] = sum[prev_node] + node;
            visited[node] = 1;
            visited_path[node] = 1;
            
            for(auto i : adj[node])
            {
                if(!visited[i])
                {
                    dfs(i , node , adj , sum , visited , visited_path);
                }
                
                else if(visited_path[i])
                {
                    ans = max(ans , sum[node] - sum[i] + i);
                }
            }
            
            visited_path[node] = 0;
        }
        
        
        long long largestSumCycle(int n, vector<int> edge)
        {
            // code here
            vector<vector<int>> adj(n);
            for(int i = 0 ; i < n ; i++)
            {
                if(edge[i] != -1)
                {
                    adj[i].push_back(edge[i]);
                }
            }
            
            
            vector<long long >sum(n+1);
            vector<long long>visited(n);
            vector<long long>visited_path(n);
            
            for(int i = 0 ; i < n ; i++)
            {
                if(!visited[i])
                {
                    dfs( i , n , adj , sum , visited , visited_path);
                }
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends