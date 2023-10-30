class Solution {
public:
/*
BFS Solution:
we start from 0000 as a string we change every ch in the string 2 steps
one forward and one backward this equal 8 edges for every node
we will use unordered_set to store visited values 
we will add the deadends first in the set 
we keep moving level by level until we reach our target string
else we return -1

the algorthims:
-> create an unordered_set and store all deadends in it 
-> create bfs
-> create a string equal 0000 as the root
-> we loop on the root 4 times
-> we change the current ch to next and prv
-> we check if it equal target or not
-> if it does we return the level integer as its the shortest
path to the target value
-> if it doesn't and not in the visited set we add it 
to both the queue and the set
*/  
    char next(char x){
        if (x == '9' ) return '0';
        return x + 1;
    }

    char prv(char x){
        if(x == '0') return '9' ;
        return x - 1;
    }
    
    int openLock(vector<string>& deadends, string target) {
        string root = "0000";
        queue<string> q;
        q.push(root);
        unordered_set<string> visited {deadends.begin(), deadends.end()};
        
        if(visited.count(root)) 
          return -1;
        if(root == target)
           return 0;

        for(int level = 0 , sz = 1 ; !q.empty() ; level++, sz = q.size()){

            while(sz--){
                string cur = q.front();
                q.pop();

                for(int i = 0 ; i < 4 ; i++){
                    cur[i] = next(cur[i]);
                    if(cur == target) return level + 1;

                    if(visited.insert(cur).second)
                      q.push(cur);
                    
                    cur[i] = prv(prv(cur[i]));
                    if(cur == target) return level + 1;
                    if(visited.insert(cur).second)
                      q.push(cur);
                    
                    cur[i] = next(cur[i]);
                    
                }
            }
        }
        return -1;
    }
};