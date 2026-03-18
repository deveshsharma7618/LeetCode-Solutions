class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int ans = 0;
        int pos = 0;

        while (n > 0) {
            int bit = n & 1;

            // Flip bit
            int flipped = bit ^ 1;

            // Place at correct position
            ans |= (flipped << pos);

            pos++;
            n >>= 1;
        }

        return ans;
    }
};
