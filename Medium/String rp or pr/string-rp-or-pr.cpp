//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int x,int y,string s){
      //code here
      int n=s.size();
      stack<char> st;
      long long ans=0;
      st.push(s[0]);
      for(int i=1;i<n;i++){ // remove all rp or pr depending on x,y value
          if(s[i]=='r' && x>=y){
              if(st.size() && st.top()=='p'){
                  st.pop();
                  ans+=x;
              }
              else
                st.push(s[i]);
          }
          else if (s[i]=='p' && y>=x){
              if(st.size() && st.top()=='r'){
                  st.pop();
                  ans+=y;
              }
              else
                st.push(s[i]);
          }
          else 
            st.push(s[i]);
      }
      stack<char> st1;
      while(st.size() && x!=y){ //remove any pr,rp if remaining
          if(st.top()=='r' && st1.size() && st1.top()=='p'){
            ans+=y;
            st1.pop();
          }
        else if(st.top()=='p' && st1.size() && st1.top()=='r'){
            ans+=x;
            st1.pop();
        }
        else
            st1.push(st.top());
        st.pop();
      }
      return ans;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends