class Solution {
private:
    void recursive_approach(vector<int>&nums,vector<int>&ans,int index,int &count){
        
        if(index==0){
            
            if(ans.size()<3){
                return;
            }
            
            for(int i=1;i<ans.size();i++){
                if(ans[i]-ans[i-1]!=ans[1]-ans[0]){
                    return;
                }
            }
            count++;
            return;
        }
        
        recursive_approach(nums,ans,index-1,count);
        ans.push_back(nums[index-1]);
        recursive_approach(nums,ans,index-1,count);
        ans.pop_back();
        
        return;
    }
    
    int map_approach(vector<int>&nums){
        
        int ans=0,n=nums.size();
        vector<unordered_map<long,long>>t(n); //{diff,count}
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                
                long diff=(long)nums[i]-(long)nums[j];
                
                ans+=t[j][diff];
                
                t[i][diff]+=t[j][diff];
                
                t[i][diff]+=1;
            }
        }
        
        return ans;
        
        
    }
public:
    // int numberOfArithmeticSlices(vector<int>& nums) {
    //     int count=0;
    //     vector<int>ans;
    //     ans.reserve(nums.size());
    //     recursive_approach(nums,ans,nums.size(),count);
    //     return count;
    // }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        return map_approach(nums);
    }
};