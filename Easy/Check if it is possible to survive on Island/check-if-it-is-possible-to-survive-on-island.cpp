//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int sunday=S/7;
        int buyingdays=S-sunday;
        int totaldays=S*M;
        int ans=0;
        if(totaldays%N==0)
        {
        ans=totaldays/N;
        }
        else{
            ans=totaldays/N+1;
        }
        if(ans<=buyingdays)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends