class Solution {
private:
    int strIndex(int index,string path){
        
        while(index<path.size()){
            if(path[index]=='/'){
                return index;
            }
            index++;
        }
        return index;
    }
public:
    string simplifyPath(string path) {
        stack<string>st;
        
        int i,n=path.size();
        
        for(i=0;i<n;){
            
            if(path[i]=='/'){
                i++;
                continue;
            }
            
            int index=strIndex(i,path);
            string temp=path.substr(i,index-i);
            
            
            if((temp == "..") && (st.empty()==false)){
               st.pop();
                
            }
            else if((temp != ".") && (temp != "..")){
                st.push(temp);
            }
            i=index;
        }
        
        if(st.empty()) return "/";
        
        string result="";
        while(!st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }
        
        return result;
    }
};