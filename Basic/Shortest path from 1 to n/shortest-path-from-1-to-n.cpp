//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n)
    {
        int i = n;
        int count = 0;
        
        while(i > 1)
        {
            if( i % 3 == 0)
            {
                i = i / 3;
                count++;
            }
            
            else
            {
                i--;
                count++;
            }
        }
        
        return count;
        //complete the function here
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
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends