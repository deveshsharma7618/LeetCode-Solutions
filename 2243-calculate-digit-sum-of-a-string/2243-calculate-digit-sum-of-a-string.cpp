class Solution {
public:
    string digitSum(string s, int k) {
        if( s.size() <= k){
            return s;
        }

        string ans;
        for (int i = 0; i < s.size(); i += k) {
            string temp = s.substr(i, k);
            int sum = 0;
            for (int j = 0; j < temp.size(); j++) {
                sum += temp[j] - '0';
            }

            ans += std::to_string(sum);
        }

        return digitSum(ans, k);
    }
};