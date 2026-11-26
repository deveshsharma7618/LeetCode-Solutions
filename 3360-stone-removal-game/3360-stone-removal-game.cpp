class Solution {
public:
    bool canAliceWin(int n) {
        bool win = false;
        int i = 10;
        while( n > 0 ){
            if( n - i >= 0 ){
                n -= i;
                i--;
                win = !win;
            }else{
                break;
            }
        }

        return win;
    }
};