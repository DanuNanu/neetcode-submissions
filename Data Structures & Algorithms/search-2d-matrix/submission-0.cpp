class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size()-1;
        int m = matrix.size()-1;
        //first do binary search across the first column, varying the roww
        int row_left = 0;
        int row_right = m;
        while (row_left <= row_right) {
            int row_mid = row_left + (row_right-row_left)/2;
            //first check if matrix[mid][0] is target
            if (matrix[row_mid][0] == target) {
                return true;
            }
            //otherwise check if mid[0] < target, if thats the case
            if (matrix[row_mid][0] < target) {
                // then you do <,>, = checks with last element in row
                //1. = check
                if (matrix[row_mid][n] == target) {
                    //you got it
                    return true;
                }else if (matrix[row_mid][n] > target) {
                     //2. target < check
                     // now do binary search on row if 
                     //didnt find then return false
                     vector<int>& row_vec = matrix[row_mid];
                     int col_left = 0;
                     int col_right = n;
                     //if you dont find here then it does not exist
                     return binary_search(row_vec, col_left, col_right, target);
                     //case for when last elemen in row >, then binary search row again
                } else {
                    row_left = row_mid +1;
                    continue;
                }
                // this is the case where the matrix[row_mid][0] > target, so 
                // in this case move the right row boundary to row_mid-1

                }else {
                    row_right = row_mid-1;
                    continue;
                }


            }
            return false;
        }
        
    
    bool binary_search(vector<int>& matrix, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (matrix[mid] == target) {
                return true;
            }
            if (matrix[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return false;
    }
};
