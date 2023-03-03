//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void find(int start , int end , int n , vector<string> &ans , string str)
    {
        if(str.size() == 2*n)
        {
            ans.push_back(str);
            return;
        }
        
        else
        {
            if(start < n)
            {
                find(start+1 , end , n , ans , str+'(');
            }
            
            if(end < start)
            {
                find(start , end + 1, n , ans , str+')');
            }
        }
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        string str = "";
        find(0 , 0, n ,  ans , str);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends