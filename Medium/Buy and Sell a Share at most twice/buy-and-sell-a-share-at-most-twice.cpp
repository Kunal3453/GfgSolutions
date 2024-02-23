//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
             int cost1=(int)(1e9),cost2=(int)(1e9),profit1=0,profit2=0;

        for(int p:price){

            cost1=min(cost1,p);

            profit1=max(profit1,p-cost1);

            cost2=min(cost2,p-profit1);

            profit2=max(profit2,p-cost2);
        }
        return profit2;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends