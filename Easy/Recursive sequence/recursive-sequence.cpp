//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
          long long m = 1000000007;
        long long ans = 1;
        long long k = 1;
        long long res = 0;
        
        for(int i=1; i<=n; i++){
            ans = 1;
            for(int j=0; j<i; j++){
                ans = (ans * k)%m;
                k++;
            }
            res = (res + ans)%m;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends