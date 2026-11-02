#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize the first row (can only come from the left)
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        
        // Initialize the first column (can only come from above)
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        
        // Fill the rest of the grid using the minimum path from top or left
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[m - 1][n - 1];
    }
};