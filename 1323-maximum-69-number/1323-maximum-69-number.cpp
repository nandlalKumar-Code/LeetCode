class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        for(auto &x:str){
            if(x=='6'){
                x='9';
                break;
            }
        }
        
        return stoi(str);
    }
};