//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        long long trappingWater(int arr[], int n)
        {
            if(n == 0)
                return 0;
            
            int lmax[n];
            int rmax[n];
            
            lmax[0] = arr[0];
            rmax[n-1] = arr[n-1];
            
            long long res = 0;
            
            for(int i = 1; i < n ; i++)
                lmax[i] = max(lmax[i-1] , arr[i]);
            
            for(int i = n-2; i>= 0 ; i--)
                rmax[i] = max(rmax[i+1] , arr[i]);
                
            
            for(int i = 0 ; i < n-1; i++)
                res += min(lmax[i] , rmax[i]) - arr[i];
                
            
            return res;
        }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends