class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> res;
            int sz = intervals.size();
            int i = 0;

            // adding all intervals that dont overlap with the newInterval
            for( ;i < sz && intervals[i][1] < newInterval[0] ; i++){
                res.push_back(intervals[i]);
            }
            // overlapping intervals with new Interval
            for(; i < sz && intervals[i][0] <= newInterval[1] ; i++){
                newInterval[0] = min(intervals[i][0] , newInterval[0]);
                newInterval[1] = max(intervals[i][1] , newInterval[1]);
            }
            res.push_back(newInterval);
            for(; i < sz ; i++){
                res.push_back(intervals[i]);
            }
            return res;


    }
};
