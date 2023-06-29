//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int findmax(vector<int>piles,int n)
  {
      int maxi=INT_MIN;
      for(int i=0;i<n;i++)
      {
          maxi=max(maxi,piles[i]);
      }
      return maxi;
  }
  int func(vector<int>piles,int n,int mid)
  {
      int totalhours=0;
      for(int i=0;i<n;i++)
      {
          totalhours+=ceil((double)piles[i]/(double)mid);
      }
      return totalhours;
  }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int low=1,high=findmax(piles,N);
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int hour=func(piles,N,mid);
            if(hour<=H)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends