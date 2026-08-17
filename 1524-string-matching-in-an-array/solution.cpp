class Solution {
public:
    
    bool substring(string &str, string &substr){
        if(str.size() < substr.size()){
            return false;
        }else{
            for(int i=0; i <= str.size()-substr.size();i++){
                string temp = str.substr(i, substr.size());
                if(temp == substr){
                    return true;
                }
            }
            
            return false;
        }
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        set<string> temp;
        vector<string> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }else{
                    if(substring(words[i], words[j])){
                        temp.insert(words[j]);
                    }
                }
            }
        }
        
        for(auto x : temp){
            ans.push_back(x);
        }
        
        return ans;
        
    }
};
