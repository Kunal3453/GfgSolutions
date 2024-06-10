//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
int search(string pat, string txt) {
    int k = pat.size();
    int n = txt.size();
    int ans = 0;
    unordered_map<char, int> mpp;

    // Build the frequency map for the pattern
    for (auto x : pat) {
        mpp[x]++;
    }
    
    int count = mpp.size();  // Number of unique characters in the pattern
    int i = 0, j = 0;

    while (j < n) {
        // Decrement the frequency of the current character in the window
        if (mpp.find(txt[j]) != mpp.end()) {
            mpp[txt[j]]--;
            if (mpp[txt[j]] == 0) {
                count--;
            }
        }

        // Check if the current window size matches the pattern size
        if (j - i + 1 == k) {
            // If count is zero, we found an anagram
            if (count == 0) {
                ans++;
            }

            // Before moving the window forward, restore the frequency of the character at the start
            if (mpp.find(txt[i]) != mpp.end()) {
                if (mpp[txt[i]] == 0) {
                    count++;
                }
                mpp[txt[i]]++;
            }
            i++;
        }
        j++;
    }
    
    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends