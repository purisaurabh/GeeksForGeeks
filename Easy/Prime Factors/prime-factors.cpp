//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) 
	{   
	    vector<int>v;
	    for(int i = 1 ; i <= N; i++)
	    {
	        int count = 0;
	        
	        if(N % i == 0)
	        {
	            for(int j = 1; j <= i ; j++)
	            {
	                if(i % j == 0)
	                    count++;
	            }
	            
	            if(count == 2)
	                v.push_back(i);
	        }
	    }
	    
	    return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends