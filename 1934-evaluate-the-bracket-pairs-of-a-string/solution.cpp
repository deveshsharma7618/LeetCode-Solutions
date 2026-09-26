#include <iostream>
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // creating unordered map for fast key access
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {

            // checking for key
            if(s[i] == '('){
                // skip first bracket
                i++;

                string key;

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // replace if available
                if(mp.find(key) != mp.end()){
                    ans += mp[key];
                }else{
                    ans += '?';
                }
                
            }else{
                ans.push_back(s[i]);
            }
        }

        return ans;

    }
};
