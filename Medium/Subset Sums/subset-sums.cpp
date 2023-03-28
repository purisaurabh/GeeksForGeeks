//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void find(int n , int index , int sum , vector<int>&arr , vector<int>&ans)
    {
        if(index == n)
        {
            ans.push_back(sum);
            return;
        }
        
        // this is the pick condidtion
        find(n , index + 1 , sum + arr[index] , arr , ans);
        
        // this is the not pick condition
        find(n , index+1 , sum , arr , ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int>ans;
        int index = 0;
        int sum = 0;
        find(n , index , sum , arr , ans);
        sort(ans.begin() , ans.end());
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends