class Solution {
private:
    int help(int n,int x){
        while((n%x)==0){
            n/=x;
        }
        return n;
    }
public:
    bool isUgly(int n) {
        
        //ugly number can only be positive number
        if(n<=0){
            return false;
        }
        
        for(int x:{2,3,5}){
            n=help(n,x);
        }
        
        if(n==1) return true;
        else return false;
    }
};