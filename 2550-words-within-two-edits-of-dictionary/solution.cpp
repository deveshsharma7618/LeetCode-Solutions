class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size();
        int m = dictionary.size();
        for(int i=0;i<n;i++){
            bool has_add = false;
            
            for(int j=0;j<m;j++){
                if(dictionary[j].size() != queries[i].size()){
                    continue;
                }else{
                    int x = 0;
                    int y = dictionary[j].size();
                    int edits = 0;
                    for(int k = 0; k < y;k++){
                        if(dictionary[j][k] != queries[i][k]){
                            edits++;
                        }
                        if(edits >= 3){
                            break;
                        }
                    }

                    if(edits <= 2){
                        ans.push_back(queries[i]);
                        has_add = true;
                    }
                }
                if(has_add){
                    break;
                }
            }

            
        }

        return ans;
    }
};
