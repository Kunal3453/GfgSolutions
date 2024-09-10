//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
       vector<int>ans;
        long long sum=0,j=0,i=0;
       if (s == 0) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                return {i + 1, i + 1}; // Return 1-based index of the zero element
            }
        }
        return {-1}; // If no zero is found, return -1
    }
      
       while(j<n)
       {
           sum+=arr[j];
           while(sum>s)
           {
               sum-=arr[i];
               i++;
           }
           if(sum==s)
           {
              ans.push_back(i+1);
              ans.push_back(j+1);
               break;
           }
           j++;
           
       }
       if(ans.size()==0)
       {
           return {-1};
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
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends