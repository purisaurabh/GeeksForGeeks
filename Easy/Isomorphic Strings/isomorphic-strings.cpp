//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int a = str1.size();
        int b = str2.size();
        
        if(a != b)
            return false;
            
        char m_1[128] = {0};
        char m_2[128] = {0};
        
        
        for(int i = 0 ; i < a ; i++)
        {
            if(m_1[str1[i]] != m_2[str2[i]])
                return false;
            
            m_1[str1[i]] = i+1;
            m_2[str2[i]] = i+1;
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends