class Solution {
private:
    //using divide and conquer approach--> O(nlogn)
    int help(vector<int>&v,int l,int h){
        
        if(l==h){
            return v[l];
        }
        
        int m,lss,rss,sum1=INT_MIN,sum2=INT_MIN,runningSum=0;
        
        
        m=l+((h-l)>>1);
        lss=help(v,l,m);
        rss=help(v,m+1,h);
        
        runningSum=0;
        for(int i=m;i>=l;i--){
            runningSum+=v[i];
            if(runningSum>sum1){
                sum1=runningSum;
            }
        }
        
        runningSum=0;
        for(int i=m+1;i<=h;i++){
            runningSum+=v[i];
            if(runningSum>sum2){
                sum2=runningSum;
            }
        }
        
        
        
        return max(lss,max(rss,sum1+sum2));
        
    }
    
    
public:
    int maxSubArray(vector<int>&v){
        return help(v,0,v.size()-1);
    }
    
//     //modified kadens algorithm--->O(n)
//     int maxSubArray(vector<int>& v) {
//       int max_so_far=INT_MIN,max_ending_here=0;

//       for(int i=0;i<v.size();i++){
//         if(v[i]<=max_ending_here+v[i]){
//             max_ending_here+=v[i];
//         }
//         else{
//             max_ending_here=v[i];
//         }

//         if(max_ending_here>max_so_far){
//             max_so_far=max_ending_here;
//         }

//       }

//       return max_so_far;
//     }
};