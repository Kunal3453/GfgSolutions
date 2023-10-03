//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        map<int,int>mpp;
        int i=0,j=0;
        int maxi=0;
        while(j<N)
        {
            mpp[fruits[j]]++;
            while(mpp.size()>2)
            {
                if(mpp[fruits[i]]==1)
                {
                    mpp.erase(fruits[i]);
                }
                else
                {
                    mpp[fruits[i]]--;
                }
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends