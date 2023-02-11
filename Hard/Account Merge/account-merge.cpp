//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Dis_joint_set {

    // vector<int>rank;
    vector<int>parent;
    vector<int>size;

    public:
    Dis_joint_set(int n)
    {
        // rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0 ; i <= n ; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = find_parent(parent[node]);
    }

    /*
    void union_by_rank(int u , int v)
    {
        int ultimate_u = find_parent(u);
        int ultimate_v = find_parent(v);

        if(ultimate_u == ultimate_v)
            return;
        
        if(rank[ultimate_u] < rank[ultimate_v])
        {
            parent[ultimate_u] = ultimate_v;
        }

        else if(rank[ultimate_v] < rank[ultimate_u])
        {
            parent[ultimate_v] = ultimate_u;
        }

        else
        {
            parent[ultimate_v] = ultimate_u;
            rank[ultimate_u]++;
        }
    }
    */

    void union_by_size(int u , int v)
    {
        int ultimate_u = find_parent(u);
        int ultimate_v = find_parent(v);

        if(ultimate_u == ultimate_v)
            return;
        
        if(size[ultimate_u] < size[ultimate_v])
        {
            parent[ultimate_u] = ultimate_v;
            size[ultimate_v] += size[ultimate_u];
        }

        else
        {
            parent[ultimate_v] = ultimate_u;
            size[ultimate_u] += size[ultimate_v];
        }
    }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) 
    {
        // code here
        int n = accounts.size();
        Dis_joint_set ds(n);
        unordered_map<string , int> map_node_and_mail;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                
                // if the given string is not found
                if(map_node_and_mail.find(mail) == map_node_and_mail.end())
                {
                    map_node_and_mail[mail] = i;
                }
                
                else
                {
                    ds.union_by_size(i , map_node_and_mail[mail]); 
                }
            }
        }
        
        vector<string> merge_mail[n];
        for(auto it : map_node_and_mail)
        {
            string mail = it.first;
            int node = ds.find_parent(it.second);
            merge_mail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i =0 ; i < n ; i++)
        {
            if(merge_mail[i].size() == 0)
                continue;
            
            sort(merge_mail[i].begin() , merge_mail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merge_mail[i])
            {
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends