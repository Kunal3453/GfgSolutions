//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool func(vector<int>bloom,int mid,int m,int k)
  {
      int n=bloom.size();
      int count=0;
      int noofb=0;
      for(int i=0;i<n;i++)
      {
          if(bloom[i]<=mid)
          {
              count++;
          }
          else{
              noofb+=(count/k);
              count=0;
          }
      }
      noofb+=count/k;
      return noofb>=m;
  }
    int solve(int m, int k, vector<int> &bloomDay){
     
      // Code here
      int n=bloomDay.size();
      long long val=m*1LL*k*1LL;
      if(val>n)
      return -1;
      int mini=INT_MAX;
      int maxi=INT_MIN;
      for(int i=0;i<n;i++)
      {
         mini=min(mini,bloomDay[i]);
         maxi=max(maxi,bloomDay[i]);
      }
      int low=mini,high=maxi;
      int ans=INT_MAX;
      while(low<=high)
      {
          int mid=(low+high)/2;
          if(func(bloomDay,mid,m,k))
          {
              ans=mid;
              high=mid-1;
          }
          else{
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends