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
    vector<string> split(string sentence){
        vector<string> tmp;

       string word;
       istringstream iss(sentence);
       while(iss >> word){
           tmp.push_back(word);
       }
       return tmp;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto word : dictionary)
           trie.insert(word);
        vector<string> words = split(sentence);
        string res = "";
        for(int i = 0 ; i<(int)words.size() ; i++){
            if(i)
              res+= " ";
            res += trie.prefix_of_word(words[i]);
        }
        return res;
    }

};