//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int  fun( int a , int b , int c , int d)

    {

        int ans = 0;

        while(a>c)

        {

            a = a/2;

            ans++;

        }

        while(b>d)

        {

            b = b/2;

            ans++;

        }

        return ans;

    }

    

    int carpetBox(int A, int B, int C, int D)

    {

        //code here

        return  min(fun( A , B , C , D) , fun(  A , B , D , C));

    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends