//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void find(int col , vector<vector<int>> &board , vector<vector<int>> &ans , vector<int> &left_row , vector<int> &lower_diagonal
    ,vector<int> &upper_diagonal, vector<int>temp , int n)
    {
        if(col == n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int row = 0; row < n ; row++)
        {
            if(left_row[row] == 0 && lower_diagonal[row+col] == 0 &&upper_diagonal[n-1 + col-row] == 0)
            {
                board[row][col] = 1;
                left_row[row] = 1;
                lower_diagonal[row+col] = 1;
                upper_diagonal[n-1+col-row] = 1;
                temp.push_back(row+1);
                
                find(col + 1 , board , ans , left_row , lower_diagonal , upper_diagonal , temp , n);
                
                board[row][col] = 1;
                left_row[row] = 0;
                lower_diagonal[row+col] = 0;
                upper_diagonal[n-1+col-row] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) 
    {
        // code here
        vector<vector<int>> board(n , vector<int>(n , 0));
        vector<vector<int>>ans;
        
        vector<int>temp;
        
        // for the left row or the straght backword direction to check the queen is present is or not
        vector<int>left_row(n , 0);
        
        // for check the direction of the queen present in the lower diagonal is queen present or not
        vector<int>lower_diagonal(2*n - 1 , 0);
        
        // for check the direction of the queen present in the upper diagonal is queen present or not
        vector<int>upper_diagonal(2*n - 1 , 0);
        
        find(0 , board , ans , left_row , lower_diagonal , upper_diagonal , temp , n);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends