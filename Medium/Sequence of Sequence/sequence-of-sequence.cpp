//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int help(int i,int n,int m,int l){
    if(i>m) return 0;
    if(l==n) return m-i+1;
    return help(i*2,n,m,l+1)+help(i+1,n,m,l);
    }
    int numberSequence(int m, int n){
        return help(1,n,m,1);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends