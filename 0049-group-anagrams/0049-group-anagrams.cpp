class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        
        for(auto x:strs){
            string str=x;
            sort(str.begin(),str.end());
            
            mp[str].push_back(x);
        }
        
        vector<vector<string>>ans;
        
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
    
//     //wrong 
//     //["bdddddddddd","bbbbbbbbbbc"] for this input
//      vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string,vector<string>>mp;
        
//         for(auto x:strs){
            
//             string str="";
            
//             vector<int>counter(26,0);
//             for(auto c:x){
//                 counter[c-'a']++;
//             }
            
//             for(int i=0;i<26;i++){
//                 str+= to_string(counter[i]);
//             }
            
//             cout<<"str="<<str<<endl;
            
//             mp[str].push_back(x);
//         }
        
//         vector<vector<string>>ans;
        
//         for(auto x:mp){
//             ans.push_back(x.second);
//         }
//         return ans;
//     }
    
    
};