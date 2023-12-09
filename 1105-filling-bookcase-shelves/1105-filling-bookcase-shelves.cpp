const int MAX = 1000 + 1;
int memo[MAX];

int best_split(int indx, int shelfWidth  ,vector<vector<int>>& books){
    if(indx == books.size() )
        return 0;
    auto &ref = memo[indx];
    if(ref != -1)
        return ref;
    ref = INT_MAX;
    int width_sum = 0 , mx_height = 0;
    for(int i = indx ; i < books.size(); i++){
        width_sum += books[i][0];
        mx_height  = max(mx_height, books[i][1]);
        if(width_sum > shelfWidth)
            break;
        ref = min(ref, mx_height + best_split(i +  1 , shelfWidth, books));
    }
    return ref;
}

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(memo, -1, sizeof(memo));
        return best_split(0, shelfWidth ,books);
    }
};