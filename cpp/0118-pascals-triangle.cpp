using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> currentRow(i + 1, 1);

            for (int j = 1; j < i; j++) {
                currentRow[j] = triangle[i - 1][j -1] + triangle[i - 1][j];
            }
            
            triangle.push_back(currentRow);
        }

        return triangle;
    }
};