//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){

        // Your code here

        vector<long long> ans;

        reverse(arr.begin() , arr.end());

        

        // deque<long long> st;

        stack<long long> st;

        

        ans.push_back(-1);

        st.push(arr[0]);

        for(int i=1; i<n; i++){

          while(!st.empty() && arr[i]>st.top())  st.pop();

                if(!st.empty())

                    ans.push_back(st.top());

                else

                    ans.push_back(-1);

                

                st.push(arr[i]);

            

        }

     

        reverse(ans.begin() , ans.end());

        return ans;

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends