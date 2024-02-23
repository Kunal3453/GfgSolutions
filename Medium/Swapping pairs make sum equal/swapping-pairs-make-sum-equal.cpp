//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
    {
        
          int S1 = accumulate(A,A+n,0);
        int S2 = accumulate(B,B+m,0);
        if(S1 > S2){
            return findSwapValues(B,m,A,n);
        }
        if(S1 == S2) return 1;
        if((S2 - S1) % 2 != 0){
            return -1;
        }
        int target = (S2 - S1) / 2;
        unordered_set<int> hs(A,A+n);
        for(int i = 0; i < m; i++){
            if(hs.count(B[i] - target)){
                return 1;
            }
        }
        return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends