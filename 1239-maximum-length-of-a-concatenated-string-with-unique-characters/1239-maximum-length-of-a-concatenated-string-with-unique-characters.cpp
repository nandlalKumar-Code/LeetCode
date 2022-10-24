class Solution {
private:
    int recursive_approach1(vector<string>&arr,int index=0,string str=""){
        //base case
        if(index==arr.size()){
            //check wheather it contains duplicate values or not
            vector<int>v(26,0);
            for(auto x:str){
                v[x-'a']++;
                if(v[x-'a']==2){
                    return 0;
                }
            }
            
            return str.size();
        }
        
        //main code
        return max(
                    recursive_approach1(arr,index+1,str),
                    recursive_approach1(arr,index+1,str+arr[index])
        );
    }
    
    void recursive_approach2(vector<string>&arr,int &result,int index=0,string str=""){
        //base case
        if(index==arr.size()){
            
            if(result>str.size()){
                return;
            }
            
            //check wheather it contains duplicate values or not
            int v[26]={0};
            for(auto x:str){
                v[x-'a']++;
                if(v[x-'a']==2){
                    return;
                }
            }
            
            if(result<str.size()) result=str.size();
            
            return;
        }
        
        //main code
        recursive_approach2(arr,result,index+1,str+arr[index]);
        recursive_approach2(arr,result,index+1,str);
        
    }
    
public:
    //TC-->O(2^N) && SC--->O(N)
    //FOR BOTH RECURSIVE APPROACHES
    
    //TLE
    // int maxLength(vector<string>& arr) {
    //   return recursive_approach1(arr);
    // }
    
     //BUT ITS NOT GIVE TLE
     int maxLength(vector<string>& arr) {
        int result=0;
        recursive_approach2(arr,result);
        return result;
    }
};