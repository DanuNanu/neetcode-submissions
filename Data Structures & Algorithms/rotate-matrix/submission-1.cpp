class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }

        for (vector<int>& row: matrix) {
            std::reverse(row.begin(), row.end());
        }
        
    }
};
