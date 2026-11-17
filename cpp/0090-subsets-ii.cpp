#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(int start, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicate elements at the same tree depth
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            current.push_back(nums[i]);                  // Choose
            backtrack(i + 1, nums, current, result);      // Explore
            current.pop_back();                          // Un-choose (Backtrack)
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end()); // Sort to group duplicates together
        backtrack(0, nums, current, result);
        return result;
    }
};