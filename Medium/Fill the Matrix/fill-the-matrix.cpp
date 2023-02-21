//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y)
    {    
        // code here
        queue<pair<int,int>>q;
        q.push({x , y});
        
        int step = 0;
        
        vector<vector<int>>visited(N+1, vector<int>(M+1 , 0));
        
        int delrow[] = {-1 , 0 , +1 , 0};
        int delcol[] = {0 , -1 , 0 , +1};
        
        visited[x][y] = 1;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ;i < size ; i++)
            {
                auto it = q.front();
                q.pop();
                
                int row = it.first;
                int col = it.second;
                
                for(int j = 0 ; j < 4; j++)
                {
                    int newrow = row + delrow[j];
                    int newcol = col + delcol[j];
                    
                    if(newrow > 0 &&  newrow <= N && newcol > 0 && newcol <= M && !visited[newrow][newcol])
                    {
                        visited[newrow][newcol] = 1;
                        q.push({newrow , newcol});
                    }
                }
            }
            
            if(!q.empty())
                step++;
        }
        
        return step;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends