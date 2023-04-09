//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void find_ans(int index , string s , string output  , string arr[] , vector<string>&ans)
    {
        // base case
        if(index == s.size())
        {
            ans.push_back(output);
            return;
        }
        
        // get the number from which we can acces the string from string arr
        int number = s[index] - '0';
        string str = arr[number];
        
        for(int i = 0 ; i < str.size(); i++)
        {
            output.push_back(str[i]);
            find_ans(index+1 , s , output , arr , ans);
            output.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int n)
    {
        string s = "";
        for(int i = 0 ; i< n ; i++)
        {
            string temp = to_string(a[i]);
            s += temp;
        }
        
        vector<string>ans;
        if(s.size() == 0)
            return ans;
        
        string output = "";
        string arr[] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        
        int index = 0;
        find_ans(index , s , output , arr , ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends