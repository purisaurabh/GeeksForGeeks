#include <bits/stdc++.h>
using namespace std;

const bool compare(pair<int,int>&a , pair<int,int>&b)
{
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second > b.second;
    
}

int main() 
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    unordered_map<int ,int>m;
	    for(int i = 0 ; i < n ; i++)
	    {
	        int x;
	        cin >> x;
	        m[x]++;
	    }
	    
	    vector<pair<int,int>>v;
	    
	    for(auto i : m)
	    {
	        v.push_back(i);
	    }
	    
	    sort(v.begin() , v.end() , compare);
	    
	    for(auto it : v)
	    {
	        for(int i = 0 ; i < it.second; i++)
	        {
	            cout << it.first << " ";
	        }
	    }
	    
	    cout << endl;
	}
	return 0;
}