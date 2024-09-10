//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int MOD = 1e9 + 7;
	int find(int arr[],int n,int sum,vector<vector<long>>&dp)
	{  if (n == 0) {
        if (sum == 0 && arr[0] == 0) {
            return 2;  // Two subsets: {0}, empty set
        }
        if (sum == arr[0] || sum == 0) {
            return 1;  // One valid subset
        }
        return 0;  // No valid subset
    }
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
	    int notpick=find(arr,n-1,sum,dp)%MOD;
	    int pick=0;
	    if(arr[n]<=sum)
	    {
	        pick=find(arr,n-1,sum-arr[n],dp)%MOD;
	    }
	    return dp[n][sum]= (pick+notpick)%MOD;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<long>>dp(n,vector<long>(sum+1,-1));
       int res=find(arr,n-1,sum,dp);
       return res;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends