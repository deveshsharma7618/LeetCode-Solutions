class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26];
        int m = ransomNote.size();
        int n = magazine.size();
        for(int i=0;i<m;i++){
            freq[ransomNote[i]-'a']++;
        }
        
        for(int i = 0; i < n; i++){
            freq[magazine[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                return false;
            }
        }
        return true;
        
    }
};
