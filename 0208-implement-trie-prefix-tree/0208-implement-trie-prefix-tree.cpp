class TrieNode{
public:
 TrieNode(): children(26,nullptr) , EndOfWord (false) {}
 vector<TrieNode*> children;
 bool EndOfWord { };

};
class Trie {
private:
  TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * cur = root ;
        for(auto c : word){
            int ch = c - 'a' ;
            if(!cur->children[ch]){
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->EndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode * cur = root ;
        for(auto c : word){
            
            int ch = c - 'a' ;
            if(!cur->children[ch]){
                return false;
            } 
            cur = cur->children[ch];          

        }
        return cur->EndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode * cur = root ;
        for(auto c : prefix){
            
            int ch = c - 'a' ;
            if(!cur->children[ch]){
                return false;
            } 
            cur = cur->children[ch];          
            
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