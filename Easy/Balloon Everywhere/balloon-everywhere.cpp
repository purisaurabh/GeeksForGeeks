//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{

public:

    int maxInstance(string s){

        unordered_map <char,int> ump;

        for(auto &it:s)

            ump[it]++;

        int ans = INT_MAX;

        ans = min(ans,ump['b']);

        ans = min(ans,ump['a']);

        ans = min(ans,ump['l']/2);

        ans = min(ans,ump['o']/2);

        ans = min(ans,ump['n']);

        return ans;

    }

};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends