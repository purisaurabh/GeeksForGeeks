//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    vector<vector<bool>> ind, arab;
    int ans;
    void dfs(int i, int j, vector<vector<int>> &mat, vector<vector<bool>>&vis){
        if(vis[i][j]) return;
        vis[i][j] = true;
        
        if(arab[i][j] && ind[i][j]) ans+=1;
        
        if(i + 1 <  mat.size() && mat[i + 1][j] >= mat[i][j]) dfs(i + 1, j, mat, vis);  //down
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(i - 1, j, mat, vis);  //up
        if(j + 1 <  mat[0].size() && mat[i][j + 1] >= mat[i][j]) dfs(i, j + 1, mat, vis);  //left
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs( i, j - 1, mat, vis);   //right
        
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        ans = 0;
        ind = arab = vector<vector<bool> >(N, vector<bool>(M, false));
        
        for(int i=0;i<N;i++){
            dfs(i,0,mat,ind);
            dfs(i,M-1,mat,arab);
        }
        for(int j=0;j<M;j++){
            dfs(0,j,mat,ind);
            dfs(N-1,j,mat,arab);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends