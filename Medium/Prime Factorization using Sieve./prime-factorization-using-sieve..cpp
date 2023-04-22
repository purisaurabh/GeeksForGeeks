//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {
        // tc = √n
       vector<int> ans;
       for(int i=2;i*i<=n;i++) {
           while(n % i == 0) {
               ans.push_back(i);
               n /= i;
           }
       }
       if(n > 1) ans.push_back(n); // for case like 13
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends