//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Disjoint {
private: 
    vector<int> parent, size;
public: 
    Disjoint(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1); 
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu == pv) return;
    
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
        Disjoint d(n);
        vector<string> ans;
        
        for(int i = 0; i < n; i++) {
            int u = mix[i][0], v = mix[i][1];
            int pu = d.findParent(u), pv = d.findParent(v);
            bool flag = true;
            
            for(int j = 0; j < m; j++) {
                int u1 = danger[j][0], v1 = danger[j][1];
                int pu1 = d.findParent(u1), pv1 = d.findParent(v1);
                
                if((pu == pu1 and pv == pv1) or (pu == pv1 and pv == pu1)) {
                    flag = false;
                    break;
                }
            }
            
            if(!flag)
                ans.push_back("No");
            else {
                d.unionBySize(u, v);
                ans.push_back("Yes");
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends