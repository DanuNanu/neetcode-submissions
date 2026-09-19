class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool right = true;
        bool left = false;
        bool down = false;
        bool up = false;
        int m = matrix.size();
        int n = matrix[0].size();
        int horz_mov = n;
        int vert_mov = m-1;
        int curr_x =0;
        int curr_y =0;
        vector<int> result;
        while (result.size() < (size_t)(m*n)) {
            if (right) {
                int mov = 0;
                while(mov < horz_mov) {
                    result.push_back(matrix[curr_x][curr_y]);
                    curr_y++;
                    mov++;
                }
                curr_y--;
                curr_x++;
                right = false;
                down = true;
                horz_mov--;
            } else if (left) {
                int mov = 0;
                while (mov < horz_mov) {
                    result.push_back(matrix[curr_x][curr_y]);
                    curr_y--;
                    mov++;
                }
                curr_y++;
                curr_x--;
                left = false;
                up = true;
                horz_mov--;
            } else if (up) {
                int mov = 0;
                while (mov < vert_mov) {
                    result.push_back(matrix[curr_x][curr_y]);
                    curr_x--;
                    mov++;
                }
                curr_x++;
                curr_y++;
                up = false;
                right = true;
                vert_mov--;
            } else {
                int mov = 0;
                while (mov < vert_mov) {
                    result.push_back(matrix[curr_x][curr_y]);
                    curr_x++;
                    mov++;
                }
                curr_x--;
                curr_y--;
                down = false;
                left = true;
                vert_mov--;
            }
         }
         return result;
        
    }
};