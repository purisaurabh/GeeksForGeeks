//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n=arr.size();
        stack<pair<int,int>>st1;
        stack<pair<int,int>>st2;
        int i=0;
    vector<int>v(100005,-1);
       for(int i=0;i<n;i++){
           if(st1.empty()){
               st1.push({arr[i],i});
           }
           else {
               while(!st1.empty() and st1.top().first>=arr[i]){
                   st1.pop();
               }
               if(!st1.empty()){
                    v[i]=st1.top().second;
                   
               }
                st1.push({arr[i],i});
               
           }
       }
       for(int i=n-1;i>=0;i--){
           if(st2.empty()){
               st2.push({arr[i],i});
           }
           else {
               while(!st2.empty() and st2.top().first>=arr[i]){
                   st2.pop();
               }
               if(!st2.empty()){
                   if(v[i]!=-1){
                      if(i-v[i]>st2.top().second-i){
                           v[i]=st2.top().second;
                       }
                       else if(i-v[i]==st2.top().second-i){
                           if(arr[v[i]]>arr[st2.top().second]){
                               v[i]=st2.top().second;
                           }
                       }
                   }
                   else {
                       v[i]=st2.top().second;
                   }
                   
               }
                st2.push({arr[i],i});
           }
       }
       vector<int>ans;
       for(int i=0;i<n;i++){
           ans.push_back(v[i]);
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends