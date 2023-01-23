//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int sum = 0;
    for(int i = 0 ; i < k ; i++)
    {
        sum += a[i];
    }
    
    long long int ans = sum;
    long long int prev = 0;
    long long int prev_sum = 0;
    
    for(int i = k; i < n ; i++)
    {
        prev_sum += a[i-k];
        prev = min(prev , prev_sum);
        sum += a[i];
        
        if(sum - prev > ans)
            ans = sum - prev;
    }
    
    
    return ans;
}