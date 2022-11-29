//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int KthDistinct(vector<int>nums,int k){
     // Code here.
     map<int,int> m;
     vector<int> v;
     for(int i=0;i<nums.size();i++){
         m[nums[i]]++;
     }
     for(int i=0;i<nums.size();i++){
         if(m[nums[i]]==1){
             v.push_back(nums[i]);
         }
     }
     
     if(k>v.size()){
         return -1;
     }
     
     return v[k-1];
 }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans  = ob.KthDistinct(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends