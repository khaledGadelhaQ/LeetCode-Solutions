class TrieNode{
public:
 TrieNode(): EndOfWord (false) {}
 unordered_map<int,TrieNode*> children;
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

    string prefix_of_word(string word){
      TrieNode * cur = root ;

      for(int i = 0 ; i<(int)word.size() ; i++){
        int ch = word[i] - 'a';
        if(!cur->children[ch]){
            break;
        }
        if(cur->children[ch]->EndOfWord)
          return word.substr(0,i+1);
        cur = cur->children[ch];

      }
      return word;
    }


    

    

};
class Solution {
public:
Trie trie;

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto word : dictionary)
           trie.insert(word);
        istringstream iss(sentence);
        
        string res = "";
        string word;

        while(iss >> word ){
            res += trie.prefix_of_word(word);
            res+=" ";
        }
        res.pop_back();

        return res;
    }

};