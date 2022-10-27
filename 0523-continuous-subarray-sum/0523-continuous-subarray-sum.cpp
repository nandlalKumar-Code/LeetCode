class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixSum;
        unordered_map<int,int>mp;
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
        
        mp[0]=0;
        for(int i=0;i<n;i++){
            if(mp.count(prefixSum[i]%k)==0){
                mp[prefixSum[i]%k]=i+1;
            }
            else if(mp[prefixSum[i]%k]<i){
                return true;
            }
        }
        return false;
        
    }
};