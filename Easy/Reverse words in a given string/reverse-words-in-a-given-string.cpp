//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int n=S.length();
        vector<string>v;
        string curr_word="";
        string result;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='.')
            {
                v.push_back(curr_word);
                curr_word="";
            }
            else
            {
                curr_word+=S[i];
            }
        }
        v.push_back(curr_word);
        for(int i=v.size()-1;i>=0;i--)
        {
            result+=v[i];
            if(i!=0)
            {
                result+='.';
            }
        }
        return result;
        
        }
        
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends