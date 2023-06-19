//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length())
        return false;
        // Your code here
        int n=str1.length();
        vector<int>v1(128,-1);
        vector<int>v2(128,-1);
        for(int i=0;i<n;i++)
        {
            if(v1[str1[i]]!=v2[str2[i]])
            {
                return false;
            }
            else
            {
                v1[str1[i]]=v2[str2[i]]=i;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends