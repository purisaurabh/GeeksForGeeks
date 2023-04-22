//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long>ans(n , 0);
        map<int , long long>m;
        
        for(int i = 0 ; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }
        
        long long prev = 0;
        for(auto &i : m)
        {
            int freq = i.second;
            i.second = prev;
            prev = prev + (freq * i.first);
        }
        
        for(int i = 0; i < n ; i++)
        {
            ans[i] = m[arr[i]];
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends