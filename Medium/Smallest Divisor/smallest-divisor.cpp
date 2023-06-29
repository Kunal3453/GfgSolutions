//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int func(vector<int>nums,int mid)
  {
      int n=nums.size();
      int count=0;
      for(int i=0;i<n;i++)
      {
          count+=ceil((double)nums[i]/(double)mid);
      }
      return count;
  }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n=nums.size();
        if(n>K)
        {
            return -1;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
          maxi=max(maxi,nums[i]);  
        }
        int low=1,high=maxi;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(func(nums,mid)<=K)
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends