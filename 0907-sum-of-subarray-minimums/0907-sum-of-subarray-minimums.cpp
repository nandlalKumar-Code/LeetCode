class Solution {
private:
    vector<int>nsl(vector<int>&arr){
        int n=arr.size();
        vector<int>ans;
        ans.reserve(n);
        
        stack<int>st;
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1); 
            }
            else{
                ans.push_back(st.top());
            }
            
            st.push(i);
        }
        
        
        return ans;
        
    }
    vector<int>nsr(vector<int>&arr){
        int n=arr.size();
        vector<int>ans;
        ans.reserve(n);
        
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1); 
            }
            else{
                ans.push_back(st.top());
            }
            
            st.push(i);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    
    long long int modmul(int a,int b){
        long long int mod=1e9+7;
        return ((a%mod)*(b%mod))%mod;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>l=nsl(arr);
        vector<int>r=nsr(arr);
        
        
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            //ye dono bta rha hai ki kitna 
            //element iss waale index ke 
            //element se left me bda hai 
            //aur right me bda hai
            int leftfreq=(l[i]==-1?i:i-l[i]-1);
            int rightfreq=(r[i]==-1?n-i-1:r[i]-i-1);
            
            int temp=modmul(modmul(arr[i],leftfreq+1),rightfreq+1);
            ans=((ans%mod)+(temp%mod))%mod;
        }
        
        return ans;
    }
};