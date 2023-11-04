class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row*col -1;
        while(right >= left){
            int mid = left  + (right - left)/2;
            if(matrix[mid / col ][ mid % col ] == target)
              return true;
            else if(matrix[mid / col ][ mid % col ] < target)
             left = mid + 1;
            else 
              right = mid - 1;
        }
        return false;
    }
};
/*
as the matrix is sorted from left to right and up to bottom we
can consider it as a one sorted array, left = 0 , right =row*col -1
row = mid / col
col = mid % col
*/
