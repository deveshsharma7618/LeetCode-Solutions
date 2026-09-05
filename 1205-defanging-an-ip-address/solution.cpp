class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(char x : address){
            if(x == '.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }else{
                ans.push_back(x);
            }
        }

        return ans;
    }
};
