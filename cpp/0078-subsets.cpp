#include <vector>

class Solution {
private:
    void backtrack(int start, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Every state represents a valid subset, so we push current to result
        result.push_back(current);
        
        // Iterate through remaining elements and build subsets
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);                  // Choose
            backtrack(i + 1, nums, current, result);      // Explore
            current.pop_back();                          // Un-choose (Backtrack)
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};