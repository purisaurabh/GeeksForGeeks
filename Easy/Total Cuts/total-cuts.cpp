//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &arr)
    {
        int max_value = INT_MIN;
        int min_value = INT_MAX;
        
        vector<int>max_arr;
        vector<int>min_arr;
        
        for(int i = 0; i < n; i++)
        {
            max_value = max(max_value , arr[i]);
            max_arr.push_back(max_value);
        }
        
        for(int i = n-1; i >= 0 ; i--)
        {
            min_value = min(min_value , arr[i]);
            min_arr.push_back(min_value);
        }
        
        int count = 0;
        int i = 0;
        int j = max_arr.size()-1;
        
        while(j--)
        {
            if(max_arr[j] + min_arr[i] >= k)
                count++;
            
            i++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends