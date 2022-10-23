class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //it is also a variation of lcs 
        int n1=str1.size();
        int n2=str2.size();
        
        vector<vector<int>>t(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        string ans;
        ans.reserve(n1+n2);
        
        //agar match nhi ho rha hai 
        //to jidhar maximum hai udar 
        //ko n1 or n2 ko move kr lo
        //string ke current character ko 
        //include krte hue
        
        while(n1>0 && n2>0){
            if(str1[n1-1]==str2[n2-1]){
                ans.push_back(str2[n2-1]);
                n1-=1;
                n2-=1;
            }
            else{
                if(t[n1][n2-1]>t[n1-1][n2]){
                    ans.push_back(str2[n2-1]);
                    n2--;
                }
                else{
                    ans.push_back(str1[n1-1]);
                    n1--;
                }
            }
        }
        
        //agar koi bach gya to usse include krna hoga
        while(n2>0){
            ans.push_back(str2[n2-1]);
            n2--;
        }
        while(n1>0){
            ans.push_back(str1[n1-1]);
            n1--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};