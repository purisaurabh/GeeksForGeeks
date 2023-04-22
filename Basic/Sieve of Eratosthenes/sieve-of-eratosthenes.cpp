//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here

        vector<bool>prime(n+1 , true);
        vector<int>v;
        // 0 and 1 are not a prime number
        
        prime[0] = false;
        prime[1] = false;
        
        for(int i = 2; i <= n/2 ; i++)
        {
            if(prime[i])
            {
                for(int j  = 2*i ; j <= n ; j= j+ i)
                {
                    prime[j] = false;
                }
            }
        }
        
        for(int i = 0 ; i <= n ; i++)
        {
            if(prime[i])
                v.push_back(i);
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
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends