//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class dsu{
public:
    // parent vector for storing parent of each node
    // size vector for storing size of tree
    vector<int> parent, size;
    dsu(int n){
        parent.resize(n);iota(parent.begin(), parent.end() , 0);
        size.resize(n);fill(size.begin(), size.end() , 1);
    }   
    int find_parent(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find_parent(parent[x]);
    }
    void unite(int x, int y){
        int a=find_parent(x);
        int b=find_parent(y);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a, b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    bool same(int x, int y){
        return find_parent(x)==find_parent(y);
    }
    int treeSz(int x){
        return this->size[find_parent(x)];
    }
};
class Solution{
public:
    int goodStones(int n,vector<int> &a){
        dsu u(n);
        set<int> s;
        for(int i=0;i<n;i++){
            int ni=i+a[i];
            if(ni>=0 and ni<n){
                u.unite(i, ni);
            }else{
                s.insert(i);
            }
        }
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            v[u.find_parent(i)].push_back(i);
        }
        int ans=0;
        for(auto x:v){
            int f=0;
            for(auto c:x){
                if(s.count(c)){
                    f=1;break;
                }
            }
            ans+=(f*(x.size()));
        }
        return ans;
    }  
};



//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends