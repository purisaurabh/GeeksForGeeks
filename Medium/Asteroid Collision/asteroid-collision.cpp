//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) 
    {
        vector<int>ans;
        
        stack<int>st;
        
        for(auto i : asteroids)
        {
            // if the element is positive
            if(i > 0)
            {
                st.push(i);
            }
            
            // if the element is negative
            else
            {
                // if the element is negative then check the three condition
                
                // check the while loop until the top element is positive and the top element is less than the current element
                while(!st.empty() && st.top() > 0 && st.top() <  abs(i))
                {
                    st.pop();
                }
                
                
                // if the top element and the current element is same
                if(!st.empty() && st.top() == abs(i))
                {
                    st.pop();
                }
                
                else if(st.empty() || st.top() < 0)
                {
                    st.push(i);
                }
            }
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends