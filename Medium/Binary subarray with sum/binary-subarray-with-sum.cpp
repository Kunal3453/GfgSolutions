//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  int subarray(vector<int>nums,int goal)
{
    int n=nums.size();
    if(goal<0)
    return 0;
    int i=0,j=0;
    int sum=0,count=0;
    while(j<n)
    {
sum+=nums[j];
while(sum>goal)
{
    sum-=nums[i];
    i++;
}
count+=(j-i+1);
j++;
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int N, int goal){
      return (subarray(nums,goal)-subarray(nums,goal-1));   
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends