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

class Trie {
    public :
        TrieNode *root;
        Trie() {
            root = new TrieNode();
        }

    void insert(string word) {
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
        TrieNode *node = root;
        for(int i = 0;i<word.size();i++){
            if(node->links[word[i] - 'a'] == NULL){
                return false;
            }
            node = node->links[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(int i = 0;i<prefix.size();i++){
            if(node->links[prefix[i] - 'a'] == NULL){
                return false;
            }
            node = node->links[prefix[i]-'a'];
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

