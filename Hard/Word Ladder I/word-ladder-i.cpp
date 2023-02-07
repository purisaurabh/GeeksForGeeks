//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) 
    {
        // Code here
        queue<pair<string , int>> q;
        q.push({startWord , 1});
        
        unordered_set<string>st(wordList.begin() , wordList.end());
        st.erase(startWord);
        
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
             
            
            // if the given target word is find the then the return the step required to reached the target word
            if(word == targetWord)
                return steps;
                
            // traverse the all the character int the first word and the change it fromt a to z
                // and find any word if getting or not which is available in the wordList or not
            
            for(int i = 0 ; i < word.size(); i++)
            {
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // find the the given word is present or not 
                    if(st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word , steps + 1});
                    }
                }
                
                word[i] = original;
            }
             
             
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends