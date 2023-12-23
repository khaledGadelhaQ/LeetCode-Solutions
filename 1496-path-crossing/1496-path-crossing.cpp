class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int x = 0, y = 0;
        st.insert({x,y});
        for (auto &ch : path) {
            if (ch == 'N')
                y++;
            else if (ch == 'S')
                y--;
            else if (ch == 'E')
                x++;
            else
                x--;
            
            if(st.find({x,y}) != st.end()) return true;
            st.insert({x,y});
        }
        return false;
    }
};
