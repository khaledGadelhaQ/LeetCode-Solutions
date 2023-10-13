
class Solution {
public:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {-1, 1, 0, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            dfs(sr, sc, image, oldColor, newColor);
        }
        return image;
    }

    void dfs(int r, int c, vector<vector<int>>& image, int oldColor, int newColor) {
        if (!isValid(r, c, image) || image[r][c] != oldColor) return;
        image[r][c] = newColor;
        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], image, oldColor, newColor);
        }
    }

    bool isValid(int r, int c, vector<vector<int>>& image) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) {
            return false;
        }
        return true;
    }
};
