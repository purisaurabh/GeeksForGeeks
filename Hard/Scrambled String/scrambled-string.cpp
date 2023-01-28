//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool compare(string s1, string s2, unordered_map<string,bool> &m) {
        
        if(s1 == s2) return true;
        
        if(s1.length() <= 1) return false;
        
        string temp = s1+"_"+s2;
        if(m.find(temp) != m.end()) return m[temp];
        
        int n = s1.length();
        bool flag = false;
        
        for(int i = 1; i <= n-1; i++) {
            //no swapping
            if(compare(s1.substr(0,i),s2.substr(0,i),m) && compare(s1.substr(i,n-i),s2.substr(i,n-i),m)) {
                flag = true;
                break;
            }
            //swapping
            if(compare(s1.substr(0,i),s2.substr(n-i,i),m) && compare(s1.substr(i,n-i),s2.substr(0,n-i),m)){
                flag = true;
                break;
            }
        }
        
        return m[temp] = flag;;
    }
    
    bool isScramble(string S1, string S2){
        unordered_map<string,bool> m;
        return compare(S1,S2,m);
    }   
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends