//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) 
	{
	    // Code here
	    vector<int>adj[V];
	    for(auto i : prerequisites)
	    {
	        adj[i.first].push_back(i.second);
	    }
	    
	    
            int indegree[V] = {0};
        
            for(int i = 0; i < V ; i++)
            {
                for(auto &x : adj[i])
                {
                    indegree[x]++;
                }
            }
        
            queue<int>q;
            
            for(int i = 0 ; i < V ; i++)
            {
                if(indegree[i] == 0)
                    q.push(i);
            }
        
            int count = 0;
        
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
        
                count++;
        
                for(auto i : adj[front])
                {
                    indegree[i]--;
                    if(indegree[i] == 0)
                        q.push(i);
                }
            }
        
            if(count == V)
                return true;
            
            return false;
            
	}    
	    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends