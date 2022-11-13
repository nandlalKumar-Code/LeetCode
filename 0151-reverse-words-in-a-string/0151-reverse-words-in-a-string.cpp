class Solution {
public:
    //TC--> O(N) && SC--->O(WORDS)
    string reverseWords(string s) {
        vector<string>v;
        int i=0;
        string str;
        
        while(i<s.size()){
            if(i==s.size()-1){
                if(s[i]!=' ') str.push_back(s[i]);
                if(str.size()){
                    v.emplace_back(str);
                }
                break;
            }
            else if(s[i]==' '){
                if(str.size()) v.emplace_back(str);
                i++;
                str.clear();
            }
            else{
                str.push_back(s[i]);
                i++;
            }
            
        }
        
        // for(auto x:v){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
       
        
        str.clear();
        str="";
        
        for(i=v.size()-1;i>=0;i--){
            str+=v[i];
            if(i==0){
                break;
            }
            str+=" ";
        }
        return str;
    }
    
};