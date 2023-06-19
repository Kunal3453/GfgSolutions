//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        string ans="";
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            char a=s[i];
            if(a%2==1)
            {
                return s.substr(0,i+1);
            }
        }
        return " ";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends