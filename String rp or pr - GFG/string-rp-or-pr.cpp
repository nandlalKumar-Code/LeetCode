//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
private:
    
    vector<long long> removeFunc(char ch1,char ch2,string s){
        long long  n=s.size(),cnt1=0,cnt2=0;
        stack<char>st1,st2;
        
        //performing for "pr"/"rp" substring
        st1.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st1.empty() && s[i]==ch2 && st1.top()==ch1){
                cnt1++;
                st1.pop();
            }
            else{
                st1.push(s[i]);
            }
        }
        
        // cout<<cnt1<<" ";
        //performing for "rp"/"pr" substring using stack 1
        st2.push(st1.top());
        st1.pop();
        
        while(st1.empty()==false){
            if(!st2.empty() && st1.top()==ch2 && st2.top()==ch1){
                cnt2++;
                st2.pop();
            }
            else{
                st2.push(st1.top());
            }
            st1.pop();
        }
        // cout<<cnt2<<" END"<<endl;
        
        vector<long long>ans;
        if(ch1=='p'){
            ans.push_back(cnt1);
            ans.push_back(cnt2);
        }
        else{
            ans.push_back(cnt2);
            ans.push_back(cnt1);
        }
        return ans;
    }
public:
    long long solve(int X,int Y,string S){
      //code here
      vector<long long> ans;
      if(X>Y) ans=removeFunc('p','r',S);
      else ans=removeFunc('r','p',S);
      
      return 1LL*X*ans[0]+1LL*Y*ans[1];
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends