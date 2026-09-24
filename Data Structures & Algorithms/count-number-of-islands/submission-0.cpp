class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); // row size
        int n = grid[0].size(); // column size
        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    continue;
                } else {
                    dfs(grid, i, j);
                    total++;
                }
            }
        }
        return total;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        //first set label to discovery ie flood
        grid[i][j] = '0';
        if (i-1 >= 0 && grid[i-1][j] == '1') {
            dfs(grid, i-1, j);
        }
        if (i+1 < grid.size() && grid[i+1][j] == '1') {
            dfs(grid, i+1, j);
        } 
        if (j-1 >=0 && grid[i][j-1] =='1') {
            dfs(grid, i, j-1);
        } 
        if (j+1 < grid[0].size() && grid[i][j+1] == '1') {
            dfs(grid, i, j+1);
        }
        return;
     }
};
