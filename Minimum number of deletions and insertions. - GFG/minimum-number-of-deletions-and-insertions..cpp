//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1=str1.size();
	    int n2=str2.size();
	    
	    vector<int>t(n2+1,0);
	    
	    for(int i=1;i<=n1;i++){
	        vector<int>temp(n2+1,0);
	        for(int j=1;j<=n2;j++){
	            if(str1[i-1]==str2[j-1]){
	                temp[j]=1+t[j-1];
	            }
	            else{
	                temp[j]=max(t[j],temp[j-1]);
	            }
	        }
	        t=temp;
	    }
	    
	    return (n1+n2-(2*t[n2]));
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends