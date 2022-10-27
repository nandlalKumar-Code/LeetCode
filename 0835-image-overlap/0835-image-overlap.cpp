class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int m=img1[0].size();
        
        vector<pair<int,int>>v1;
        vector<pair<int,int>>v2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1){
                    v1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    v2.push_back({i,j});
                }
            }
        }
        
        
        map<pair<int,int>,int>mp;
        int maxi=0;
        n=v1.size();
        m=v2.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=v1[i].first-v2[j].first;
                int y=v1[i].second-v2[j].second;
                mp[{x,y}]++;
                maxi=max(mp[{x,y}],maxi);
            }
        }
        
        return maxi;
    }
};