//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string low="";
        string upp="";
        for(int i=0;i<n;i++){
            if(isupper(str[i])){
                upp+=str[i];
            }
            else{
                low+=str[i];
            }
        }
        sort(low.begin(),low.end());
        sort(upp.begin(),upp.end());
        string ans="";
        int i=0;
        int j=0;
        int k=0;
        while(i<n){
            if(isupper(str[i])){
                ans+=upp[j];
                j++;
                
            }
            else{
                ans+=low[k];
                k++;
            
            }
            i++;
        }
        
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends