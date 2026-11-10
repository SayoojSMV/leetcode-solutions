#include <vector>
#include <string>

class Solution {
private:
    bool dfs(int i, int j, int index, vector<vector<char>>& board, string& word) {
        // Base case: all characters have been matched successfully
        if (index == word.length()) {
            return true;
        }
        
        // Check boundaries and character match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark the current cell as visited by temporarily changing its value
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore all 4 possible directions (up, down, left, right)
        bool found = dfs(i + 1, j, index + 1, board, word) ||
                     dfs(i - 1, j, index + 1, board, word) ||
                     dfs(i, j + 1, index + 1, board, word) ||
                     dfs(i, j - 1, index + 1, board, word);
        
        // Backtrack: restore the cell's original character
        board[i][j] = temp;
        
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};