class Solution {
public:
    
    //VARIATION LCS WITH SOME MODIFICATION
    
    int minDistance(string word1, string word2) {
        //it is simple lcs with some modification
        int n1=word1.size();
        int n2=word2.size();
        
        vector<vector<int>>t(n1+1,vector<int>(n2+1,0));
        
        for(int i=0;i<=n1;i++){
            t[i][0]=i;
        }
        for(int j=0;j<=n2;j++){
            t[0][j]=j;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min(t[i-1][j],min(t[i][j-1],t[i-1][j-1]));
                }
            }
        }
        
        return t[n1][n2];
    }
};