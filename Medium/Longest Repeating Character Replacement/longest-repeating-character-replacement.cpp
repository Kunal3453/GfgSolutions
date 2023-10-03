//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
       unordered_map<char,int>mpp;
       int maxf=0;
       int start=0;
       int maxi=0;
       int n=S.length();
       for(int end=0;end<n;end++)
       {
           mpp[S[end]]++;
           maxf=max(maxf,mpp[S[end]]);
           while((end-start+1-maxf)>K)
           {
               mpp[S[start]]--;
               start++;
           }
           maxi=max(maxi,end-start+1);
           
       }
       return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends