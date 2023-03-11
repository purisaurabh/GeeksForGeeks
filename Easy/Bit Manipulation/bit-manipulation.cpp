//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // left shift means num*2 <<
    // right shift means num/2 >> 
    
    void get_bit(int num , int i)
    {
        if(num & (1 << i))
            cout << 1 << " ";
        
        else
            cout << 0 << " ";
    }
    
    
    void set_bit(int num , int i)
    {
        cout << (num | (1 << i)) << " ";
    }
    
    void clear_bit(int num , int i)
    {
        cout << (num & ~(1 << i)) << " ";
    }
    void bitManipulation(int num, int i) 
    {
        // your code here
        get_bit(num , i-1);
        set_bit(num , i-1);
        clear_bit(num , i-1);
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends