//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        int lastEnd = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(i-x > lastEnd) return 0;
                lastEnd = i+x+1;
            }
        }
        return lastEnd >= n;
    }
};



//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends