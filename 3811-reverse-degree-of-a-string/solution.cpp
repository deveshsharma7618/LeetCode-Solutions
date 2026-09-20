class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int degree = 0;
        for(int i = 0; i < n; i++){
            int reversedIdx = ('z' - s[i]) + 1;
            degree += reversedIdx * ( i + 1);
        }

        return degree;
    }
};
