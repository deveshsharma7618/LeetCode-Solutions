class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        int count = 0;

        for(int i=0;i<s.size();i++)
        {
            // Opening
            if(s[i]=='(')
                left++;
            // closing
            else
            {
                if(left == 0)
                count++;
                else
                left--;
            }
        }

        return count +left;
    }
};