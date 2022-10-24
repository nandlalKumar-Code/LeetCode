class Solution {
public:
    string longestPalindrome(string s) {
        //variation of longest common substring
        string str=s;
        reverse(str.begin(),str.end());
        
        int n=s.size();
        
        vector<vector<int>>t(n+1,vector<int>(n+1,0));
        int result=INT_MIN;
        string ans;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==str[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    
                    if(result<t[i][j]){
                        string temp1=s.substr(i-t[i][j],t[i][j]);
                        string temp2=string(temp1.rbegin(),temp1.rend());
                        
                        if(temp1==temp2){
                            result=t[i][j];
                            ans=temp1;
                        }
                    }
                }
                else{
                    t[i][j]=0;
                }
            }
        }
        return ans;
    }
};