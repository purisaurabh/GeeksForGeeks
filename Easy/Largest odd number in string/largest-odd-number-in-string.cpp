//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string num) 
    {
        // your code here
        if((num[num.size()-1] - '0') % 2 != 0)
        {
            return num;
        }

        string ans = "";
        int index = -1;
        for(int i = num.size()-1; i >= 0 ; i--)
        {
            if((num[i] - '0') % 2 != 0)
            {
                index = i;
                break;
            }
        }    

        for(int i = 0 ; i <= index ; i++)
        {
            ans += num[i];
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends