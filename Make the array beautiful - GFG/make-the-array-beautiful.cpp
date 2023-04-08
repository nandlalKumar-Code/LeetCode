//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>st;
        int i=0,n=arr.size();
        vector<int>ans;
        while(i<n){
            bool flage=false;
            if(st.empty()==false && ( (arr[i]>=0 && st.top()<0)||(arr[i]<0 && st.top()>=0)) ){
                // cout<<arr[i]<<" ===> "<<st.top()<<endl;
                st.pop();
                flage=true;
            }
            
            if(flage==false){
                st.push(arr[i]);
            }
            i++;
        }
        while(st.empty()==false){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends