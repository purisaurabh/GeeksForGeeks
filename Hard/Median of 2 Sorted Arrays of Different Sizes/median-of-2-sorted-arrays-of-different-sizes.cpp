//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes here
        vector<int>v;
        
        for(int i = 0 ; i < nums1.size(); i++)
        {
            v.push_back(nums1[i]);
        }
        
        for(int i = 0 ; i < nums2.size(); i++)
        {
            v.push_back(nums2[i]);
        }
        
        sort(v.begin() , v.end());
        
        if(v.size() % 2 == 0)
        {
            double second_mid = v[v.size()/2];
            double first_mid = v[(v.size()/2)-1];
            
            double ans = (first_mid + second_mid)/2;
            return ans;
        }
        
        else
        {
            int mid = v[v.size()/2];
            double ans = mid; 
            return ans;
        }
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends