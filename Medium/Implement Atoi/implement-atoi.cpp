//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int n = str.size();
        int temp = 1;
        int ans = 0;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                ans += temp * (str[i] - '0');
                temp = temp* 10;
            }
            
            else if(i == 0 && str[i+1] >= '0' && str[i+1] <= '9' && str[i] == '-')
            {
                ans = -ans;
            }
            
            else
            {
                return -1;
            }
        }
        
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends