class TrieNode{
public:
 TrieNode(): EndOfWord(false){}
 unordered_map<int,TrieNode*> mp ;
 bool EndOfWord;

};
class WordDictionary {
private:
 TrieNode* root ;
public:
    WordDictionary() {
      root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto c : word){
          int ch = c - 'a' ;

          if(!cur->mp[ch]){
            cur->mp[ch] = new TrieNode();
          }
          cur = cur->mp[ch]; 
        }
        cur->EndOfWord = true;
    }

    bool search(string word){
      
      return search_(word,0,root);
    }
    
    bool search_(string word,int i , TrieNode* cur) {
      
      if(cur == nullptr)
        return false;
      if(i == word.size())
        return cur->EndOfWord;
      if(word[i] != '.')
        return search_(word,i+1,cur->mp[word[i]-'a']);
      for(auto val : cur->mp){
        if(search_(word,i+1, cur->mp[val.first]))
         return true;
      }
      return false;

    }
};

/*
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */