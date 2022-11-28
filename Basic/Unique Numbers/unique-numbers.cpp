//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

    bool func(int N){
        unordered_map<int,int>mp;
        
        while(N>0){
            mp[N%10]++;
            N=N/10;
        }
        for(auto it:mp){
            if(it.second>1){
                return false;
            }
        }
        return true;
    }
    vector<int> uniqueNumbers(int L,int R)
    {
        vector<int>v;
        for(int i=L;i<=R;i++){
            if(func(i)){
                v.push_back(i);
            }
        }
        return v;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends