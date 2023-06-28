//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>&arr, int key) {
        // Code here
        int low=0,high=N-1;
         while(low<=high)
       {
           int mid=(low+high)/2;
           if(arr[mid]==key)
           {
               return true;
           }
           if(arr[low]==arr[mid]&&arr[mid]==arr[high])
           {
               low++;
               high--;
               continue;
           }
           if(arr[low]<=arr[mid])// left sorted
           {
               if(arr[low]<=key&&key<=arr[mid])
               {
                   high=mid-1;
               }
               else
               {
                   low=mid+1;
               }
           }
           else
           {
               if(arr[mid]<=key&&key<=arr[high])// right sorted
               {
                   low=mid+1;
               }
               else{
                   high=mid-1;
               }
           }
       }
       return false;
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends