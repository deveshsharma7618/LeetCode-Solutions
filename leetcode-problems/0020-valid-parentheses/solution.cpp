class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                c.push(s[i]);
            }else{
                if(c.empty()){
                    return false;
                }
                char x = c.top();
                if(x == '(' && s[i] == ')'){
                    c.pop();
                }else if(x == '{' && s[i] == '}'){
                    c.pop();
                }else if(x == '[' && s[i] == ']'){
                    c.pop();
                }else{
                    return false;
                }
            }
        }
        if(c.empty()){
            return true;
        }else{
            return false;
        }
    }
};
