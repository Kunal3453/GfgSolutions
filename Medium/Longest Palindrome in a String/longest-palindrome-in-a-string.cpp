//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string longestPalin (string S) {
        // code here
        int start = 0;
    int end = 0;
    int low, high;
    int n = S.length();
    for (int i = 0; i < n; i++) {
        // Even length
        low = i;
        high = i + 1;

        while (low >= 0 && high < n && S[low] == S[high]) {
            if ((end - start) < (high - low)) {
                start = low;
                end = high;
            }
            low--;
            high++;
        }

        // Odd length
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < n && S[low] == S[high]) {
            if ((end - start) < (high - low)) {
                start = low;
                end = high;
            }
            low--;
            high++;
        }
    }
    return S.substr(start, end - start + 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends