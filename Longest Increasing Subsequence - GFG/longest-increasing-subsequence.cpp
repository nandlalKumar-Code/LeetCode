//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int lengthOfLIS(int nums[],int n)
{
 
    // Binary search approach

    vector<int> ans;
 
    ans.push_back(nums[0]);
 
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
            ans[low] = nums[i];
        }
    }
 
    return ans.size();
}
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
       return lengthOfLIS(a,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends