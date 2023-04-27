//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void query1(int i , string &s , char ch)
    {
        s[i] = ch;
    }
    
    char query2(int left , int right , int k  , string s)
    {

        vector<int> v(26);
        for(int i = left;i<=right; i++)
        {
            v[s[i]-'a']++;
        }
        
        int sum = 0;
        for(int i = 25; i>= 0; i--)
        {
            sum += v[i];
            if(sum >= k)
            {
                return i + 'a';
            }
        }
        return 'z';
    }


public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){

       vector<char> ans;

       for(int i = 0; i<q; i++)
       {
           int q = queries[i][0][0] - '0';

           if(q == 1)
           {
               query1(stoi(queries[i][1]) , s , queries[i][2][0]);
           }
           if(q == 2)
           {
               char chh;
               chh = query2(stoi(queries[i][1]) , stoi(queries[i][2]) , stoi(queries[i][3]), s );
               ans.push_back(chh);
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends