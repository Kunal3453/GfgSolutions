//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input array
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
      double x[M],y[N];
       for(int i=0;i<M;i++)
       {
           x[i]=pow(X[i],1.0/X[i]);
       }
       for(int i=0;i<N;i++)
       {
           y[i]=pow(Y[i],1.0/Y[i]);
       }
       sort(x,x+M);
       sort(y,y+N);
       int count=0;
       long long ans=0;
       for(int i=0;i<M;i++)
       {
           while(x[i]>y[count]&&count<N)
           {
               count++;
           }
           ans=ans+count;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}
// } Driver Code Ends