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
    vector<int> getDistinctDifference(int n, vector<int> &a) {
        unordered_map<int , int> m, m1;
        vector<int> d(a.size());
        vector<int> d1(a.size());
        vector<int> r;
        vector<int> c = a;
        reverse(c.begin(),c.end());
        
        int j = 0;
        int k = a.size()-1;
        
        for(auto i:c)
        {
            d1[k] = m1.size();
            m1[i]++;
            k--;
        }
        for(auto i:a)
        {
            d[j] = m.size();
            r.push_back(d[j]-d1[j]);
            m[i]++;
            j++;
        }
        return r;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends