class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& arr) {
        map<int, int> map;
        int sz = arr.size();
        for (int i = 0; i < sz; i++) {
            map[arr[i][0]] = i;
        }
        sort(arr.begin(), arr.end());
        vector<int> res ( sz, -1);
        
        for (int i = 0; i < sz; i++) {
            auto it = map.lower_bound(arr[i][1]);
            int origIdx = map[arr[i][0]];
            if (it != map.end()) {
                res[origIdx] = it->second;
            }
        }
        return res;
    }

};