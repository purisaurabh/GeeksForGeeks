//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
   int solve(int N, int K, vector<int> &arr) {

        // code here

        int sum=0;

        for(int i=0;i<N;i++){

            sum+=arr[i];

        }

        vector<int> v;

        int m=sqrt(sum)+1;

        for(int i=1;i<m;i++){

            if(sum%i==0){

                v.push_back(i);

                v.push_back(sum/i);

            }

        }

        for(int i=1;i<N;i++){

            arr[i]+=arr[i-1];

        }

        int res=1;

        for(int x: v){

            int cnt=0;

            for(int i=0;i<N;i++){

                if(arr[i]%x==0){

                    cnt++;

                }

            }

            if(cnt>=K) res=max(res,x);

        }

        return res;

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends