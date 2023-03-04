//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void find(string s , vector<string> &ans , string output , int index)
	    {
	        if(s.size() == index)
	        {
	            ans.push_back(output);
	            return;
	        }
	        
	        // take condition
	        find(s , ans , output+s[index] , index+1);
	        
	        // not take
	        find(s , ans , output , index+1);
	    }
	    
	    
		vector<string> AllPossibleStrings(string s)
		{
		    // Code here
		    vector<string>ans;
		    string output = "";
		    int index = 0;
		    find(s , ans , output , index);
		    sort(ans.begin() , ans.end());
		    ans.erase(ans.begin());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends