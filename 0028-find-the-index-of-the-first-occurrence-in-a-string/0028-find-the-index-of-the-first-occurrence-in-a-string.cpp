class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        int maxi=INT_MIN;
        pair<int,int>mark;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(haystack[i-1]==needle[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    if(maxi<t[i][j]){
                        maxi=t[i][j];
                        mark={i,j};
                    }
                }
                else{
                    t[i][j]=0;
                }
            }
        }
        
        if(maxi!=m) return -1;
        
        
        int index=-1;
        int i=mark.first,j=mark.second;
        while(i>0 && j>0){
            if(haystack[i-1]==needle[j-1]){
                index=i;
                i--;
                j--;
            }
            else{
                if(t[i][j-1]>t[i-1][j]){
                    j--;
                }
                else{
                    i--;
                }
            }
        }
        
        return index-1;
        
        
    }
};