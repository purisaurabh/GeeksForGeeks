//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> mat){
        int i=0,j=0;
        int n=mat.size();
        int m=mat[0].size();
        char ch='r';
        while(i<n && j<m && j>=0 && i>=0){
            if(ch=='r'){
            if(mat[i][j]==1){
                mat[i][j]=0;
                i++;
                ch='d';
            }else {
                 j++;
            }
            }else if(ch=='d'){
            if(mat[i][j]==1){ 
                 mat[i][j]=0;
                j--;
                ch='l';
            }else {
                i++;
            }
                
        }else if(ch=='l'){
            if(mat[i][j]==1){
                 mat[i][j]=0;
                i--;
                ch='u';
            }else {
                j--;
            }
                
        }else if(ch=='u'){
            if(mat[i][j]==1){ 
                 mat[i][j]=0;
                j++;
                ch='r';
            }else {
                i--;
            }
                
        }
        if((i==n-1&&j==m-1)||j<0||i<0) break;
        }
        if(i<0) i=0;
        if(i==n) i=i-1;
        if(j==m) j=j-1;
        if(j<0) j=0;
        return {i,j};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends