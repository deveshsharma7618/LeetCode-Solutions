#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int solve(int i, int j, const vector<int>& temp) {
        // Base case: empty inner content for "()", returning 1
        if( i > j ){
            return 0;
        }else if ( j - i == 1) {
            return 1;
        }

        int matchIdx = temp[i];

        if (matchIdx == j) {
            return 2 * solve(i + 1, j - 1, temp);
        }

        return solve(i, matchIdx, temp) + solve(matchIdx + 1, j, temp);
    }

    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> temp(n, -1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                temp[st.top()] = i;
                st.pop();
            }
        }

        return solve(0, n - 1, temp);
    }
};