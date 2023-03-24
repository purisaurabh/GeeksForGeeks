//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        
        map<char, int>m; 
        int n=s.size();
        int l=0,r=n-1;
        for(int i=0;i<n;i++)
            m[s[i]]++;//storer freq of chaar in map 
     /*   for(auto x:m)
            cout<<x.first<<" "<<x.second<<endl; 
    */
        int left_delete=-1;//marker to find last deleted item is from left side or right side
        while(l<r)//while left<right
        {
            while(m[s[l]]==1)// skip non repeated characters from left
                l++;
            if(m[s[l]]>1)//repeated char
            {
                m[s[l]]--;
                s[l]='#';
                left_delete=1;
            }
            while(m[s[r]]==1)//skip non repeated char from right
                r--;
            if(m[s[r]]>1)// repeated char
            {
                m[s[r]]--;
                s[r]='#';
                left_delete=0;
            }
            l++;r--;
        }
        string ans;
        for(int i=0;i<n;i++)
            if(s[i]!='#')
                ans+=s[i];

        if(left_delete==1)//reverse answer if lasst delete is from left
            reverse(ans.begin(),ans.end());
        return ans;
            
       
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends