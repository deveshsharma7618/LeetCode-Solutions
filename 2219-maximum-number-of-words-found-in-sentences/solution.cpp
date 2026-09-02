class Solution {
public:

    int countWords(string &str){

        if(str == ""){
            return 0;
        }

        int words = 1;
        int n = str.size();

        for(int i = 0; i < n; i++){
            if(str[i] == ' '){
                words++;
            }
        }
        return words;
    }


    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        int n = sentences.size();
        for(int i = 0; i < n; i++){
            int wordCount = countWords(sentences[i]);
            ans = max(wordCount, ans);
        }
        return ans;
    }
};
