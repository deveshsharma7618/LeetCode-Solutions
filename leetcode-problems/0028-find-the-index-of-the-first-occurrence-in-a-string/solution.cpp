class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        while( i < haystack.size()){
            int temp_i = i;
            int j = 0;
            while(j < needle.size() && temp_i < haystack.size() && haystack[temp_i] == needle[j]){
                temp_i++;
                j++;
            }

            if(temp_i - i == needle.size()){
                return i;
            }
            i++;

        }
        return -1;
    }

};
