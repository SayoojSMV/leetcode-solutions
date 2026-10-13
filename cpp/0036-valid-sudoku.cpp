class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];

                if (current == '.') {
                    continue;
                }

                string rowKey = "r" + to_string(i) + "_" + current;
                string colKey = "c" + to_string(j) + "_" + current;
                string boxKey = "b" + to_string(i / 3) + "_" + to_string(j / 3) + current;

                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                    return false;
                }

                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }

        return true;
    }
};