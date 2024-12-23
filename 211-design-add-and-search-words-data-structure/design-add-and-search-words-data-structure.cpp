class TrieNode {
public:
  TrieNode *links[26];
  bool flag;
  TrieNode() {
        for(int i = 0; i<26;i++){
            links[i] = NULL;
            flag = false;
        }
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node = root ;
       for(int i = 0;i<word.size();i++) {
          if(node->links[word[i] - 'a'] == NULL){
             node->links[word[i] -'a'] = new TrieNode();
          }
          node = node->links[word[i]-'a'];
       }
       node->flag = true;
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;
        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode* child : cur->links) {
                    if (child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (cur->links[c - 'a'] == nullptr) {
                    return false;
                }
                cur = cur->links[c - 'a'];
            }
        }
        return cur->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */