class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>t(n,0);
        
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                t[i]=t[i-1]+1;
                ans+=t[i];
            }
        }
        
        return ans;
    }
};