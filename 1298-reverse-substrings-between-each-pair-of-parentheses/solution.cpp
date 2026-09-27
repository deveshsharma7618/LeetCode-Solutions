#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<int> st;
        std::string result = "";
        
        for (char c : s) {
            if (c == '(') {
                st.push(result.length());
            } else if (c == ')') {
                int start = st.top();
                st.pop();
                std::reverse(result.begin() + start, result.end());
            } else {
                result += c;
            }
        }
        
        return result;
    }
};

