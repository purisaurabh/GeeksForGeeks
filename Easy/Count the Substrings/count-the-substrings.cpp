//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        map<int,int> map;
        int count = 0,ans = 0 , n = s.length();
        for(int i = 0 ; i< n; i++){
            if(s[i] >= 'a' && s[i]<= 'z'){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                ans++;
            }
            if(map.find(count) != map.end()){
                ans += map[count];
            }
            map[count]++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends