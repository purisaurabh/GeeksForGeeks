//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int> output;
        // map is used for the sorted 
        map< int,int> mp;
        for(int i=0; i<N; i++) mp[Arr[i]]++;
        for(auto it:mp){
            if(it.second % 2 !=0){
                // odd number frequency so included into the answer
                output.push_back(it.first);
            }
        }
        // step-2
        // before returning just sort the output array for better output
        sort(output.begin(),output.end());
        // reverse the output
        reverse(output.begin(),output.end());
        return output;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends