//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<bool>> dp(K+1, vector<bool> (target+1, 0));
        dp[0][0] = 1;
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= K; i++){
            for(int j = 1; j <= target; j++){
                for(int k = 0; k < N; k++){
                    if(coins[k] <= j){
                        int x = coins[k];
                        if(dp[i-1][j-x]){
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }
        return dp[K][target];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends