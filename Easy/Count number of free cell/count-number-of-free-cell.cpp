//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{

  public:

  vector<long long int> countZero(int n, int k, vector<vector<int>>& a){

      //Code Here

      int r[n] = {0};

    int c[n] = {0};

    int cnt1 = 0, cnt2 = 0;

    vector<long long int> ans;

    int f = n * n;

    for (int i = 0; i < k; i++)

    {

        int count = 0;

        int r1=a[i][0];

        int c1 = a[i][1];

        if(r[r1-1]==0)

        {

            r[r1 - 1] = 1;

            cnt1++;

            count += n - cnt2;

        }

        if(c[c1-1]==0)

        {

            c[c1 - 1] = 1;

            cnt2++;

            count += n  - cnt1;

        }

        // cout << count << endl;

        f = f - count;

        // cout << f << endl;

        ans.push_back(f);

    }

    return ans;

  }

};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends