//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        vector<int>ch(26,0);
        int fix,movable,sz,count;
        fix=0,movable=0,sz=-1,count=0;
        
        for(;movable<s.size();movable++){
            
            int idx= (int) (s[movable]-'a');
            ch[idx]++;
            
            count= ch[idx]==1?count+1:count;
            
            //taking unique characters upto current index gets greater then
            while(count>k){
                idx= s[fix]-'a';
                ch[idx]--;
                
                if(ch[idx]==0){
                    count--;
                }
                
                fix++;
            }
            
            
            if(count==k){
                sz= max(sz,movable-fix+1);

            }   
        }
        
        return sz;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends