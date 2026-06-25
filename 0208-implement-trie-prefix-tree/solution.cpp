class Trie {
    Trie *children[26];
    int isLeaf = false;
public:
    Trie() {
        for(int i=0;i<26;i++){
            children[i] = NULL;
            isLeaf = false;
        }
    }
    
    void insert(string word) {
        Trie *temp = this;
        for(char c : word){
            if(temp->children[c-'a'] == NULL){
                temp->children[c-'a'] = new Trie();
            }
            temp = temp->children[c-'a'];
        }
        
        temp->isLeaf = true;
        
    }
    
    bool search(string word) {
        Trie *temp = this;
        for( char c : word){
            if(temp->children[c-'a'] == NULL){
                return false;
            }
            temp = temp->children[c-'a'];
        }
        
        return temp->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie *temp = this;
        for( char c : prefix){
            if(temp->children[c-'a'] == NULL){
                return false;
            }
            temp = temp->children[c-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
