//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
static bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.second < b.second.second;
}

vector<int> maxMeetings(int n, vector<int> &S, vector<int> &F) {
    vector<pair<int, pair<int, int>>> p;
    for (int i = 0; i < n; i++) {
        pair<int, int> k = make_pair(S[i], F[i]);
        p.push_back(make_pair(i + 1, k));
    }
    sort(p.begin(), p.end(), comp);
    int currend = p[0].second.second;
    vector<int> ans;
    ans.push_back(p[0].first);
    for (int i = 1; i < n; i++) {
        if (p[i].second.first > currend) {
            currend = p[i].second.second;
            ans.push_back(p[i].first);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends