//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    
    void find(vector<int> &nums , int target , vector<vector<int>> &ans , vector<int>&output , int index)
    {
        if(index == nums.size())
        {
            //at the end target will be zero them we cam sat that the subsequence having sum equal to targer will be present
            // then push it into the ans;
            if(target == 0)
                ans.push_back(output);
            
            return;
        }
        
        // this is take condition
        if(nums[index] <= target)
        {
            output.push_back(nums[index]);
            find(nums , target-nums[index] , ans , output , index);
            
            // this is when the not getting the answer from this way or there are other many way to find the answer
            output.pop_back();https://media.geeksforgeeks.org/img-practice/wheelfab-1680611378.svg
        }
        
        
        // this is not pick condition
        find(nums , target , ans , output , index+1);
        
    }
    
    
    
    vector<vector<int> > combinationSum(vector<int> &nums, int sum) 
    {
        // Your code here
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int index = 0;
        vector<int>output;
        nums.erase(unique(nums.begin() , nums.end()) , nums.end());
        find(nums , sum , ans , output , index);
        // sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends