//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        //int n = arr.size();
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++){
            string s = arr[i];
            reverse(s.begin(), s.end());
            if(mp.find(s)==mp.end())
                mp[arr[i]] = 0;
            else{
                if(mp[s] == 0)
                    mp[s]++;
                else
                    mp[arr[i]] = 0;
            }
        }
        /*for(auto x: mp)
            cout<<x.first<<" "<<x.second<<endl;*/
        int count = 0;
        for(auto x: mp){
            if(x.second == 0){
                string s = x.first;
                reverse(s.begin(), s.end());
                if(x.first != s ||count ==1)
                    return false;
                else
                    count++;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends