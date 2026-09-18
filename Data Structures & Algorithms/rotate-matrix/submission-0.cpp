class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int v_temp = n;
        int k = 0;
        while (v_temp >= k){
            vector<int> temp_row = matrix[k];
            matrix[k] = matrix[v_temp];
            matrix[v_temp] = temp_row;
            v_temp--;
            k++;
        }

        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
    }
};
