class Solution {
public:
    vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void letterCombinationsHelper(string &digits, int i, int j, string &temp, vector<string> &ans){
        if(j >= digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit = digits[i] - '0'-2;
        string possible_chars = mapping[digit];
        for(int k=0; k < possible_chars.size(); k++){
            temp += possible_chars[k];
            letterCombinationsHelper(digits, i+1, j+1, temp, ans );
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        letterCombinationsHelper(digits, 0, 0, temp,ans);
        return ans;
    }
};
