//Here s1 or s2 may be negative or positive 
//this is the general code to multiply two 
//strings 
//source-> https://practice.geeksforgeeks.org/batch/gts-1/track/gts-mathematics/problem/multiply-two-strings
class Solution{
  private:
    string multiply(string s,char ch,int freq){
        int carry=0,n=s.size();
        string ans="";
        while(freq--){
            ans.push_back('0');
        }
        
        for(int i=n-1;i>=0;i--){
            int temp=(s[i]-'0')*(ch-'0')+carry;
            carry=temp/10;
            
            ans.push_back((temp%10)+'0');
            
        }
        
        while(carry){
            ans.push_back((carry%10)+'0');
            carry/=10;
        }
        
        // cout<<"ans="<<ans<<endl;
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
    string addition(string s1,string s2){
        int n1=s1.size();
        int n2=s2.size();
        
        if(n2==0) return s1;
        if(n2>n1) return addition(s2,s1);
        
        int carry=0;
        
        string ans="";
        
        int i,j;
        
        for(i=n1-1,j=n2-1;i>=0;i--,j--){
            
            
            int temp=(s1[i]-'0')+((j>=0?(s2[j]-'0'):0))+carry;
            
            ans.push_back((temp%10)+'0');
            
            carry=temp/10;
        }
        
        while(carry){
            ans.push_back((carry%10)+'0');
            carry/=10;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int flage=0;
       
       if(s1[0]=='-'){
           flage=1-flage;
           s1=s1.substr(1);
       }
       if(s2[0]=='-'){
           flage=1-flage;
           s2=s2.substr(1);
       }
       
       int n1=s1.size();
       int n2=s2.size();
       string ans="";
       
       if(n2>n1){
           ans=multiplyStrings(s2,s1);
           
           if(flage && ans.front()!='0'){
               return ("-"+ans);
           }
           return ans;
       } 
       
       
       
       for(int i=n2-1;i>=0;i--){
           string temp=multiply(s1,s2[i],n2-i-1);
           ans=addition(temp,ans);
       }
       
       int i=0,n=ans.size();
       while((i<n) && (ans[i]=='0')){
           i++;
       }
       
       ans=ans.substr(i);
       
       return (ans.empty()?"0":(flage?("-"+ans):ans));
       
       
    }

};
