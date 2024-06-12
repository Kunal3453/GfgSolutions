//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
   priority_queue<int> maxheap; // Max heap
priority_queue<int, vector<int>, greater<int>> minheap; // Min heap

// Function to insert into heap.
void insertHeap(int x) {
    if (maxheap.empty()) {
        maxheap.push(x);
        return;
    }
    if (maxheap.size() > minheap.size()) {
        if (x < maxheap.top()) {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(x);
        } else {
            minheap.push(x);
        }
    } else {
        if (x < maxheap.top()) {
            maxheap.push(x);
        } else {
            minheap.push(x);
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
}

// Function to balance heaps (not needed in this implementation)
void balanceHeaps() {
    // No operation needed as balancing is handled in insertHeap
}

// Function to return median.
double getMedian() {
    if (maxheap.size() == minheap.size())
        return (maxheap.top() + minheap.top()) / 2.0;
    else
        return maxheap.top();
}
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends