//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int func(int arr[],int n,int ans)
  {
      int day=1,load=0;
      for(int i=0;i<n;i++)
      {
          if(load+arr[i]>ans)
          {
              day=day+1;
              load=arr[i];
          }
          else
          {
              load+=arr[i];
          }
          
      }
      return day;
  }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int maxi=*max_element(arr,arr+N);
        int sum=accumulate(arr,arr+N,0);
        int low=maxi,high=sum;
        int ans=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int daysreq=func(arr,N,mid);
            if(daysreq<=D)
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends