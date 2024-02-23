#include<bits/stdc++.h>
using namespace std;
int main()
 {
 int t;
 cin>>t;
 while(t--)
 {
     int n;
        cin>>n;
        int a[n];
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        sort(a,a+n,[&m](int c,int d)
        {
        return (m[c]==m[d])?c<d:m[c]>m[d];
        });
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
 }
	return 0;
}