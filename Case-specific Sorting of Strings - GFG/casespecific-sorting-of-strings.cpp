//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char>s(n,'X');
        string upper;
        string lower;
        for(int i=0;i<n;i++){
            if((str[i]>='A') && (str[i]<='Z')){
                s[i]='U';
                upper.push_back(str[i]);
            }
            else{
                s[i]='S';
                lower.push_back(str[i]);
            }
        }
        
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        // cout<<upper<<"<----->"<<lower<<endl;
        
        string ans="";
        for(int i=0,j=0,k=0;i<n;i++){
            if(s[i]=='U'){
                ans.push_back(upper[j]);
                j++;
            }
            else{
                ans.push_back(lower[k]);
                k++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends