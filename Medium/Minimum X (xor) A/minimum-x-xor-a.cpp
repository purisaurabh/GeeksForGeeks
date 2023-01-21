//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {

        int ans = 0;

        int k = __builtin_popcount(b);

        

        //cout << k << endl;

        for(int i = 31; i >= 0; i--) {

            if(k == 0) break;

            if(((1 << i) & a) != 0) {

                ans = ans | (1 << i);

                k--;

            }

            //cout << k << endl;

        }

        

        //cout << k << " " << ans << endl;

        //cout << ans << endl;

        

        for(int i = 0; i <= 31; i++) {

            if(k == 0) break;

            if(((1 << i) & ans) == 0) {

                ans = (ans | (1 << i));

                k--;

            }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends