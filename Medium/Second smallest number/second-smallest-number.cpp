//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(S > 9 * D){
            return "-1";
        }
        string ans = "";
        for(int i = 0; i < D-1; i++){
            if(i == 0){
                for(int j = 1; j <= 9; j++){
                    int rem = ceil((double)(S - j) / (double)(D - i - 1));
                    if(rem <= 9){
                        ans = ans + char(j+ '0');
                        S -= j;
                        break;
                    }
                }
            }
            else{
                for(int j = 0; j <= 9; j++){
                    int rem = ceil((double)(S - j) / (double)(D - i - 1));
                    if(rem <= 9){
                        ans = ans + char(j + '0');
                        S -= j;
                        break;
                    }
                }
            }
        }
        ans = ans + char(S + '0');
        if(ans[D-1] == '0'){
            return "-1";
        }
        else{
            int idx = -1;
            for(int i = 0; i < D-1; i++){
                if(ans[i] < '9'){
                    idx = i;
                }
            }
            if(idx == -1 || ans[idx+1] == '0'){
                return "-1";
            }
            else{
                ans[idx] = char((ans[idx]-'0')+1 + '0');
                ans[idx+1] = char((ans[idx+1]-'0')-1 + '0');
                return ans;
            }
        }
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends