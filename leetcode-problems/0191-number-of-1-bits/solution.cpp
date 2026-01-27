class Solution {
public:
    int hammingWeight(int n) {
        int x = sizeof(int) * 8;
        int count = 0;
        for(int i = 0; i < x; i++){
            int bit = n & 1;
            if(bit)
                count++;
            n >>= 1;
        }
        return count;
    }
};
