class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int tmp {0};
  for(int i = 0  ; i < ransomNote.size() ; i++){

    for( int j = 0 ; j < magazine.size() ; j++){
      if(ransomNote[i] == magazine[j]){
       tmp++;
       magazine[j] = ' ';
       break;
      }
    }
  } 
  if(tmp == ransomNote.size()) 
     return true;
  return false;


 

    }
};