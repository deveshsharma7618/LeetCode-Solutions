class Solution {
public:
    int compress(vector<char>& chars) {
        string s;

        int freq = 1;
        char x = chars[0];

        int n = chars.size();

        for (int i = 1; i < n; i++) {
            if (chars[i] == x) {
                freq++;
            } else {
                s.push_back(x);
                if (freq != 1)
                    s += to_string(freq);

                x = chars[i];
                freq = 1;
            }
        }

        // Process last group
        s.push_back(x);
        if (freq != 1)
            s += to_string(freq);

        // Copy back
        for (int i = 0; i < s.size(); i++)
            chars[i] = s[i];

        return s.size();
    }
};
