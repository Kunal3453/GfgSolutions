//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int>res;
    // code here
   int low=0,high=n-1;
   int first=-1;
   while(low<=high)
   {
       int mid=(low+high)/2;
       if(arr[mid]==x)
       {
           first=mid;
           high=mid-1;
       }
       else if(arr[mid]>x)
       {
           high=mid-1;
       }
       else
       {
           low=mid+1;
       }
   }
   res.push_back(first);
   int l=0,h=n-1;
   int last=-1;
   while(l<=h)
   {
       int mid=(l+h)/2;
       if(arr[mid]==x)
       {
           last=mid;
           l=mid+1;
       }
       else if(arr[mid]>x)
       {
           h=mid-1;
       }
       else
       {
           l=mid+1;
       }
   }
   res.push_back(last);
   return res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends