//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str)
    {
        string s = "";
        s = str[0];
        
        for(int i = 1; i < str.size(); i++)
        {
            if(str[i-1] >= str[i] && str[0] != str[1])
                s = s + str[i];
            
            else
                break;
        }
        
        string st = s;
        reverse(st.begin() , st.end());
        
        return s + st;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends