//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int>v;
        
        for(int i = L ; i <= R ; i++)
        {
            int num = i;
            int sum = 0;
            bool flag = true;
            
            while(num != 0)
            {
                int last = num % 10;
                
                if(last == D)
                {
                    flag = false;
                    break;
                }
                
                if(num == i)
                {
                    sum += last;
                    num = num / 10;
                }
                
                else
                {
                    if(last <= sum)
                    {
                        flag = false;
                        break;
                    }
                    
                    else
                    {
                        sum += last;
                        num = num/10;
                    }
                }
            }
            
            if(flag)
                v.push_back(i);
        }
        
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends