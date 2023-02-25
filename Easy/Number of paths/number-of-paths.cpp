//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    // Code Here
    vector<long long>v(n , 1);
    for(int i = 1; i < m ; i++)
    {
        for(int j = 1; j < n ; j++)
        {
            v[j] += v[j-1];
        }
    }
    
    return v[n-1];
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends